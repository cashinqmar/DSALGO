#include<bits/stdc++.h>
using namespace std;

int tabulation(int s,int e,vector<int> &arr,vector<int>& dp){
for(int j=e;j>=0;j--){
    if(j==e){
        dp[j]=1;
        continue;
    }
        int count=0;
    for(int i=0;i<arr.size();i++){
        if(j+arr[i]<=e)
        count+=dp[j+arr[i]];
    }

    dp[j]=count;
}
return dp[s];
}


int memoization(int s,int e,vector<int> &arr,vector<int> &dp){

    if(s==e){
        dp[s]=1;
        return 1;
    }
    if(dp[s]!=0) return dp[s];

 int count=0;
    for(int i=0;i<arr.size();i++){
        if(s+arr[i]<=e)
        count+=memoization(s+arr[i],e,arr,dp);
    }

    return dp[s]=count;
}


int countways(int s,int e,vector<int>& arr){
    if(s==e){
        return 1;
    }
      int count=0;
    for(int i=0;i<arr.size();i++){
        if(s+arr[i]<=e)
count+=countways(s+arr[i],e,arr);
    }

    return count;
}


int main(){

    vector<int> arr={1,2,3,4,5,6};
    vector<int>dp(11,0);
    // int ans=countways(0,10,arr);
    // int ans=memoization(0,10,arr,dp);
    int ans=tabulation(0,10,arr,dp);
    cout<<ans;

}