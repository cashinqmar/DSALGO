#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int v=0;
    int w=0;
    edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};

void addedge(vector<vector<edge*>> &graph,int u,int v,int w){
    graph[u].push_back(new edge(v,w));
    graph[v].push_back(new edge(u,w));
}

void display(vector<vector<edge*>> &graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto e:graph[i]){
            cout<<"("<<e->v<<","<<e->w<<")";
        }
        cout<<endl;
    }
}
void dfs(vector<vector<edge*>> &graph,int sr,vector<int>& low,vector<int>& dis,vector<bool>& art,vector<bool>& vis,vector<int> &par){
      static int time=0;
    low[sr]=dis[sr]=time;
    time++;
    vis[sr]=true;
   int children=0;

    for(int i=0;i<graph[sr].size();i++){
        int node=graph[sr][i]->v;

        if(!vis[node]){
            par[node]=sr;
             children++;

            dfs(graph,node,low,dis,art,vis,par);

           

            low[sr]=min(low[sr],low[node]);

                if(par[sr]!=-1&&dis[sr]<=low[node]){
                art[sr]=true;
            }


            if(par[sr]==-1&&children>1){
              art[sr]=true;
            }

            // if(dis[sr]<low[node]){
            //     // if(sr<node)p.push_back(make_pair(sr,node));
            //     // else p.push_back(make_pair(node,sr));
            // }
        }

        else if(par[sr]!=node){
       low[sr]=min(low[sr],dis[node]);
        }
    }
}

void solve(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<vector<edge*>> graph(3000,vector<edge*>());

int e;
cin>>e;
int k;
cin>>k;
for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    addedge(graph,x,y,0);
}

vector<bool> vis(n,false);
vector<int> low(n,0);
vector<int> dis(n,0);
vector<bool> art(n,false);
vector<int> par(n,-1);
for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(graph,i,low,dis,art,vis,par);
    }
}
int count=0;
for(int i=0;i<n;i++){
    if(art[i]==true)count++;
}
cout<<count*k<<endl;
}
}
int main(){
solve();
return 0;
}