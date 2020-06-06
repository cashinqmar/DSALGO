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
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }

        vector<int> visited(n,-1);
        stack<int> st1,st2;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(graph,i,visited,st1);
            }
        }

        for(int i=0;i<n;i++){
            visited[i]=-1;
        }

        dfs(graph,st1.top(),visited,st2);
        if(st1.size()==st2.size()&&(st1.size()>0)){
            cout<<st1.top()<<"\n";
        }
        else cout<<"-1"<<"\n";

    }
    
}