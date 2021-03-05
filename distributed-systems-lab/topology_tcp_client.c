#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 8080
#define ARR_SIZE 1000
#define INF 1000000005

int min(int a, int b){
	return (a<=b ? a : b);
}

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
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("error in creating socket\n");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
		perror("invalid address. address not supported\n");
		exit(EXIT_FAILURE);
	}
	if(connect(sock, (struct sockaddr *)&serv_addr, (socklen_t)sizeof(serv_addr))<0){
		perror("connection failed\n");
		exit(EXIT_FAILURE);
	}
	char choice;
	int valread, node_cnt;
	printf("Choose topology(tree(t)/ring(r)/star(s)/hybrid(h): ");
	scanf("%c", &choice);
	send(sock, &choice, sizeof(choice), 0);
	printf("Enter the number of node: ");
	scanf("%d", &node_cnt);
	send(sock, &node_cnt, sizeof(node_cnt), 0);
	struct Topology topo;
	valread = read(sock, &topo, sizeof(topo));
	printf("------------- Adjacency Matrix -----------\n");
	for(int i=0; i<node_cnt; i++){
		printf("Node %d: ", i+1);
		for(int j=0; j<node_cnt; j++){
			if(topo.adj_mat[i][j]) printf("%d ", j+1);
		}
		printf("\n");
	}
	printf("------------ Degree of Nodes -------------\n");
	for(int i=0; i<node_cnt; i++){
		printf("Degree of node %d: %d\n", i+1, topo.degree[i]);
	}
	for(int i=0; i<node_cnt; i++){
		for(int j=0; j<node_cnt; j++){
			if(!topo.adj_mat[i][j]) topo.adj_mat[i][j] = INF;
			if(i==j) topo.adj_mat[i][j] = 0;
		}
	}
	for(int k=0; k<node_cnt; k++){
		for(int i=0; i<node_cnt; i++){
			for(int j=0; j<node_cnt; j++){
				topo.adj_mat[i][j] = min(topo.adj_mat[i][j], topo.adj_mat[i][k] + topo.adj_mat[k][j]);
			}
		}
	}
	printf("------------- Shortest Path --------------\n");
	printf("  ");
	for(int i=0; i<node_cnt; i++) printf("%d ", i);
	printf("\n");
	printf("----------------------------------------------\n");
	for(int i=0; i<node_cnt; i++){
		printf("%d|", i);
		for(int j=0; j<node_cnt; j++){
			if(topo.adj_mat[i][j]<INF) printf("%d ", topo.adj_mat[i][j]);
			else printf("%c ", 'X');
		}
		printf("\n");
	}
	return 0;
}
