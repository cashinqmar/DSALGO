#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,f;
    cin>>n>>m>>f;

    vector<int> capacity(n);
    for(int i=0;i<n;i++)cin>>capacity[i];

    vector<vector<pair<int,long long int>>> graph(n+1);
    for(int i=0;i<m;i++){
      int x,y,w;
      cin>>x>>y>>w;
      graph[x].push_back({y,w});
      graph[y].push_back({x,w});
    }
    int k;
    cin>>k;

    vector<long long int> djikstra(n+1,-1);

    priority_queue<pair<int,long long int>,vector<pair<int,long long int>>,greater<pair<int,long long int>>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        pair<int,long long int> temp=pq.top();
        pq.pop();
        long long int w=temp.first;
        int u=temp.second;
        if(djikstra[u]!=-1){
            continue;
        }

        djikstra[u]=w;

        for(auto i:graph[u]){
            if(djikstra[i.first]==-1){
                pq.push({w+i.second,i.first});
            }
        }
    }

    vector<pair<long long int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({djikstra[i+1],capacity[i]});
    }

    sort(arr.rbegin(),arr.rend());
    int count=0;
    while(count<k&&arr.size()>0){
    int t=arr.size();

        if(arr[t-1].second==0){
            arr.pop_back();
        }
        else {
            cout<<arr[t-1].first+f<<" ";
            arr[t-1].second--;
            count++;
        }
    }

    while(count<k){
        cout<<"-1"<<" ";
        count++;
    }


}