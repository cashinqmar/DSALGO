#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<vector<pair<long int,long int>>> graph(100005);
    vector<bool> visited(100005);
    vector<int> ans(100005,-1);
    
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back({y,0});
        graph[y].push_back({x,1});
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
  cout<<ans[n]<<"\n";
}