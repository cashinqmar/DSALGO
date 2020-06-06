#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> graph,int src,vector<int> &visited,stack<int> &st){
    visited[src]=1;
    for(auto i:graph[src])if(visited[i]==-1)dfs(graph,i,visited,st);
    st.push(src);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> graph(n);
        vector<vector<int>> graph2(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph2[y].push_back(x);
        }

        vector<int> visited(n,-1);
        stack<int> st1;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(graph,i,visited,st1);
            }
        }

        for(int i=0;i<n;i++){
            visited[i]=-1;
        }
        stack<int> st2;
        int count=0;
        while(st1.size()!=0){
            if(visited[st1.top()]==-1){
                dfs(graph2,st1.top(),visited,st2);
              count++;
            } st1.pop();
        }
       cout<<count<<"\n";
    }
    
}