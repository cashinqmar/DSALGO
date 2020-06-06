#include<bits/stdc++.h>
using namespace std;

//bellman ford

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        unordered_map<int,unordered_map<int,int>> edges;

        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            edges[x][y]=z;
        }

        for(int i=0;i<n-1;i++){
            
           for(auto i:edges){
               for(auto j:i.second){
                   int u=i.first;
                   int v=j.first;
                   int w=j.second;

                   if(dist[u]!=INT_MAX){
                       if(dist[v]>dist[u]+w){
                           dist[v]=dist[u]+w;
                       }
                   }
               }
           }
        }

        vector<int> duplicate(n);
        for(int i=0;i<n;i++)duplicate[i]=dist[i];

         for(auto i:edges){
               for(auto j:i.second){
                   int u=i.first;
                   int v=j.first;
                   int w=j.second;

                   if(dist[u]!=INT_MAX){
                       if(dist[v]>dist[u]+w){
                           dist[v]=dist[u]+w;
                       }
                   }
               }
           }

           bool res=true;
           for(int i=0;i<n;i++){
               if(dist[i]!=duplicate[i]){
                   res=false;
                   break;
               }
           }
           if(res)cout<<0<<"\n";
           else cout<<1<<"\n";
    }   
}