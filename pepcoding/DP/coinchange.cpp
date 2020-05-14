#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& coins,int amount,int idx,vector<int>& dp){
        if(amount==0){
            return dp[amount]=1;
        }
       if(dp[amount]!=0)return dp[amount];

       int count=0;

        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
              count+=helper(coins,amount-coins[i],0,dp);
            }
        }
        return dp[amount]=count;
    }


int coinchangepermutation(vector<int> &coins,int target){
vector<int> dp(target+1,0);
dp[0]=1;
for(int i=0;i<=target;i++){
    for(auto j:coins){
        if(i-j>=0)
        dp[i]+=dp[i-j];
    }
}

return dp[target];
}

int coinchangecombination(vector<int> &coins,int target){
    // coins can be used multiple times
vector<int> dp(target+1,0);
dp[0]=1;
for(auto j:coins)
for(int i=0;i<=target;i++){
    {
        if(i-j>=0)
        dp[i]+=dp[i-j];
    }
}

return dp[target];
}
//one coin one time
int coinchangecombination2(vector<int>& coin,int target,int n,  vector<vector<int>> &dp){
    if(target==0||n==-1){
        if(target==0)return dp[target][n]=1;
        return dp[target][n]=0;
    }

    int count=0;
    if(target-coin[n-1]>=0)count+=coinchangecombination2(coin,target-coin[n-1],n-1,dp);
    count+=coinchangecombination2(coin,target,n-1,dp);

    return  dp[target][n]= count;

}

int main(){
    vector<int> coins={2,3,5,7};
    int target=10;
    // vector<int> dp(target+1,0);
    vector<vector<int>> dp(target+1,vector<int>(coins.size()+1));

    cout<<coinchangecombination2(coins,target,4,dp);
    // cout<<coinchangepermutation(coins,target);
    // cout<<coinchangecombination(coins,target);
    
}