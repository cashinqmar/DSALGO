#include<bits/stdc++.h>
using namespace std;

void nsol(vector<int>& arr){
    stack<int> st;
    int l=arr.size();
    vector<int> ans(l,0);
    for(int i=l-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>arr[i]){
              int x=st.top();st.pop();
            ans[x]=arr[i];
            }
            st.push(i);
}
while(!st.empty()){
    ans[st.top()]=-1;st.pop();
}
    for(auto i:ans)cout<<i<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    nsol(arr);
}