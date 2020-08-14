#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
unordered_map<char,int> m;
for(int i=0;i<s.size();i++){
    m[s[i]]++;
}

stack<char> st;
vector<int> visited(26,false);
for(int i=0;i<s.size();i++){

if(visited[s[i]-'0']==false){

while(st.size()!=0&&st.top()>s[i]){
    if(m[st.top()]==1){
        break;
    }
    else{
        visited[st.top()-'0']=false;
        st.pop();
    }
}
st.push(s[i]);
visited[s[i]-'0']=true;
}
m[s[i]]--;

}

string ans;
while(st.size()!=0){
    ans.push_back(st.top());
    st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
}

int main(){

}