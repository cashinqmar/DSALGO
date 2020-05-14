#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        
        stack<int> st1,st2;
        vector<int> nsor(n,0);
        vector<int> nsol(n,0);

        for(int i=0;i<n;i++){
          while(!st1.empty()&&arr[st1.top()]>arr[i]){
              int x=st1.top();st1.pop();
              nsor[x]=arr[i];
          }
          st1.push(i);
        }

        for(int i=n-1;i>=0;i--){
          while(!st2.empty()&&arr[st2.top()]>arr[i]){
              int x=st2.top();st2.pop();
              nsol[x]=arr[i];
          }
          st2.push(i);
        }

        int ans=INT_MIN;

       for(int i=0;i<n;i++){
           ans=max(abs(nsor[i]-nsol[i]),ans);
       }
       cout<<ans<<"\n";
    }

}