#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<long long int> st;
    for(int i=0;i<n;i++){

        if(!st.empty()&&st.top()>0&&arr[i]<0){
          long long int x=st.top();
            st.pop();
            long long int temp=x+arr[i];
            st.push(temp);
        }

        else if(!st.empty()&&st.top()>0&&arr[i]>0){
          long long int x=st.top();
            st.pop();
            long long int temp=x+arr[i];
            st.push(temp);
        }
    
        else st.push(arr[i]);
    }

    long long sum=0;
    while(st.size()!=0){
        if(st.top()<0)sum+=abs(st.top());
        st.pop();
    }

  cout<<sum<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}