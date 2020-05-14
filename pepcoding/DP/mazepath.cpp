#include<bits/stdc++.h>
using namespace std;

int mazepathmemoization(int sr,int sc,int er,int ec,vector<vector<int>>&dp){
    if(sr==er&&er==ec){
        return 1;
    }
  
    int count=0;

    for(int i=1;i<=er;i++){
    if(sr+1*i<=er)count+=mazepathmemoization(sr+1*i,sc,er,ec,dp);
    if(sr+1*i<=er&&sc+1*i<=ec)count+=mazepathmemoization(sr+1*i,sc+1*i,er,ec,dp);
    if(sc+1*i<=ec)count+=mazepathmemoization(sr,sc+1*i,er,ec,dp);

    }
    return dp[sr][sc]=count;
}
int tabulation(int sr,int sc,int er,int ec,vector<vector<int>>&dp){


    for(int i=er;i>=0;i--){
        for(int j=ec;j>=0;j--){
                if(i==er&&j==ec){
                    dp[er][ec]=1;
                  }
                  for(int k=1;k<=er;k++){
           if((i+1*k<=er))dp[i][j]+=dp[i+1*k][j];
          if((i+1*k<=er&&((j+1)*k<=ec)))dp[i][j]+=dp[i*k+1*k][j*k+1*k];
          if((j+1*k<=ec))dp[i][j]+=dp[i][j*k+1*k];
                  }

    }
    }
    return dp[sr][sc];
}


int main(){
    int sr,sc,er,ec;
    cin>>sr>>sc>>er>>ec;

    vector<vector<int>> dp(er+1,vector<int>(ec+1,0));
    int ans=mazepathmemoization(sr,sc,er,ec,dp);
    for(auto i:dp){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
     for(int i=er;i>=0;i--)
        for(int j=ec;j>=0;j--)dp[i][j]=0;



     ans=tabulation(sr,sc,er,ec,dp);
for(auto i:dp){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
    cout<<ans<<" ";

}