#include <bits/stdc++.h>
using namespace std;

char choice;
int node_cnt;

int main(){
	printf("Enter the type of type of topology[Star(s), Ring(r), Tree(t)]: ");
	scanf("%c", &choice);
	printf("Enter the number of nodes in the network: ");
	scanf("%d", &node_cnt);
	switch(choice){
		case 's':
			printf("Adjacency List:\n");
			printf("1: ");
			for(int i=2; i<=node_cnt; i++) printf("%d ", i);
			printf("\n");
			for(int i=2; i<=node_cnt; i++){
				printf("%d: 1\n", i);
			}
			printf("Adjacency Matrix:\n");
			for(int i=1; i<=node_cnt; i++){
				if(i==1) printf("%d ", 0);
				else printf("%d ", 1);
			}
			printf("\n");
			for(int i=2; i<=node_cnt; i++){
				for(int j=1; j<=node_cnt; j++){
					if(i==1 || j==1) printf("1 ");
					else printf("0 ");
				}
				printf("\n");
			}
			printf("Degree of nodes:\n");
			for(int i=1; i<=node_cnt; i++){
				if(i==1) printf("1: %d\n", node_cnt-1);
				else printf("%d: 1\n", i);
			}
			break;
		case 'r':
			printf("Adjacency List:\n");
			for(int i=1; i<=node_cnt; i++){
				printf("%d: %d\n", i, i%node_cnt+1);
			}
			printf("Adjacency Matrix:\n");
			for(int i=1; i<=node_cnt; i++){
				for(int j=1; j<=node_cnt; j++){
					if(j==(i%node_cnt+1)) printf("1 ");
					else printf("0 ");
				}
				printf("\n");
			}
			printf("Degree of nodes:\n");
			for(int i=1; i<=node_cnt; i++) printf("%d: 1\n", i);
			break;
		case 't':
			printf("Adjacency List:\n");
			for(int i=1; i<=node_cnt/2; i++){
				if(2*i+1<=node_cnt) printf("%d: %d %d", i, 2*i, 2*i+1);
				else if(2*i<=node_cnt) printf("%d: %d", i, 2*i);
				if(i>1) printf(" %d\n", i/2);
				else printf("\n");
			}
			for(int i=node_cnt/2+1; i<=node_cnt; i++) printf("%d: %d\n", i, i/2);
			printf("Adjacency Matrix\n");
			int degree[node_cnt+1];
			fill_n(degree, node_cnt+1, 0);
			for(int i=1; i<=node_cnt; i++){
				for(int j=1; j<=node_cnt; j++){
					if(2*i==j || 2*i+1==j){
						printf("1 ");
						degree[i]++;
					}else if(i!=1 && i!=j && i/2==j){
						printf("1 ");
						degree[i]++;
					}else printf("0 ");
				}
				printf("\n");
			}
			printf("Degree of nodes:\n");
			for(int i=1; i<=node_cnt; i++) printf("%d: %d\n", i, degree[i]);
			break;
	}
	return 0;
}
