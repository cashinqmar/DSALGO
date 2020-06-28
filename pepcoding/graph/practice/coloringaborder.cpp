#include<bits/stdc++.h>
using namespace std;

   
bool isavlid(vector<vector<int>>& grid,int x,int y){
    return x>=0&&x<grid.size()&&y>=0&&y<grid[0].size();
}

vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<int>>& grid,int x,int y,int original,int color,vector<vector<bool>> &visited){

visited[x][y]=true;
int count=0;
    
 for(int i=0;i<4;i++){
int newx=x+dir[i][0];
int newy=y+dir[i][1];

if(isavlid(grid,newx,newy)&&(grid[newx][newy]==original||grid[newx][newy]==grid[x][y]))
count++;
 }       
    
for(int i=0;i<4;i++){
int newx=x+dir[i][0];
int newy=y+dir[i][1];

if(isavlid(grid,newx,newy)&&(grid[newx][newy]==original)){
if(visited[newx][newy]==false)  
dfs(grid,newx,newy,original,color,visited);
}
    
}
    

    
if(count!=4)grid[x][y]=color;
    
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
       int n=grid.size();
       int m=grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int original=grid[r0][c0];
        dfs(grid,r0,c0,original,color,visited);
        return grid;
}
int main(){

}