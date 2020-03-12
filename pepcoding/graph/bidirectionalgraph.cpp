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
int n=8;
vector<vector<edge*>> graph(n,vector<edge*>());

void addedge(int u,int v,int w){
    graph[u].push_back(new edge(v,w));
    graph[v].push_back(new edge(u,w));
}

void display(){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto e:graph[i]){
            cout<<"("<<e->v<<","<<e->w<<")";
        }
        cout<<endl;
    }
}


void removeedge(int u,int v){
    int udx=-1;
    int vdx=-1;

 for(int i=0;i<n;i++){
     if(graph[u][i]->v==v){
         udx=i;
         break;
     }
 }

  for(int i=0;i<n;i++){
     if(graph[v][i]->v==u){
         vdx=i;
         break;
     }
 }

 graph[u].erase(graph[u].begin()+udx);
 graph[v].erase(graph[v].begin()+vdx);
}

void removevertex(int u){
    for(int i=graph[u].size()-1;i>=0;i--){
        removeedge(u,graph[u][i]->v);
    }
}

int countpaths(int sr,int des,vector<bool> &vis,string ans){
    vis[sr]=true;
    if(sr==des){
       cout<<ans+" "+to_string(sr)<<endl;
        vis[sr]=false;
        return 1;
    }
    int count=0;
    for(int i=0;i<graph[sr].size();i++){
        if(!vis[graph[sr][i]->v]){
            count+=countpaths(graph[sr][i]->v,des,vis,ans+" "+to_string(sr));
        }
    }
    vis[sr]=false;
return count;
}

bool haspath(int sr,int des,vector<bool> &vis,string ans){
    vis[sr]=true;

    if(sr==des){
        cout<<ans+" "+to_string(sr)<<endl;
        return true;
    }
bool res=false;
    for(int i=0;i<graph[sr].size();i++){
        if(!vis[graph[sr][i]->v]){
            res=res|haspath(graph[sr][i]->v,des,vis,ans+" "+to_string(sr));
        }
    }

    vis[sr]=false;
    return res;
}

int searchvertex(int u,int v){
    int idx=-1;
  for(int i=0;i<graph[u].size();i++){
  if(graph[u][i]->v==v){
      idx=i;
      break;
  }
 }
 return idx;
}

void hamiltonian(int sr,int osr,vector<bool>& visited,int count,string ans){
    if(count==n-1){
      if(searchvertex(sr,osr)==-1){
          cout<<" has path"<<ans<<endl;
      }
      else{
          cout<<" has cycle"<<ans<<endl;
      }

      return;
    }

    visited[sr]=true;

    for(int i=0;i<graph[sr].size();i++){
        if(!visited[graph[sr][i]->v]){
            hamiltonian(graph[sr][i]->v,osr,visited,count+1,ans+to_string(sr));
        }
    }
    visited[sr]=false;
}


void dfs(int sr,vector<int>& low,vector<int>& dis,vector<int>& art,vector<bool>& vis,vector<int> &par){
      static int time=0;
    low[sr]=dis[sr]=time;
    time++;
    vis[sr]=true;
   int children=0;

    for(int i=0;i<graph[sr].size();i++){
        int node=graph[sr][i]->v;

        if(!vis[node]){
            par[node]=sr;

            dfs(node,low,dis,art,vis,par);

            children++;

            low[sr]=min(low[sr],low[node]);

                if(par[sr]!=-1&&dis[sr]<=low[node]){
                art[sr]++;
            }


            if(par[sr]==-1&&children>1&&dis[sr]<=low[node]){
              art[sr]++;
            }

            if(dis[sr]<low[node]){
                cout<<"edge "<<sr<<" "<<node<<endl;
            }
        }

        else if(par[sr]!=node){
       low[sr]=min(low[sr],dis[node]);
        }
    }
}
void creategraph(){
    addedge(0, 1, 10);
    addedge(0, 2, 10);
    addedge(2, 3, 40);
    addedge(3, 1, 2);
    // addedge(4, 1, 2);
    addedge(4, 3, 8);
    addedge(5, 4, 3);
    addedge(4,7,10);
    addedge(5,6,10);
    addedge(6,7,9);
}

void solve(){
creategraph();
// display();
vector<bool> vis(n,false);
vector<int> low(n,0);
vector<int> dis(n,0);
vector<int> art(n,0);
vector<int> par(n,-1);

for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,low,dis,art,vis,par);
    }
}
for(int i=0;i<n;i++){
    if(art[i]>0)cout<<i<<" ";
}
// removeedge(3, 2);
// removevertex(3);
// display();
// vector<bool> vis(n,false);
// cout<<countpaths(0,6,vis,"");
// hamiltonian(0,0,vis,0,"");
}


int main(){
solve();
return 0;
}