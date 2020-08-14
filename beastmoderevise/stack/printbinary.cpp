#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        string s="1";
        queue<string> q;
        q.push(s);
        while(!q.empty()){
            string temp=q.front();
            q.pop();
            count++;
            cout<<temp<<" ";
            if(count==n)break;
            q.push(temp+"0");
            q.push(temp+"1");

        }
        cout<<"\n";
    }
}