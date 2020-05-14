#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(100001,0);
        vector<int> arrk(100001,0);
        vector<int> arrk1(100001,0);
        vector<pair<int,int>> query(n);

        int x,y;
        for(int i=0;i<n;i++){
          cin>>x>>y;
          query[i]={x,y};
          arr[x]+=1;
          if(y+1<=100000)arr[y+1]-=1;
        }
        for(int i=1;i<100001;i++){
            arr[i]+=arr[i-1];
        }

        if(arr[0]==k)arrk[0]++;
       for(int i=1;i<100001;i++){
            arrk[i]+=arrk[i-1];
            if(arr[i]==k)arrk[i]++;
        }

         if(arr[0]==k+1)arrk1[0]++;
       for(int i=1;i<100001;i++){
            arrk1[i]+=arrk1[i-1];
            if(arr[i]==k+1)arrk1[i]++;
        }
int ans=0;
       for(int i=0;i<n;i++){
           int count=arrk[100000];
           int x=query[i].first;
           int y=query[i].second;

           int k=arrk[y];
           int k1=arrk1[y];
           if(x-1>=0){
               k=k-arrk[x-1];
               k1=k1-arrk1[x-1];
           }
ans=max(ans,count-k+k1);
       }
       cout<<ans<<"\n";
}
}