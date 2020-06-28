#include<bits/stdc++.h>
using namespace std;

void downheapify(vector<int> &arr,int pi,int ei){
    int lc=pi*2+1;
    int rc=pi*2+2;
    int maxi=pi;
    if(lc<=ei&&arr[lc]>arr[maxi]){
        maxi=lc;
     }
    if(rc<=ei&&arr[rc]>arr[maxi]){
        maxi=rc;
    }

    if(maxi!=pi){
        swap(arr[pi],arr[maxi]);
        downheapify(arr,maxi,ei);
    }
}

void heapsort(vector<int> &arr,int si,int ei){
    if(si>ei)return;
    swap(arr[si],arr[ei]);
    downheapify(arr,si,ei-1);
    heapsort(arr,si,ei-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=arr.size()-1;i>=0;i--)downheapify(arr,i,n-1);

    heapsort(arr,0,n-1);

    for(auto i:arr)cout<<i<<" ";
}