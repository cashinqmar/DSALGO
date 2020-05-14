#include<bits/stdc++.h>
using namespace std;

int matrixchainrecursion(vector<int>& arr,int st,int end,vector<vector<int>> &dp){
    if(st+1==end)return dp[st][end]=0;
    if(dp[st][end]!=-1)return dp[st][end];
    int min_=INT_MAX;
    for(int cut=st+1;cut<end;cut++){
        int leftcost=matrixchainrecursion(arr,st,cut,dp);
        int rightcost=matrixchainrecursion(arr,cut,end,dp);

        int mycost=leftcost + arr[st]*arr[cut]*arr[end]+rightcost;
        min_=min(min_,mycost);
    }
    return dp[st][end]=min_;
}

int  matrixchaintabulation(vector<int>& arr,vector<vector<int>> &dp){

    for(int gap=1;gap<arr.size();gap++){
        for(int st=0,end=gap;end<arr.size();st++,end++){

            if(st+1==end){ 
                dp[st][end]=0;
                continue;
            }
    int min_=INT_MAX;
    for(int cut=st+1;cut<end;cut++){
        int leftcost=dp[st][cut];
        int rightcost=dp[cut][end];

        int mycost=leftcost + arr[st]*arr[cut]*arr[end]+rightcost;
        min_=min(min_,mycost);
    }
          dp[st][end]=min_;
        }
    }
        return dp[0][arr.size()-1];
    }

int  matrixchaintabulationbrackets(vector<int>& arr,vector<vector<int>> &dp,vector<vector<string>> &sdp){

    for(int gap=1;gap<arr.size();gap++){
        for(int st=0,end=gap;end<arr.size();st++,end++){

            if(st+1==end){ 
                dp[st][end]=0;
                sdp[st][end]=(char('A'+st));
                continue;
            }
    int min_=INT_MAX;
    string mins="";
    for(int cut=st+1;cut<end;cut++){
        int leftcost=dp[st][cut];
        int rightcost=dp[cut][end];

        int mycost=leftcost + arr[st]*arr[cut]*arr[end]+rightcost;
      if(min_>mycost){
          min_=mycost;
          mins="("+sdp[st][cut]+sdp[cut][end]+")";
      }
    }
      sdp[st][end]=mins;

          dp[st][end]=min_;
        }
    }
    cout<<sdp[0][arr.size()-1];
    return dp[0][arr.size()-1];
    }

    



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // cout<<matrixchainrecursion(arr,0,n-1,dp)<<"\n";
        // for(auto i:dp){
        //     for(auto j:i)cout<<j<<" ";
        //     cout<<"\n";
        // }
         vector<vector<string>> sdp(n,vector<string>(n));
        matrixchaintabulationbrackets(arr,dp,sdp);
        cout<<"\n";
    }
}