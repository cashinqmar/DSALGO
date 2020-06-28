#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int num,den;
        cin>>num>>den;
        if(num%den==0)cout<<num/den<<"\n";
        else{
            string ans=to_string(num/den);
            unordered_map<int,int> m;
            int count=0;
            int rem=num%den;
            m[rem]=count++;
            string str;
            bool flag=false;
            int start;
            while(1){
                rem*=10;
                int q=rem/den;
                rem=rem%den;
                str=str+to_string(q);
                  if(rem==0){
                    flag=true;
                    break;
                }
                if(m.find(rem)!=m.end()){
                    start=m[rem];
                    break;
                }
               
                m[rem]=count++;
            }

           
            if(flag){
                ans=ans+"."+str;
            }
            else ans=ans+"."+str.substr(0,start)+"("+str.substr(start)+")";
            cout<<ans<<"\n";
        }
    }
}