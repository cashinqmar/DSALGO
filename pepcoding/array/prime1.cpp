#include<bits/stdc++.h>
using namespace std;
int p=100000;
vector<int> arr(p,true);

void sieve(){
    for(int i=2;i*i<p;i++){
        if(arr[i]==true){
           int  k=2*i;
            while(k<p){
                arr[k]=false;
                k+=i;
            }
        }
    }
}


void display(int m,int n){
    int k=n-m+1;
 vector<int> nums(k,true);

 for(int i=2;i*i<=n;i++){
     if(arr[i]==true){
         int j=m;

         if(j%i!=0){
             int k=j/i;
             j=(k+1)*i;
         }
         if(i==j){
             j+=i;
         }

         while(j<k+m){
            if(j%i==0)
             nums[j-m]=false;
             j+=i;
         }
     }
}

for(int i=0;i<k;i++){
    if(nums[i])cout<<i+m<<"\n";
}
}

int main(){
int t;
cin>>t;
sieve();
while(t--){
int m,n;
cin>>m>>n;
if(m==0||m==1)m=2;
display(m,n);
cout<<"\n";
}
}