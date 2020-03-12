#include<bits/stdc++.h>
using namespace std;

vector<long int> graph[100005];
vector<long int> dis(100005,0);
vector<long int> low(100005,0);
vector<long int> par(100005,-1);
vector<bool> art(100005,false);
vector<bool> vis(100005,false);
vector<int>  ans(100005,0);

map< pair< long int,long int>,long int> m;

void dfs(long int sr){
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

            if(dis[sr]<low[node]){
                m[{sr,node}]=1;
                 m[{node,sr}]=1;
                }
            }

        else if(par[sr]!=node){
            low[sr]=min(low[sr],dis[node]);
        }
    }
}

int main(){
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        long int n,z;
        cin>>n>>z;
      
        for(int i=0;i<z;i++){
           long  int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }

         for(int i=0;i<=n;i++){
        vis[i]=false;
    }
        queue<int> q;
        q.push(n);
     
        ans[n]=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            vis[top]=true;
            for(int i=0;i<graph[top].size();i++){
                int node=graph[top][i];
                if(!vis[node]){
               
                  ans[node]=ans[top]+m[{top,node}];
                   q.push(node);
                }

            }
        }

        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
        
            if(ans[x])cout<<ans[x]<<"\n";
             else cout<<"impossible\n";

            }
        }