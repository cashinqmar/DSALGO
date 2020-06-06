#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<pair<long int,long int>>> graph(100005);
    vector<bool> visited(100005);
    vector<int> ans(100005,0);
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
    }
   auto comp=[](pair<long int,long int> &a,pair<long int,long int>&b){
       return a.second>b.second;
   };

    priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,decltype(comp)> pq(comp);
    
    pq.push({1,0});
    while(!pq.empty()){
        pair<long int,long int> t=pq.top();
        pq.pop();

        int v=t.first;
        int w=t.second;
        if(visited[v])continue;
        ans[v]=w;
        visited[v]=true;
        for(int i=0;i<graph[v].size();i++){
            if(!visited[graph[v][i].first]){
             pq.push({graph[v][i].first,graph[v][i].second+w});
            }
        }
    }
    for(int i=2;i<=n;i++)cout<<ans[i]<<" ";
    cout<<'\n';

}