#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int parent,int vis[],vector<int> adj[]){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            if(dfs(it,src,vis,adj)==true){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e){
    if(v==1 && e==0) return false; 
    vector<int> adj[v]; //adj list
	for(auto it: edges){
		int U = it[0];
		int V = it[1];
		adj[U].push_back(V); 
		adj[V].push_back(U);
	}
    int vis[v]={0}; 
    for(int i=0;i<v;i++){ 
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{3,4},{4,0}};
    int V = 5;
    int E = 5;
    if(isCyclic(edges,V,E)) cout<<"True";
    else cout<<"False";
    return 0; 
}