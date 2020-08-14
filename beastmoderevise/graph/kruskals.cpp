#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,pair<int,long long>> &a,const pair<int,pair<int,long long>>&b){
    return a.second.second<b.second.second;
}


int root(vector<int> &par,int vtx){
    if(par[vtx]==vtx)return vtx;
    return par[vtx]=root(par,par[vtx]);
}

void merge(vector<int> &par,vector<int>& rank,int x,int y){
    int a=root(par,x);
    int b=root(par,y);

    if(a!=b){
        if(rank[a]<rank[b]){
            par[a]=b;
        }
        else if(rank[a]>rank[b]){
            par[b]=a;
        }
        else{
            par[a]=b;
            rank[b]++;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,pair<int,long long>>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        long long int z;
        cin>>x>>y>>z;
        edges.push_back({x,{y,z}});
    }

    sort(edges.begin(),edges.end(),compare);

    vector<int> par(n+1);
    vector<int> rank(n+1,0);

    for(int i=0;i<n+1;i++)par[i]=i;
    
    long long ans=0;
    int count=0;
    int i=0;
    while(count<n-1&&i<edges.size()){
        pair<int,pair<int,long long>> temp=edges[i];
        i++;

        int u=temp.first;
        int v=temp.second.first;
        long long w=temp.second.second;

        if(root(par,u)==root(par,v))continue;

        else{
            ans+=w;
            merge(par,rank,u,v);
            count++;
        }
    }

    cout<<ans<<"\n";
}