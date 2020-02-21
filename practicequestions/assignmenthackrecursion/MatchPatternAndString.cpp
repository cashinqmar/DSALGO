#include<bits/stdc++.h>
using namespace std;

bool utility(string str,int n,int i,string pat,int m,int j,map<char,string> &map){
    if(i==n&&j==m){
for (auto it = map.begin(); it != map.end(); it++) 
        cout << it->first << "->" << it->second << endl; 
return true;
    }

    if(i==n||j==m)return false;

        bool res=false;

    char ch=pat[j];
    if(map.find(ch)!=map.end()){
        string s=map[ch];
        int len=s.size();
        if(s==str.substr(i,len)){
            res= utility(str,n,i+len,pat,m,j+1,map);
        }
    }
else{
    for(int k=1;k<=n-i;k++){
   map[ch]=str.substr(i,k);
   res=(utility(str,n,i+k,pat,m,j+1,map));
   map.erase(ch);
   res=false;
    }
}
return res;
}

bool patternMatch(string str, string pat, int n, int m) 
{ 
    if (n < m) 
    return false; 
  
    // create an empty hashmap 
    map<char, string> map; 
  
    // store result in a boolean variable res 
    bool res =utility(str, n, 0, pat, m, 0, map); 
  
    // if solution exists, print the mappings
    // return result 
    
    return res; 
} 
void solve(){
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.size();
    int m=str2.size();
    patternMatch(str1,str2,n,m);
    
}
int main(){
    solve();
    return 0;
}