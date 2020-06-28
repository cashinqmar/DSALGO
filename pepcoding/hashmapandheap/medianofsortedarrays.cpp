#include<bits/stdc++.h>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

if(nums2.size()<nums1.size())swap(nums1,nums2);
int gl=(nums1.size()+nums2.size()+1)/2;

int i=0;
int j=nums1.size();

while(i<=j){
    int mid1=(i+j)/2;
    int mid2=gl-mid1;

    int leftmax1,rightmin1,leftmax2,rightmin2;
// for mid1
    if(mid1==0){
        leftmax1=INT_MIN;
    }
    else{
        leftmax1=nums1[mid1-1];
    }

    if(mid1==nums1.size()){
        rightmin1=INT_MAX;
    }
    else{
        rightmin1=nums1[mid1];
    }

// for mid2
  if(mid2==0){
        leftmax2=INT_MIN;
    }
    else{
        leftmax2=nums2[mid2-1];
    }

    if(mid2==nums2.size()){
        rightmin2=INT_MAX;
    }
    else{
        rightmin2=nums2[mid2];
    }

if(leftmax1<=rightmin2&&leftmax2<=rightmin1){
    if((nums1.size()+nums2.size())%2==1){
        return (double)max(leftmax1,leftmax2);
    }
    else{
        return (double)(max( (double)leftmax1, (double)leftmax2)+min( (double)rightmin1, (double)rightmin2))/2;
    }
}

else if(leftmax1>rightmin2){
    j=mid1-1;
}
else{
    i=mid1+1;
}

}

}

int main(){

}