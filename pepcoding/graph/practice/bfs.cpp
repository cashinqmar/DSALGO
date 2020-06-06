#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<vector<int>> graph(n);
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int v=q.front();
            cout<<v<<" ";
            q.pop();
            for(int i=0;i<graph[v].size();i++){
                if(!visited[graph[v][i]]){
                  q.push(graph[v][i]);
                  visited[graph[v][i]]=true;
                }
            }
        }
        cout<<"\n";
    }
}