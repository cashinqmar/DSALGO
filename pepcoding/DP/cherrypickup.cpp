#include<bits/stdc++.h>
using namespace std;

int helper(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){

    int c2=r1+c1-r2;

    if(r1>=grid.size()||r2>=grid.size()||c1>=grid[0].size()||c2>=grid[0].size()){
        return INT_MIN;
    }
    int ans=0;
    if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
    if((r1==grid.size()-1&&c1==grid[0].size()-1)){
        return grid[r1][c1];
    }
    if((c2==grid[0].size()-1||r2==grid.size()-1)){
        return grid[r2][c2];
    }

    ans+=grid[r1][c1];

    if(c1!=c2){
        ans+=grid[r2][c2];
    }

    int temp1=helper(r1,c1+1,r2,grid,dp);
    int temp2=helper(r1+1,c1,r2,grid,dp);
    int temp3=helper(r1+1,c1,r2+1,grid,dp);
    int temp4=helper(r1,c1+1,r2+1,grid,dp);

    ans=max(ans,max(temp1,temp2));
    ans=max(ans,max(temp3,temp4));

    return dp[r1][c1][r2]=ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int>(n,-1)));
    return helper(0,0,0,grid,dp);
}
int main(){

}