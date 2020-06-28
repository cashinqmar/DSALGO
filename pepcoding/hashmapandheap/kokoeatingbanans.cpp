#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> &nums,long long  k,long long  H){
long long  count=0;

long long  temp=0;
for(long long  i=0;i<nums.size();i++){
   count+=ceil(nums[i]/k);
}

return count<=H;
}
int minEatingSpeed(vector<int>& piles, int H) {
int low=1;

int high=INT_MIN;

for(int i=0;i<piles.size();i++){
    high=max(high,piles[i]);
}
int ans=-1;
while(low<=high){
    int mid=(low+high)/2;

    if(isvalid(piles,mid,H)){
        high=mid-1;
        ans=mid;
    }
    else{
        low=mid+1;
    }
}
return ans;
}


int main(){
    
}