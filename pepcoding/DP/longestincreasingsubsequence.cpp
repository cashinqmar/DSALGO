#include<bits/stdc++.h>
using namespace std;
//longest increasing
int LISDP(vector<int> & arr,vector<int> &dp){

    dp[0]=1;
    int ans=1;
    for(int i=1;i<arr.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i])
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int LDSDP(vector<int>& arr,vector<int> &dp){
    //longest decreasing subsequence

  int n=arr.size();
    dp[n-1]=1;
    int ans=1;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i])
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

int LBSDP(vector<int> &arr){
    //longest bitonic subsequence
        vector<int>LIS(arr.size(),1);
        vector<int>LDS(arr.size(),1);
        LISDP(arr,LIS);
        LDSDP(arr,LDS);

        int ans=1;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,LIS[i]+LDS[i]-1);
        }
        return ans;

}

int LRBSDP(vector<int>& arr){
    //longest reverse bitonic subsequence
} 

int main(){
    vector<int> arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<LBSDP(arr);

}