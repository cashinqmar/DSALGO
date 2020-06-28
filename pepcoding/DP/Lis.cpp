#include <bits/stdc++.h>
using namespace std;
//O(n2) solution
int helper1(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(nums.size(), 0);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


//O(nlogn) solution

int helper2(vector<int> &nums){

int ans=0;
int n=nums.size();

vector<int> arr(n,0);

for(auto val:nums){
    int lo=0;
    int hi=ans;
while(lo<hi){
    int mid=(lo+hi)/2;

    if(arr[mid]<val){
        lo=mid+1;
    }
    else{
        hi=mid;
    }
}
    arr[lo]=val;

    if(lo==ans){
        ans++;
    }
}
return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    return helper(nums);
}

int main()
{
}