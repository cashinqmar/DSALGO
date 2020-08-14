#include<bits/stdc++.h>
using namespace std;

void display(vector<long long int> &arr){
    vector<long long int> display(arr.size(),-1);

    stack<long long int> st;

    for(long long int i=0;i<arr.size();i++){

        while(!st.empty()&&arr[st.top()]<arr[i]){
            long long int x=st.top();
            st.pop();
            display[x]=arr[i];
        }

        st.push(i);
    }

    for(long long int i=0;i<arr.size();i++){
        cout<<display[i]<<" ";
    }
    cout<<"\n";

}
int main(){
    long long int t;
    cin>>t;

    while (t--)
    {
         long long int n;
        cin>>n;
        vector<long long int> arr(n,0);
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }

        display(arr);
    }
    
}