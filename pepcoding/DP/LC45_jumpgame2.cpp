#include<bits/stdc++.h>
using namespace std;
//greedy O(n)
int jump(vector<int>& nums) {
    int currentend=0;
    int currentfarthest=0;
    int jump=0;
    for(int i=0;i<nums.size()-1;i++){
        currentfarthest=max(currentfarthest,i+nums[i]);
        if(i==currentend){
            jump++;
            currentend=currentfarthest;
        }
    }
    return jump;
}
//O(n2)
int jump(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;

    for(int i=0;i<n;i++){
        for(int j=1;j<=nums[i];j++){
            if(i+j<n){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){

}