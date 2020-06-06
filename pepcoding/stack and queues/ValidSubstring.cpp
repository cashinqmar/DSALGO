#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      stack<int> st;
      st.push(-1);
      int ans=0;
      for(int i=0;i<s.size();i++){
          if(s[i]=='('){
              st.push(i);
          }
          if(s[i]==')'){
              if(st.top()!=-1&&s[st.top()]=='('){
                  st.pop();
                  ans=max(ans,i-st.top());
              }
              else st.push(i);
          }
      }
      cout<<ans<<"\n";
    }
}