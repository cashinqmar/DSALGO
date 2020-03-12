#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10005];
vector<int> dis(10005,0);
vector<int> low(10005,0);
vector<int> par(10005,-1);
vector<bool> art(10005,false);
vector<bool> vis(10005,false);

void init(int n){
    for(int i=0;i<n+5;i++){
        graph[i].clear();
        dis[i]=0;
        low[i]=0;
        par[i]=-1;
        art[i]=false;
        vis[i]=false;
    }
}

void dfs(int sr){
    static int time=0;
    low[sr]=dis[sr]=time;
    time++;
    vis[sr]=true;

    int child=0;
    for(int i=0;i<graph[sr].size();i++){
        int node=graph[sr][i];
        if(sr==node)continue;

        if(!vis[node]){
        par[node]=sr;

            dfs(node);
            child++;
            low[sr]=min(low[sr],low[node]);

            if(par[sr]==-1&&child>1)art[sr]=true;

            if(par[sr]!=-1&&dis[sr]<=low[node])art[sr]=true;
            
        }
        else if(par[sr]!=node){
            low[sr]=min(low[sr],dis[node]);
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
    
        init(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(art[i]==true)count++;
        }
        cout<<count<<endl;
          for(int i=0;i<n;i++){
            if(art[i])cout<<i<<" ";
        }
        cout<<endl;
    
    }

}