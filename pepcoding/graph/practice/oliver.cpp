#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
vector<int> depth(100005);
vector<int> par(100005);
vector<int> jumppar(100005);
  int n;
int height=0;

void bfs(){
    queue<int> q;
    q.push(1);
    vector<int> vis(100005,false);
    // vector<int> dis(100005,0);
    // dis[1]=1;
    while(!q.empty()){

        int t=q.size();
        while(t--){
         int top=q.front();
         q.pop();
         vis[top]=true;
         for(int i=0;i<graph[top].size();i++){
             if(!vis[graph[top][i]]){
                //  dis[graph[top][i]]=dis[top]+1;
                 q.push(graph[top][i]);
             }
         }
    }
    height++;
    }
    height=sqrt(height);

}
void dfs(int curr,int prev){
    par[curr]=prev;
    depth[curr]=depth[prev]+1;
   
    if(depth[curr]%height==0){
        jumppar[curr]=par[curr];
    }
    else{
        jumppar[curr]=jumppar[prev];
    }


    for(int i=0;i<graph[curr].size();i++){
        if(prev!=graph[curr][i])
     dfs(graph[curr][i],curr);
    }
}

int lcanaive(int u,int v){
    if(u==v)return u;
    if(depth[u]>depth[v])swap(u,v);
    v=par[v];
    return lcanaive(u,v);
}

int lcasqrt(int u,int v){
    while(jumppar[u]!=jumppar[v]){
        if(depth[u]>depth[v])
        swap(u,v);
        v=jumppar[v];
    }
    return lcanaive(u,v);
}




int main(){

     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<n-1;i++){
         int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
}
depth[0]=-1;
bfs();
dfs(1,0);


 int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==0){
            if(lcasqrt(a,b)==a)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
             if(lcasqrt(a,b)==b)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }


}