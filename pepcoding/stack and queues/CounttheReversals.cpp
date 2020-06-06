#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      stack<char> st;

      for(int i=0;i<s.size();i++){
          if(s[i]=='{'){
              st.push('{');
          }
          if(s[i]=='}'){
             if(st.size()!=0&&st.top()=='{')st.pop();
             else st.push('}');
          }
          
      }

      int oc=0;
      int cc=0;
      while(st.size()!=0&&st.top()!='}'){
        //   cout<<st.top()<<"\n";
          st.pop();
          oc++;
      }
       while(st.size()!=0){
            // cout<<st.top()<<"\n";
          st.pop();
          cc++;
      }
// cout<<"oc"<<oc<<" cc"<<cc<<'\n';
      if(oc%2==0&&cc%2==0){
          int ans=oc/2+cc/2;
          cout<<ans<<"\n";
      }
      else if(oc%2==1&&cc%2==1){
          int ans=oc/2+cc/2+2;
      }
      else cout<<"-1"<<"\n";
    }
}