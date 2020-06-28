#include<bits/stdc++.h>
using namespace std;


// memory consuming solution
// int trap(vector<int>& height) {
// int n=height.size();
// vector<int> leftmax(n,0);
// vector<int> rightmax(n,0);
// leftmax[0]=height[0];
// for(int i=1;i<height.size();i++){
//     leftmax[i]=max(leftmax[i-1],height[i]);
// }

// rightmax[height.size()-1]=height[height.size()-1];
// for(int i=height.size()-2;i>=0;i--){
//     rightmax[i]=max(rightmax[i+1],height[i]);
// }

// int ans=0;

// for(int i=0;i<n;i++){
// int sum=min(leftmax[i],rightmax[i])-height[i];
// if(sum>0)ans+=sum;
// }
// return ans;
// }

// constant memory solution
int trap(vector<int>& height) {
int leftmax=height[0];
int rightmax=height[height.size()-1];

int i=0;
int j=height.size()-1;

int ans=0;

while(i<=j){

if(height[i]<height[j]){
    if(leftmax<height[i]){
        leftmax=height[i];
    }
    else
    {
        ans+=leftmax-height[i];
    }
    i++;
}
else{
      if(rightmax<height[i]){
        rightmax=height[i];
    }
    else
    {
        ans+=rightmax-height[i];
    }
    j--;

}
}
return ans;
}

int main(){

}