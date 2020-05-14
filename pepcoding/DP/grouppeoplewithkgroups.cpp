#include<bits/stdc++.h>
using namespace std;

int memoization(int n,int k,vector<vector<int>>& dp){
    if(n<k){
        return dp[n][k]=0;
    }
    if(k==1||n==k){
        return dp[n][k]=1;
    }
    if(dp[n][k]!=0)return dp[n][k];

    
    int setwithitself=memoization(n-1,k-1,dp);
    int setwithother=memoization(n-1,k,dp)*k;
    int ans=setwithitself+setwithother;
    return dp[n][k]=ans;
}

int tabulation(int n,int k,vector<vector<int>> &dp){

for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
          if(i<j){
       dp[i][j]=0;
        continue;
    }
    if(j==1||j==i){
       dp[i][j]=1;
       continue;
    }
    
    int setwithitself=dp[i-1][j-1];
    int setwithother=dp[i-1][j]*j;
    int ans=setwithitself+setwithother;
     dp[i][j]=ans;
    }
}
return dp[n][k];

}


int recursion(int n,int k){
    if(n<k)return 0;
    if(k==1)return 1;

    int setwithitself=recursion(n-1,k-1);
    int setwithother=recursion(n-1,k)*k;
    int ans=setwithitself+setwithother;
    return ans;
}

int main(){
    int n=6,k=3;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    cout<< tabulation(n,k,dp);
}