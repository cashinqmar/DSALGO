#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

       vector<vector<int>> arr(n,vector<int>(k,0));
       int x;
       for(int i=0;i<n;i++){
           for(int j=0;j<k;j++){
               cin>>x;
               arr[i][j]=x;
           }
       }
      int i=0;
     
       while(i<n){
           for(int j=0;j<k;j++){
               if(i%k==j)cout<<arr[i][j]<<" ";
           }
           i++;
       }
    }
}