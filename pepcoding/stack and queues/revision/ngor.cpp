#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &nums){
    vector<int> arr(nums.size(),-1);
    stack<int> st;
    for(int i=0;i<nums.size();i++){
        while(st.size()!=0&&(nums[st.top()]<nums[i])){
            arr[st.top()]=nums[i];
            st.pop();
        }

        st.push(i);
    }

    for(auto i:arr)cout<<i<<" ";
    cout<<"\n";
}

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    display(arr);
}
}