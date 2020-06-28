#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &dp,int i,int n){
if(i==n){
    return dp[i]=1;
}

if(dp[i]!=-1)return dp[i];

int count=0;

for(int k=1;k<=2;k++){
    if(i+k<=n){
        count+=helper(dp,i+k,n);
    }
}
return dp[i]=count;
}

 int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return helper(dp,0,n);
}
int main(){

}