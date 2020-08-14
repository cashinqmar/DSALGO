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

        int i=0;int j=0;
        int k=0;
        while(arr[k]==0)k++;
        i=k;
        j=k;
        k=n-1;
        while(arr[k]==2)k--;

        while(j<=k){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else if(arr[j]==2){
                  swap(arr[j],arr[k]);
                k--;
                j++;
            }
            else{
                j++;
            }
        }
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
}