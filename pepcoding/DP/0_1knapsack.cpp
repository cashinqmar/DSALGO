#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &dp, vector<int> &value,vector<int> &weight,int wt,int idx){
    if(wt<=0||idx<=0){
        return 0;
    }

    if(dp[idx][wt]!=-1)return dp[idx][wt];

    int ans=0;
//picked
    if(wt-weight[idx]>=0){
    ans=helper(dp,value,weight,wt-weight[idx],idx-1)+value[idx];
    }
//notpicked
    ans=max(ans,helper(dp,value,weight,wt,idx-1));

    return dp[idx][wt]=ans;
}


int main(){
int t;
cin>>t;
while(t--){
    int n,wt;
    cin>>n>>wt;
    vector<int> value(n,0);
    vector<int> weight(n,0);
    for(int i=0;i<n;i++)cin>>value[i];
    for(int i=0;i<n;i++)cin>>weight[i];

    vector<vector<int>> dp(n,vector<int> (wt+1,-1));
    cout<<helper(dp,value,weight,wt,n-1)<<"\n";
}
}