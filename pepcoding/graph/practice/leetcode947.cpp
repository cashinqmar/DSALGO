#include<bits/stdc++.h>
using namespace std;

int root(unordered_map<int,int> &par,int vtx){
    if(par[vtx]==vtx)return vtx;
    return par[vtx]=root(par,par[vtx]);
}

void merge(unordered_map<int,int> &par,int x,int y,int &count){
  int a=root(par,x);
  int b=root(par,y);
  if(a!=b){
          par[a]=b;
           count--;
  }
}

int removeStones(vector<vector<int>>& stones) {
unordered_map<int,int> par;

    int count=0;
for(int i=0;i<stones.size();i++){
    int x=stones[i][0];
    int y=stones[i][1]+10001;

    if(par.find(x)==par.end()){
        par[x]=x;
        count++;
    }
    if(par.find(y)==par.end()){
        par[y]=y;
        count++;
    }
    merge(par,x,y,count);
}

set<int> s;
for(int i=0;i<stones.size();i++){
    int k=root(par,stones[i][0]);
    s.insert(k);
}

return stones.size()-s.size();
}

int main(){
vector<vector<int>>stones = {{0,1},{1,0},{1,1}};

cout<<"\n";
cout<<removeStones(stones);
}