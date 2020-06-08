#include<bits/stdc++.h>
using namespace std;

   bool isvalid(vector<vector<int>> &grid,int x,int y){
    return x>=0&&x<grid.size()&&y>=0&&y<grid[0].size();
}

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

string str="";

void dfs(vector<vector<int>> &grid,int x,int y){
grid[x][y]=0;

for(int i=0;i<4;i++){
    int newx=x+dir[i][0];
    int newy=y+dir[i][1];
    if(isvalid(grid,newx,newy)&&grid[newx][newy]==1){
      if(i==0){
          str+="r";
          dfs(grid,newx,newy);
          str+='x';
      }
      if(i==1){
str+="l";
          dfs(grid,newx,newy);
          str+='x';
      }
      if(i==2){
str+="d";
          dfs(grid,newx,newy);
          str+='x';
      }
      if(i==3){
str+="u";
          dfs(grid,newx,newy);
          str+='x';
      }
    }

}
}

int numberofDistinctIslands(vector<vector<int>> &grid) {
        // write your code here
unordered_set<string> count;

for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
        if(grid[i][j]==1){
            str="s";
            dfs(grid,i,j);
            count.insert(str);
        }
    }
}
return count.size();
}
int main(){

}