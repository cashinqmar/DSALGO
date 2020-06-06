#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        int count=1;
        queue<string> q;
        q.push("1");
        while(1){
            int t=q.size();
            while(t--){
               if(count>n)break;
               string temp=q.front();
               q.pop();
               cout<<temp<<" ";
               count++;
               q.push(temp+"0");
               q.push(temp+"1");
            }
             if(count>n)break;
        }
        cout<<"\n";
    }
    
}