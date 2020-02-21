#include<bits/stdc++.h>
using namespace std;


bool haslonger(vector<vector<int>>& matrix,int tar,vector<bool>& visited,int sc){
    if(tar<=0){
        return true;
    }

    for(int i=0;i<matrix[0].size();i++){
  if(matrix[sc][i]!=0&&!visited[i]){
      visited[i]=true;
       if(haslonger(matrix,tar-matrix[sc][i],visited,i))return true;
      visited[i]=false;
  }
    }
    return false;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<k;i++){
        int x,y,w;
        cin>>x>>y>>w;
        matrix[x][y]=w;
        matrix[y][x]=w;
    }

    vector<bool> visited(n,false);
    int s,minw;
    cin>>s>>minw;
    visited[s]=true;
    if(haslonger(matrix,minw,visited,s))cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
int main(){
solve();
return 0;
}