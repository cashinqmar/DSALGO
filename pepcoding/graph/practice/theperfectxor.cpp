#include<bits/stdc++.h>
using namespace std;

vector<int> graph[300005];
vector<int> dis(300005,0);
vector<int> low(300005,0);
vector<int> par(300005,-1);
vector<bool> art(300005,false);
vector<bool> vis(300005,false);
vector<int> wt(300005);
vector<int> wtt(300005);
vector<int> x(300005,0);
int total=0;
int maxm=0;

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
            wt[sr]+=wt[node];
            low[sr]=min(low[sr],low[node]);

            if(par[sr]==-1&&child>1){
                art[sr]=true;
                wtt[sr]+=wt[node];
                x[sr]^=wt[node];
            }
            if(par[sr]!=-1&&dis[sr]<=low[node]){
                art[sr]=true;
                wtt[sr]+=wt[node];
                  x[sr]^=wt[node];
            }
            
        }
        else if(par[sr]!=node){
            low[sr]=min(low[sr],dis[node]);
        }
    }
    if(art[sr]){
        x[sr]=x[sr]^(total-wtt[sr]);
        maxm=max(maxm,x[sr]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    n++;

    for(int i=1;i<n;i++){
         int x;
         cin>>x;
         total+=x;
         wt[i]=x;
         wtt[i]=wt[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        // cgraph[x].push_back(y);
        // cgraph[y].push_back(x);
    }
    
    vector<int> nodes;
    for(int i=1;i<n;i++){
        if(!vis[i])dfs(i);
    }
    if(maxm==0)cout<<"-1";
    else cout<<maxm;
}