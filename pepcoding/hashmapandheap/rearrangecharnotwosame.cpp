#include<bits/stdc++.h>
using namespace std;

string rearrange(string &s){
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }

    priority_queue<pair<int,char>>pq ;

    for(auto i:m){
        pq.push({i.second,i.first});
    }
    string ans="";

     pair<int,char> hold={-1,'a'};

    while(!pq.empty()){
        pair<int,char> temp=pq.top();pq.pop();
        ans+=temp.second;
        temp.first-=1;

       
        if(hold.first>0)pq.push(hold);
        hold=temp;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<int(s.size()==(rearrange(s)).size())<<"\n";
    }

}