#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
unordered_map<char,int> m;

int i=0;
int j=0;
bool flag=false;

int ans=0;
while(j<s.size()){
    m[s[j]]++;
    if(m[s[j]]>1){
        flag =true;
    }
    j++;

    if(!flag){
    ans=max(ans,j-i);
    }

    while(flag){
        m[s[i]]--;
        if(m[s[i]]==1){
            flag=false;
        }
        i++;   
    } 
}
return ans;
}

int main(){
string s;
cin>>s;
cout<<lengthOfLongestSubstring(s);
}