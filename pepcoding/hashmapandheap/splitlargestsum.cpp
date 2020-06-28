#include<bits/stdc++.h>
using namespace std;
     
bool isvalid(vector<int> &nums,long long  m,long long  sum){
long long  count=1;

long long  temp=0;
for(long long  i=0;i<nums.size();i++){
    if(temp+nums[i]>sum){
        temp=0;
        count++;
    }
    temp+=nums[i];
}

return count<=m;
}


long long  splitArray(vector<int>& nums, long long  m) {
long long  low=INT_MIN;
long long  high=0;

for(long long  i=0;i<nums.size();i++){
high+=nums[i];
low=max(low,(long long)nums[i]);
}

long long  ans=-1;
while(low<=high){
    long long  mid=low+(high-low)/2;

    if(isvalid(nums,m,mid)){
        ans=mid;
        high=mid-1;
    }
    else{
        low=mid+1;
    }
}

return ans;
}

int  main(){


}