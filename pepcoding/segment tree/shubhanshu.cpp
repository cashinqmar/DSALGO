#include<bits/stdc++.h>
using namespace std;

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     int n=nums.size();
//     vector<int> leftmax(n,0);
//     vector<int> rightmax(n,0);

//     for(int i=0;i<n;i++){
//         if(i%k==0){
//             leftmax[i]=nums[i];
//         }
//         else
//         {
//             leftmax[i]=max(leftmax[i-1],nums[i]);
//         }
//     }
//      rightmax[n-1]=nums[n-1];
    
//        for(int i=n-1;i>=0;i--){
//         if((i+1)%k==0||(i==n-1)){
//             rightmax[i]=nums[i];
//         }
//         else
//         {
//             rightmax[i]=max(rightmax[i+1],nums[i]);
//         }
//     }
//     vector<int> ans;
//     for(int i=0;i<nums.size()-k+1;i++)ans.push_back(max(rightmax[i],leftmax[i+k-1]));
    
//     return ans;
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>k>>m;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            
            vector<int> nums=matrix[i];
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
        if((i+1)%k==0||(i==n-1)){
            rightmax[i]=nums[i];
        }
        else
        {
            rightmax[i]=max(rightmax[i+1],nums[i]);
        }
    }
    vector<int> ans;
    for(int i=0;i<nums.size()-k+1;i++)ans.push_back(max(rightmax[i],leftmax[i+k-1]));
    
    matrix[i].resize(n-k+1);/*yaha change*/
    matrix[i]=ans;
    }
       vector<int> arr;
       int i=0;
       while(i<n-k+1){/*yaha change*/
       for(int j=0;j<n-k+1;j++){/*yaha change*/
           int final=INT_MIN;
            for(int z=i;z<i+k;z++){
                final=max(final,matrix[z][j]);
            }
            if(final>=m)
            arr.push_back(final);
       }
       i++;
       }

    sort(arr.begin(),arr.end());

    cout<<arr.size()<<" "<<arr[0]<<" "<<arr[arr.size()-1]<<"\n";

   }
}