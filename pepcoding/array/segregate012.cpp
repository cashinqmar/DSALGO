#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    
        int i=0;int j=0;
        int k=0;
         while(k<arr.size()&&arr[k]==0)k++;
         i=k;
         j=k;

         k=n-1;
         while(k>=0&&arr[k]==2)k--;
        
        while(j<=k){
          if(arr[j]==0){
              swap(arr[i],arr[j]);
              i++;
              j++;
          }
          else if(arr[j]==2){
             swap(arr[j],arr[k]);
             k--;
          }
          else{
              j++;
          }

        }

        for(auto i:arr)cout<<i<<" ";
        cout<<"\n";
    }
}