#include <bits/stdc++.h>
using namespace std;

char choice;

int main(){
	cout<<"Enter the topology[c(hypercube)/h(hybrid)]: ";
	cin>>choice;
	switch(choice){
		case 'c':
			{
				int dim;
				cout<<"Enter number of dimensions: ";
				cin>>dim;
				int nodes = pow(2, dim+1);
				int adj_mat[nodes][nodes];
				fill_n(adj_mat[0], nodes*nodes, 0);
				for(int i=0; i<4; i++){
					adj_mat[i][(i+1)%4] = 1;
					adj_mat[(i+1)%4][i] = 1;
				}
				for(int d=2; d<=dim; d++){
					for(int i=0; i<pow(2, d); i++){
						for(int j=0; j<pow(2, d); j++){
							adj_mat[(1<<(d))|i][(1<<(d))|j] = adj_mat[i][j];
						}
					}
					for(int i=0; i<pow(2, d); i++){
						adj_mat[i][(1<<(d))|i] = adj_mat[(1<<(d))|i][i] = 1;
					}
				}
				cout<<"Pictorial representation of the topology:\n";
				for(int i=0; i<nodes; i++){
					for(int j=0; j<nodes; j++){
						if(adj_mat[i][j]==1) cout<<".";
						else cout<<" ";
					}
					cout<<"\n";
				}
				cout<<"Adjacency Matrix:\n";
				for(int i=0; i<nodes; i++){
					for(int j=0; j<nodes; j++){
						cout<<adj_mat[i][j]<<" ";
					}
					cout<<"\n";
				}
				cout<<"Adjancency List:\n";
				int degree[nodes];
				fill_n(degree, nodes, 0);
				for(int i=0; i<nodes; i++){
					cout<<"Node "<<i+1<<": ";
					for(int j=0; j<nodes; j++){
						if(adj_mat[i][j]){
							cout<<j+1<<" ";
							degree[i]++;
						}
					}
					cout<<"\n";
				}
				cout<<"Degree of nodes:\n";
				for(int i=0; i<nodes; i++){
					cout<<"Node "<<i+1<<" = "<<degree[i]<<"\n";
				}
				break;
			}
		case 'h':
			{
				int nodes;
				cout<<"Number of Nodes(>=6): ";	
				cin>>nodes;
				if(nodes<6){
					cout<<"Number of nodes must be greater than or equal to 6\n";
					return 0;
				}
				int adj_mat[nodes][nodes];
				fill_n(adj_mat[0], nodes*nodes, 0);
				for(int i=0; i<4; i++){
					int left = 2*i+1; 
					int right = 2*i+2;
					if(left<4){
						adj_mat[i][left] = 1;
						adj_mat[left][i] = 1;
					}
					if(right<4){
						adj_mat[i][right] = 1;
						adj_mat[right][i] = 1;
					}
				}
				adj_mat[0][4] = 1;
				adj_mat[4][0] = 1;
				adj_mat[5][4] = 1;
				adj_mat[4][5] = 1;
				adj_mat[5][0] = 1;
				adj_mat[0][5] = 1;
				for(int i=6; i<nodes; i++){
					adj_mat[5][i] = adj_mat[i][5] = 1;
				}
				cout<<"Adjacency Matrix:\n";
				for(int i=0; i<nodes; i++){
					for(int j=0; j<nodes; j++){
						cout<<adj_mat[i][j]<<" ";
					}
					cout<<"\n";
				}
				cout<<"Adjancency List:\n";
				int degree[nodes];
				fill_n(degree, nodes, 0);
				for(int i=0; i<nodes; i++){
					cout<<"Node "<<i+1<<": ";
					for(int j=0; j<nodes; j++){
						if(adj_mat[i][j]){
							cout<<j+1<<" ";
							degree[i]++;
						}
					}
					cout<<"\n";
				}
				cout<<"Degree of nodes:\n";
				for(int i=0; i<nodes; i++){
					cout<<"Node "<<i+1<<" = "<<degree[i]<<"\n";
				}
				break;
			}
	}
    return 0;
}

