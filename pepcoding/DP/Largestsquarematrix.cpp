#include<bits/stdc++.h>
using namespace std;

int ans;
//memoization
int maxmsquare(vector<vector<int>> &matrix,vector<vector<int>> &dp,int x,int y){
    int m=matrix.size();
    int n=matrix[0].size();

    if(x==m-1||y==n-1){
        return dp[x][y]=matrix[x][y];
    }

    if(dp[x][y]!=-1)return dp[x][y];

    int count=INT_MAX;
    if(x+1<m){
        count=min(count,maxmsquare(matrix,dp,x+1,y));
    }
    if(y+1<n){
        count=min(count,maxmsquare(matrix,dp,x,y+1));
    }
    if(x+1<m&&y+1<n){
        count=min(count,maxmsquare(matrix,dp,x+1,y+1));
    }

    if(matrix[x][y]==1){
    ans=max(ans,max(1,count+1));
    return dp[x][y]=count+1;
    }
    return dp[x][y]=matrix[x][y];
}

//tabulation
void tabulation(vector<vector<int>> &matrix,vector<vector<int>> &dp){
    int m=matrix.size();
    int n=matrix[0].size();


for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
 if(i==m-1||j==n-1){
    dp[i][j]=matrix[i][j];
    }

    if(dp[i][j]!=-1)continue;

    int count=INT_MAX;
    if(i+1<m){
        count=min(count,dp[i+1][j]);
    }
    if(j+1<n){
               count=min(count,dp[i][j+1]);
    }
    if(i+1<m&&j+1<n){
             count=min(count,dp[i+1][j+1]);
    }

    if(matrix[i][j]==1){
    ans=max(ans,max(1,count+1));
     dp[i][j]=count+1;
    }
    else dp[i][j]=matrix[i][j];
    }

}
   
}


int main(){
int t;
cin>>t;
while(t--){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    vector<vector<int>> dp(m,vector<int>(n,-1));
ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            ans=max(ans,matrix[i][j]);
        }
    }

tabulation(matrix,dp);
cout<<ans<<"\n";
}
}