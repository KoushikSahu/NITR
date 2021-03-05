#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080
#define ARR_SIZE 1000

struct Topology{
	int node_cnt;
	int degree[ARR_SIZE], adj_mat[ARR_SIZE][ARR_SIZE];
};

struct Topology new_topology(int node_cnt){
	struct Topology topo;
	topo.node_cnt = node_cnt;
	for(int i=0; i<node_cnt; i++){
		for(int j=0; j<node_cnt; j++){
			topo.adj_mat[i][j] = 0;
		}
	}
	return topo;
}

int main(){
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == 0){
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	int opt = 1; // int value used as option value to allow reuse of address and port
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
		perror("error in setting socket option");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	int addr_len = (int)sizeof(addr_len);
	if(bind(server_fd, (struct sockaddr *)&address, (socklen_t)sizeof(address))<0){
		perror("error in binding");
		exit(EXIT_FAILURE);
	}
	if(listen(server_fd, 5)<0){
		perror("error while listening");
		exit(EXIT_FAILURE);
	}
	int new_socket;
	if((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addr_len)) < 0){
		perror("failed to accept connection request");
		exit(EXIT_FAILURE);
	}
	int valread;
	char choice; 
	int node_cnt;
	valread = read(new_socket, &choice, sizeof(char));
	valread = read(new_socket, &node_cnt, sizeof(int));
	struct Topology topo = new_topology(node_cnt);
	topo.node_cnt = node_cnt;
	if(choice=='r'){
		for(int i=0; i<node_cnt; i++){
			topo.adj_mat[i][(i+1)%node_cnt] = topo.adj_mat[(i+1)%node_cnt][i] = 1;
		}
		
	}else if(choice=='s'){
		int common_node = 0;
		for(int i=1; i<node_cnt; i++){
			topo.adj_mat[i][common_node] = topo.adj_mat[common_node][i] = 1;
		}
	}else if(choice=='t'){
		for(int i=0; i<node_cnt; i++){
			int par = (i-1)/2, left = 2*i+1, right = 2*i+2;
			if(i!=par) topo.adj_mat[i][par] = topo.adj_mat[par][i] = 1;
			if(left<node_cnt) topo.adj_mat[i][left] = topo.adj_mat[left][i] = 1;
			if(right<node_cnt) topo.adj_mat[i][right] = topo.adj_mat[right][i] = 1;
		}
	}else if(choice=='h'){
		int ring, star, tree;
		ring = star = node_cnt/3;
		tree = node_cnt - (ring + star);
		if(tree<4 || ring<3 || star<4){
			perror("Not enough nodes to form hybrid topology\n");
			exit(0);
		}else{
			int root = 0;
			int ring_start = 3;
			int ring_end = 5;
			int common = 6;
			for(int i=0; i<ring_start; i++){
				int par = (i-1)/2, left = 2*i+1, right = 2*i+2;
				if(i!=par) topo.adj_mat[i][par] = topo.adj_mat[par][i] = 1;
				if(left<ring_start) topo.adj_mat[i][left] = topo.adj_mat[left][i] = 1;
				if(right<ring_start) topo.adj_mat[i][right] = topo.adj_mat[right][i] = 1;
			}
			for(int i=ring_start; i<=ring_end; i++){
				if(i!=ring_end) topo.adj_mat[i][i+1] = topo.adj_mat[i+1][i] = 1;
				else topo.adj_mat[i][ring_start] = topo.adj_mat[ring_start][i] = 1;
			}
			for(int i=common+1; i<node_cnt; i++){
				topo.adj_mat[i][common] = topo.adj_mat[common][i] = 1;
			}
			topo.adj_mat[root][ring_start] = topo.adj_mat[ring_start][root] = 1;
			topo.adj_mat[ring_start][common] = topo.adj_mat[common][ring_start] = 1;
		}
	}
	for(int i=0; i<node_cnt; i++){
		int edge_cnt = 0;
		for(int j=0; j<node_cnt; j++) edge_cnt += topo.adj_mat[i][j];
		topo.degree[i] = edge_cnt;
	}
	send(new_socket, &topo, sizeof(topo), 0);
	return 0;
}
