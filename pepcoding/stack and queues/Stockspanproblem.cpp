#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)cin>>arr[i];
        
        stack<int> st;
        vector<int> ans(n,1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                int x=st.top();
                ans[x]=x-i;
                st.pop();
            }
            st.push(i);
        }
 
 while(!st.empty()){
           int x=st.top();
                ans[x]=x+1;
                st.pop();
 }
        for(auto i:ans)cout<<i<<" ";
        cout<<"\n";

    }
}