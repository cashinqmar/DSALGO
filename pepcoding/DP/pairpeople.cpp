#include<bits/stdc++.h>
using namespace std;

int pairpeoplerec(int n,vector<int>& dp){
    if(n<=1)return dp[n]=1;
    if(dp[n]!=0)return dp[n];

    int singlepair=pairpeoplerec(n-1,dp);
    int pairedextra=pairpeoplerec(n-2,dp)*(n-1);

    return dp[n]=singlepair+pairedextra;
}

int tabulation(int i,vector<int>& dp){
    for(int n=0;n<=i;n++){
        if(n<=1){
            dp[n]=1;
            continue;}

    int singlepair=dp[n-1];
    int pairedextra=dp[n-2]*(n-1);
 dp[n]=singlepair+pairedextra;
    }
    return dp[i];
}

int twovariable(int n){
    int a=1;
    int b=1;
    int ans;
    for(int i=2;i<n;i++){
      
       ans=a+b*(i-1);
       b=a;
       a=ans;
    }
    return ans;
}

int main(){
    int n=7;
    vector<int> dp(n+1);
    cout<<twovariable(n);
}