#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char,int> freq;
    unordered_map<char,vector<int>> idx;

    for(int i=0;i<s.size();i++){
        freq[s[i]]++;
        idx[s[i]].push_back(i);
    }

    for(pair<char,int> key:freq){
        cout<<key.first<<" "<<key.second<<"\n";
    }

    cout<<"\n";
    
    for(pair<char,vector<int>> key:idx){
        cout<<key.first<<" ";
       for(int i=0;i<key.second.size();i++){
           cout<<key.second[i]<<" ";
       }
       cout<<"\n";
    }

}