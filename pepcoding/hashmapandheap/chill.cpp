#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int i,int ei){
    int lci=i*2+1;
    int rci=i*2+2;
    int maxi=i;

    if(lci<=ei&&arr[lci]>arr[maxi]){
        maxi=lci;
    }
    if(rci<=ei&&arr[rci]>arr[maxi]){
        maxi=rci;
    }
    if(maxi!=i){
         swap(arr[i],arr[maxi]);
        heapify(arr,maxi,ei);
    }
}


void heapsort(vector<int> &arr,int si,int ei){
if(si>ei)return;
swap(arr[si],arr[ei]);
heapify(arr,si,ei-1);
heapsort(arr,si,ei-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=n-1;i>=0;i--){
        heapify(arr,i,n-1);
    }

    heapsort(arr,0,n-1);
    
    for(auto i:arr)cout<<i<<" ";
}