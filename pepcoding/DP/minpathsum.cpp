#include<bits/stdc++.h>
using namespace std;
  
int helper(vector<vector<int>>& grid, vector<vector<int>>& dp,int x,int y){
if(x==grid.size()-1&&y==grid[0].size()-1){
    return dp[x][y]=grid[x][y];
}

if(dp[x][y]!=-1){
    return dp[x][y];
}

int minm=INT_MAX;
    
if(x+1<grid.size()){
    minm=min(minm,helper(grid,dp,x+1,y));
}

if(y+1<grid[0].size()){
    minm=min(minm,helper(grid,dp,x,y+1));
}

return dp[x][y]=minm+grid[x][y];

}

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return helper(grid,dp,0,0);
}
int main(){

}