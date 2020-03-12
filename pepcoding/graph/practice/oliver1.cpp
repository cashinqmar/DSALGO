#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
vector<int> out(100005,0);
vector<int> in(100005,0);
vector<int> vis(100005,false);
int timer=0;

void dfs(int n){
    vis[n]=true;
    in[n]=timer++;
    for(int i=0;i<graph[n].size();i++){
        if(!vis[graph[n][i]])dfs(graph[n][i]);
    }
    out[n]=timer++;
    }

bool check(int u,int v){
    if(in[u]<in[v]&&out[u]>out[v])return true;return false;
}
int main(){
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      graph[x].push_back(y);
    }
    dfs(1);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==0){
            if(check(a,b))cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
             if(check(b,a))cout<<"YES\n";
            else cout<<"NO\n";

        }
    }

}