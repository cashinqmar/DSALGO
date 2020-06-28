#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }

        int even=0;
        int odd=0;
        for(auto i:m){
            if(i.second%2==0)even++;
            else odd++;
        }
        if(even==m.size()||odd==1){
            cout<<"Yes"<<"\n";
        }
        else cout<<"No"<<"\n";
    }
}