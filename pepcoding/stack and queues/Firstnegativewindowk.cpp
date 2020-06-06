#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        cin>>k;
       
        vector<int> ans(n-k+1);
        int first=-1;
        for(int i=n-1;i>=0;i--){
           if(arr[i]<0)first=i;
           if(i<n-k+1){
               if(first>=i&&first<=i+k-1){
                   ans[i]=arr[first];
               }
               else{
                   ans[i]=0;
               }
           }
        }
        for(auto i:ans)cout<<i<<" ";
        cout<<"\n";
    }
}