#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {

    vector<int> leftmax(height.size());
    vector<int> rightmax(height.size());

    int n=height.size();
    for(int i=0;i<n;i++){
        if(i==0)leftmax[i]=height[i];   
        else leftmax[i]=max(leftmax[i-1],height[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1)rightmax[i]=height[i];   
   else rightmax[i]=max(rightmax[i+1],height[i]);
   }

   int ans=0;
   for(int i=0;i<n;i++){
      if(min(leftmax[i],rightmax[i])-height[i]>=0)ans+=min(leftmax[i],rightmax[i])-height[i];
   }
return ans;
}
int main(){

}