#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000005

int nodes;
int adj_mat[1000][1000];
int dist[1000];

int rand(int a, int b){
	return a+rand()%b;
}


void djikstra(int src){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i=0; i<nodes; i++) dist[i] = MAX;
	dist[src] = 0;
	bool done[nodes];
	fill_n(done, nodes, false);
	pq.push({0, src});
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		if(!done[p.second]){
			for(int i=0; i<nodes; i++){
				if(adj_mat[p.second][i]!=MAX && !done[i]){
					dist[i] = min(dist[i], dist[p.second]+adj_mat[p.second][i]);
					pq.push({dist[i], i});
				}
			}
		}
		done[p.second] = true;
	}
}

int main(){
	cout<<"Number of Nodes(>=6): ";	
	cin>>nodes;
	if(nodes<6){
		cout<<"Number of nodes must be greater than or equal to 6\n";
		return 0;
	}
	for(int i=0; i<nodes; i++){
		for(int j=0; j<nodes; j++){
			adj_mat[i][j] = MAX;
		}
	}
	for(int i=0; i<4; i++){
		int left = 2*i+1; 
		int right = 2*i+2;
		if(left<4){
			adj_mat[i][left] = adj_mat[left][i] = rand(1, 1000);
		}
		if(right<4){
			adj_mat[i][right] = adj_mat[right][i] = rand(1, 1000);
		}
	}
	adj_mat[0][4] = adj_mat[4][0] = rand(1, 1000);
	adj_mat[5][4] = adj_mat[4][5] = rand(1, 1000);
	adj_mat[5][0] = adj_mat[0][5] = rand(1, 1000);
	for(int i=6; i<nodes; i++){
		adj_mat[5][i] = adj_mat[i][5] = rand(1, 1000);
	}
	for(int i=0; i<nodes; i++) adj_mat[i][i] = 0;
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
			if(adj_mat[i][j]!=MAX){
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
	cout<<"Source for djikstra's: ";
	int src;
	cin>>src;
	src--;
	djikstra(src);
	cout<<"Distance from "<<src+1<<":\n";
	for(int i=0; i<nodes; i++){
		cout<<"Node "<<i+1<<": "<<dist[i]<<"\n";
	}
    return 0;
}

