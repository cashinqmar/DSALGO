#include<bits/stdc++.h>
using namespace std;


bool check(vector<long long > &arr,long long k,long long s){

vector<long long > sample(arr.size());
for(long long int i=0;i<sample.size();i++){
    sample[i]=arr[i]+(i+1)*k;
}
 if (sample.size()< k) { 
        return INT_MAX; 
    } 
  
    // Compute sum of first window of size k 
    int max_sum = 0; 
    for (int i = 0; i < k; i++) 
        max_sum += sample[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of 
    // current window. 
    int window_sum = max_sum; 
    if(s>=window_sum)return true;
    for (int i = k; i < sample.size(); i++) { 
        window_sum += arr[i] - arr[i - k]; 
       if(s>=window_sum)return true;
    }
  return false;
}

int  main(){
long long  n,s;
cin>>n>>s;
vector<long long > e(n);
for(long long  i=0;i<n;i++){
    cin>>e[i];
}

long long max_sum=0;
vector<long long > sample(e.size());
for(long long int i=0;i<sample.size();i++){
    sample[i]=e[i]+(i+1)*n;
      max_sum += sample[i]; 
}

if(s>=max_sum)cout<<n;
else{
long long  ans=0;

long long  low=0;
long long  high=n;
while(low<high){
    long long int mid=(low+high)/2;
    
    if(check(e,mid,s)){
        ans=max(ans,mid);
        low=mid+1;
    }
    else {
        high=mid;
    }
}
cout<<ans;

}
}