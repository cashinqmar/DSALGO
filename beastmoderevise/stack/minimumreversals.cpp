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
            if(s[i]=='{')st.push('{');
            else if(s[i]=='}'){
                if(st.size()!=0&&st.top()=='{')st.pop();
                else st.push('}');
        }
    }

    int oc=0;
    int cc=0;
    while(!st.empty()){
        if(st.top()=='{')oc++;
        else cc++;
        st.pop();
    }

    if(oc%2==0&&cc%2==1)cout<<"-1"; 
    else if(oc%2==1&&cc%2==0)cout<<"-1"; 
    else if(oc%2==0&&cc%2==0)cout<<oc/2+cc/2;
    else if(oc%2==1&&cc%2==1)cout<<oc/2+cc/2+2;

    cout<<"\n";
}
}