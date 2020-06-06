#include<bits/stdc++.h>
using namespace std;


int main(){
    long int n;
    long int e;
    cin>>n>>e;
    vector<vector<pair<long int,long int>>> graph(n+1);
    for(int i=0;i<e;i++){
        long int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    
    long long int ans=0;
    auto comp=[](pair<long int,long int> &a,pair<long int,long int> &b){
        return a.second>b.second;
    };
    priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,decltype(comp)> pq(comp);
    
    vector<bool> visited(n+1,false);
        pq.push({1,0});//bhot zaroori kaam

    while(pq.size()!=0){ 
        pair<int,int> t=pq.top();pq.pop();
        int v=t.first;
        int w=t.second;

        if(visited[v])continue;
        visited[v]=true;
        ans+=w;
        for(int i=0;i<graph[v].size();i++){
            if(!visited[graph[v][i].first]){
              pq.push(graph[v][i]);
            }
        }
    }
    cout<<ans<<"\n";
}