#include<bits/stdc++.h>
using namespace std;


int timestamp=0;
void articulationpoint( vector<vector<int>> &graph,int src,vector<int> &par,vector<int> &art, vector<int> &dis,vector<int> &low,vector<int> &vis){
dis[src]=timestamp;
low[src]=timestamp;
timestamp++;
vis[src]=true;

int children=0;

for(auto i:graph[src]){
    if(vis[i]==false){
      par[i]=src;
      
      children++;

      articulationpoint(graph,i,par,art,dis,low,vis);

      low[src]=min(low[src],low[i]);

      if(par[src]!=-1&&dis[src]<=low[i]){
          art[src]=true;
      }

      if(par[src]==-1&&children>1){
          art[src]=true;
      }

       // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // // is a bridge 
            // if (dis[src]<low[i]) 
            //   cout << src <<" " << i << endl; 
    }
    else{
        if(par[src]!=i){
            low[src]=min(low[src],dis[i]);
        }
    }
}

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        n++;
        vector<vector<int>> graph(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        vector<int> par(n,-1);
        vector<int> art(n,false);
        vector<int> dis(n,0);
        vector<int> low(n,0);
        vector<int> vis(n,false);

        for(int i=1;i<n;i++){
         if(vis[i]==false)
        articulationpoint(graph,i,par,art,dis,low,vis);
    }

    int count=0;
    for(auto i:art)if(i)count++;
    
    cout<<count<<"\n";
}
}