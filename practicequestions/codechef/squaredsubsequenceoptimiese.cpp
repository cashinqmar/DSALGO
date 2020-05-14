#include<bits/stdc++.h>
using namespace std;


bool check(long long a){
    if(a&1){
  return true;
    }
   if(a%4==0)return true;

   return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
       long long   int n;
        cin>>n;



        vector<long long int> arr(n);
        vector<long long int>next2(n,n);
        vector<long long int>next4(n,n);
        vector<long long int>game4(n,n);
        long long int x;
        for(int i=0;i<n;i++){
            cin>>x;
            arr[i]=x;
        }
        for(int i=n-1;i>=1;i--){
            if(arr[i]%2==0){
            next2[i-1]=i;
            }
            else{if(i!=n-1)
                next2[i-1]=next2[i];
            }
        }

//         for(int i=n-1;i>=0;i--){
//             if(arr[i]%4==0){
//             next4[i]=i;
//             }
//             else{
//                 if(i!=n-1)
//                 next4[i]=next4[i+1];
//             }
//         }

//         long long int prod=1;
//        for(int i=n-1;i>=0;i--){
//            prod*=arr[i];
//             if(prod%4==0){
//             game4[i]=i;
//             }
//             else{if(i!=n-1)
//                 game4[i]=game4[i+1];
//             }
//         }


  cout<<"next2";
  for(auto i:next2)cout<<i<<" ";
// //   cout<<"next4";
// //   for(auto i:next4)cout<<i<<" ";


      long long count=0;
        for(long long int i=0;i<n;i++){
          if(arr[i]%2==1){
              int a=next2[i];
             {
                 
             if(arr[a]%4==0) {
                 count+=a-i+n-a;
            }
            else if(a{
                count+=a-i+n-next2[a];
            }
             }
             else count++;
          }
          else if(arr[i]%4==0){
              count+=n-i;
          }
          else{
              if(i!=n-1)
              count+=n-next2[i];
                //  cout<<count<<"\n";
          }
        }
         cout<<count<<"\n";
    }
}