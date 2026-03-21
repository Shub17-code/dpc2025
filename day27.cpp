#include<bits/stdc++.h>
using namespace std;

int ShortestPath(vector<vector<int>>& edges, int v, int start,int end){
    if(start==end) return 0; 
    vector<int> adj[v]; 
	for(auto it: edges){
		int U = it[0];
		int V = it[1];
		adj[U].push_back(V); 
		adj[V].push_back(U);
	}
    vector<int> dis(v,1e9); 
    dis[start] = 0; 
    queue<int> q; 
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dis[it]>dis[node]+1){ 
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<v;i++){
        if(dis[i]==1e9){ 
            dis[i]=-1;
        }
    }
    return dis[end];
}
int main(){
    vector<vector<int>> edges={{0,1},{1,2}};
    int V = 4;
    int start=2;
    int end=2;
    cout<<ShortestPath(edges,V,start,end);
    return 0; 
}