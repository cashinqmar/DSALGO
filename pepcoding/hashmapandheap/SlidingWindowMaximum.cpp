#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> leftmax(n,0);
    vector<int> rightmax(n,0);

    for(int i=0;i<n;i++){
        if(i%k==0){
            leftmax[i]=nums[i];
        }
        else
        {
            leftmax[i]=max(leftmax[i-1],nums[i]);
        }
    }
    rightmax[n-1]=nums[n-1];

       for(int i=n-1;i>=0;i--){
        if((i+1)%k==0){
            rightmax[i]=nums[i];
        }
        else
        {
            rightmax[i]=max(rightmax[i+1],nums[i]);
        }
    }

    vector<int> ans;
    for(int i=0;i<nums.size()-k+1;i++)ans.push_back(max(leftmax[i],rightmax[i+k-1]));
    
    return ans;
}


int main(){

}