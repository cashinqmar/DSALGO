#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,e;
    cin>>n>>e;
    vector<vector<pair<long long int,long long>>> graph(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<e;i++){
      long long int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }

    long long  sum=0;
    pq.push({0,1});
    vector<bool> visited(n+1,false);
    while(!pq.empty()){
        pair<long long,long long> temp=pq.top();
        pq.pop();

        if(visited[temp.second])continue;
        sum+=temp.first;
        visited[temp.second]=true;

        for(auto i:graph[temp.second]){
            if(!visited[i.first]){
                pq.push({i.second,i.first});
            }
        }
    }

    cout<<sum<<"\n";


}