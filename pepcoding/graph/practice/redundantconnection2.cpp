#include<bits/stdc++.h>
using namespace std;

 int root(vector<int>& par,int vtx){
        if(vtx==par[vtx])return vtx;
        return par[vtx]=root(par,par[vtx]);
    }
    void merge(vector<int> &par,vector<int> &size,int x,int y){
        int a=root(par,x);
        int b=root(par,y);
        
        if(a!=b){
            if(size[a]<size[b]){
                par[a]=b;
                size[b]+=size[a];
            }
            else{
                par[b]=a;
                size[a]+=size[b];
            }
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int blacklist=-1;
        int n=edges.size()+1;
        
        vector<int> incoming(n,-1);
        vector<int> par(n);
        vector<int> size(n,0);

        for(int i=0;i<n;i++)par[i]=i;

        bool cycle=false;
       
        int vtx=-1;
        for(int i=0;i<edges.size();i++){
            if(incoming[edges[i][1]]==-1){
                incoming[edges[i][1]]=i;
            }
            else{
                vtx=edges[i][1];
                blacklist=i;
                break;
            }
        }

        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(blacklist!=-1&&blacklist==i)continue;

            int a=root(par,edges[i][0]);
            int b=root(par,edges[i][1]);

            if(a!=b){
                merge(par,size,a,b);
            }
            else{
                cycle=true;
                ans=edges[i];
            }
        }

        if(blacklist!=-1&&cycle){
            return edges[incoming[vtx]];
        }

        if(blacklist!=-1&&!cycle){
            return edges[blacklist];
        }
  
      else return ans;
}

int main(){

}    
