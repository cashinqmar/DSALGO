#include<bits/stdc++.h>
using namespace std;

// int findMaxDiff(int v[], int n)
// {

//     int d = -1;
//     stack<int> st;
    
//     for(int i=0; i<n; i++)
//     {
//         if(st.empty()||v[st.top()]<v[i])
//         {
//             st.push(i);
//         }
        
//         else if(v[st.top()]>v[i])
//         {
//             while(!st.empty() && v[st.top()]>v[i])
//             {
//                 int a = v[i];
//                 st.pop();
//                 int b=0;
               
//                 if(!st.empty())
//                     b = v[st.top()];
//                 int c= abs(a-b);
//                 d= max(d,c);
//             }
//             st.push(i);
//         }
//     }
    
//     while(!st.empty())
//     {
//         st.pop();
//         int c=0;
//         if(!st.empty())
//          c= v[st.top()];
        
//         d= max(d,c);
        
//     }
//     return d;
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n=7;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        
        stack<int> st;
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
          while(!st.empty()&&st.top()>arr[i]){
             st.pop();
             if(!st.empty())
             ans=max(ans,abs(arr[i]-st.top()));
             else ans=max(ans,abs(arr[i]));
          }
          if(st.size()==0||st.top()<arr[i]){
              st.push(arr[i]);
          }
         
        }
        while(!st.empty()){
        st.pop();
        int c=0;
        if(!st.empty())
         c= st.top();
        ans= max(ans,abs(c));
        }
       cout<<ans<<"\n";
    }

}