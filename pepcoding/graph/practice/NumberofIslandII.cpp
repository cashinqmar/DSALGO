#include<bits/stdc++.h>
using namespace std;

 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
int root(vector<int> &par,int vtx){
   if (par[vtx] == vtx)return vtx;
   return par[vtx] = root(par,par[vtx]);
}

void merge(vector<int> &par,vector<int> &ranks,int x,int y,int &count){
    int a=root(par,x);
    int b=root(par,y);
if(a!=b){
    if(ranks[a]<ranks[b]){
       par[a]=b;
    }
    else if(ranks[a]>ranks[b]){
        par[b]=a;
    }
    else{
         par[a]=b;
         ranks[b]++;
    }
    count--;
}
}

vector<int> numIslands2(int n, int m, vector<Point> &arr) {

vector<int> par(n*m,-1);

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

vector<int> ranks(n*m,0);

vector<int> ans;

int count=0;

for(int i=0;i<arr.size();i++){
    int idx=arr[i].x*m+arr[i].y;

    if(par[idx]==-1)count++;par[idx]=idx;

    for(int k=0;k<dir.size();k++){
        int x=arr[i].x+dir[k][0];
        int y=arr[i].y+dir[k][1];

        int newidx=x*m+y;

        if(x>=0&&x<n&&y>=0&&y<m&&par[newidx]!=-1){
            merge(par,ranks,idx,newidx,count);
        }
    }
    ans.push_back(count);
}
return ans;
}

int main(){
int m=5;
int n=4;
vector<Point> arr={{1,1},{0,1},{3,3},{3,4}};
vector<int> res=numIslands2(n,m,arr);
for(auto i:res)cout<<i<<" ";
}