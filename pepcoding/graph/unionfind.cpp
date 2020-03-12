#include<bits/stdc++.h>
using namespace std;

vector<int> v(26);

int findParent(int u)
{
    if (v[u] == u)
        return u;

    int p = findParent(v[u]);
    v[u] = p; //compression.
    return p;
}


void solve(){
    for(int i=0;i<26;i++)v[i]=i;

string s1,s2,s3;
cin>>s1>>s2>>s3;

int l=s1.size();
for(int i=0;i<l;i++){
int p1=findParent(s1[i]-'a');
int p2=findParent(s2[i]-'a');

v[p1]=min(p1,p2);
v[p2]=min(p1,p2);
}
l=s3.size();
for(int i=0;i<s3.size();i++ ){
    int p=findParent(s3[i]-'a');
    cout<<(char)(p+'a');
}


}

int main(){
solve();
return 0;
}

