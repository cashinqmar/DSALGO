#include<bits/stdc++.h>
using namespace std;


int binary_search(vector<int> &arr,int si,int ei,int target){

    if(si<=ei){

    int mid=(si+ei)/2;

    if(target==arr[mid])return mid;

    if(target>arr[mid]){
        return binary_search(arr,mid+1,ei,target);
    }
    else  return binary_search(arr,si,mid-1,target);
    }
    return -1;
}

 int search(vector<int>& nums, int target) {


        int lo=0;
        int hi=nums.size()-1;
        int pivot=-1;

        while(lo<hi){
            int mid=lo+(hi-lo)/2;

            if(nums[mid]>nums[hi]){
                lo=mid+1;
            }
            else {
                hi=mid;
            }
        }
     pivot=lo;

    int ans=-1;
    ans=binary_search(nums,0,pivot-1,target);

    if(ans==-1){
        ans=binary_search(nums,pivot,nums.size()-1,target);
    }
     return ans;
}

int main(){
vector<int> arr={4,5,6,7,0,1,2};

cout<<search(arr,0);
}