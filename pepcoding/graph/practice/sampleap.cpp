#include<bits/stdc++.h>
using namespace std;

vector<long int> graph[100005];
vector<long int> dis(100005,0);
vector<long int> low(100005,0);
vector<long int> par(100005,-1);
vector<bool> art(100005,false);
vector<bool> vis(100005,false);

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

void dfs(long int sr,map<pair<long int,long int>,long int> &m){
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

            dfs(node,m);
            child++;
            low[sr]=min(low[sr],low[node]);

            if(par[sr]==-1&&child>1)art[sr]=true;

            if(par[sr]!=-1&&dis[sr]<=low[node])art[sr]=true;

            if(dis[sr]<low[node]){
                if(sr<node){
                    pair<int,int> p;
                    p.first=sr;
                    p.second=node;
                    m[p]++;
                }
                else {
                     pair<int,int> p;
                    p.first=node;
                    p.second=sr;
                    m[p]++;
                }
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
    
        long int n,m;
        cin>>n>>m;
        long int k;
        cin>>k;
        n++;
       map< pair< long int,long int>,long int> mp;

        // init(n);

        vector<pair<long int,long int>> input(1000005);
        map<pair<int,int>,int> lol;
       
        for(int i=1;i<=m;i++){
           long  int x,y,z;
            cin>>x>>y>>z;
            if(x<y){
                 input[z].first=x;
                 input[z].second=y;
                 lol[input[z]]++;
            }
            else{
            input[z].first=y;
            input[z].second=x;
             lol[input[z]]++;
            }
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,mp);
            }
        }
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(art[i]==true)count++;
        // }
        // cout<<count<<endl;
     
          for(int i=0;i<k;i++){
              int x;
              cin>>x;
              pair<int,int> p=input[x];
            if(mp[p]>=1&&lol[p]==1)cout<<"/nYES";
            else cout<<"/nno";
        }
}