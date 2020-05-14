#include<bits/stdc++.h>
using namespace std;

#define m 1000000007
int main(){
    int t;
    cin>>t;
    while(t--){
       priority_queue<long long int> pq;
       int n;cin>>n;
       for(int i=0;i<n;i++){
           int x;
           cin>>x;
        pq.push(x);
       }

       long long profit=0;
      int ctr=0;
       while(!pq.empty()&&pq.top()!=0){
           
           long long int x=pq.top();
           pq.pop(); 
           if((((x)%m-ctr)%m)<=0)break;

          profit=(profit%m+(x)%m-ctr)%m;
        //   cout<<profit<<" ";
          ctr++;
       }
cout<<profit<<'\n';

    }
}