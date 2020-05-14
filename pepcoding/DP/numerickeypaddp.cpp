#include<bits/stdc++.h>
using namespace std;

int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
long dp[4][3][31];

int helper(int x,int y,int n,long dp[4][3][31]){
    if(n==1)return dp[x][y][n]=1;
    if(dp[x][y][n]!=-1)return dp[x][y][n];

    long res=helper(x,y,n-1,dp);
    if(x+1<4&&matrix[x+1][y]!=-1)res+=helper(x+1,y,n-1,dp);
     if(y+1<3&&matrix[x][y+1]!=-1)res+=helper(x,y+1,n-1,dp);
      if(x-1>-1&&matrix[x-1][y]!=-1)res+=helper(x-1,y,n-1,dp);
       if(y-1>-1&&matrix[x][y-1]!=-1)res+=helper(x,y-1,n-1,dp);

       return dp[x][y][n]=res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]!=-1)ans+=helper(i,j,n,dp);
            }
        }
        cout<<ans<<"\n";
    }
}