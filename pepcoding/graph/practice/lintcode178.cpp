#include<bits/stdc++.h>
using namespace std;

bool cycle =false;

void dfs(vector<vector<int>> &graph,int src,vector<int>& visited){
    if(visited[src]==2)return;
     visited[src]=1;
    for(auto i:graph[src]){
        if(visited[i]==-1)dfs(graph,i,visited);
        else if(visited[i]==1){
            cycle=true;
            return;
        }
    }
    visited[src]=2;
}
bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,-1);

        for(int i=0;i<n;i++){
            if(!cycle)dfs(graph,i,visited);
        }
return cycle;
}


int main(){

    }