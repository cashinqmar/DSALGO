#include<bits/stdc++.h>
using namespace std;

int funct(vector<int> &arr){
stack<int> st;
int ans=INT_MIN;
st.push(-1);

int n=arr.size();

for(int i=0;i<n;i++){
    while(st.top()!=-1&&arr[st.top()]>arr[i]){
        int x=st.top();st.pop();
        ans=max(ans,(i-st.top()-1)*arr[x]);
    }
    st.push(i);
}

while(st.top()!=-1){
     int x=st.top();st.pop();
        ans=max(ans,(n-st.top()-1)*arr[x]);
}

return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> arr(matrix[0].size(),0);
    int ans=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]=='1')arr[j]++;
            else arr[j]=0;
        }
        ans=max(ans,funct(arr));
    }

    return ans;
}