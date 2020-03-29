#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+2;
#define pi pair<pair<int,int>,long int> 
vector<pi> edges(100005);
vector<int> par(MAX,0);
vector<int> siz(MAX,0);


void initialise(int n){
    for(int i=0;i<=n;i++)par[i]=i;
    edges.clear();
    siz.clear();
}

int root(int vtx){
   if (par[vtx] == vtx)
        return vtx;

    par[vtx] = root(par[vtx]);
    return par[vtx];
}

void merge(int x,int y){
    int a=root(x);
    int b=root(y);
    if(siz[a]<siz[b]){
        par[a]=b;
        siz[b]+=siz[a];
    }
    else{   
        par[b]=a;
        siz[a]+=siz[b];
    }
}
long long int kruskals(int m){
    int x,y;
    long long  cost,mincost=0;
    for(int i=0;i<m;i++){
        x=edges[i].first.first;
        y=edges[i].first.second;
        cost=edges[i].second;
        if(root(x)!=root(y)){
            mincost+=cost;
            merge(x,y);
        }
    }
    return mincost;
}
int main(){
           ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
int n,m;
cin>>n>>m;
initialise(n);
for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    edges[i]={{x,y},z};
}
sort(edges.begin(),edges.begin()+m,[](pi a,pi b){
    return a.second<b.second;
});
// for(int i=0;i<m;i++)cout<<edges[i].second<<" ";

long long int ans=kruskals(m);
cout<<ans<<"\n";
}