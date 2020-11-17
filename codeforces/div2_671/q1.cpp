#include<bits/stdc++.h>
using namespace std;

 string cutst(string s)
{
    int l=s.length();
    int i=0;
    
    while(s[i]!='\0')
    {
        if(s[i]==s[i+1])
        s.erase(i,1);
        
        else
        {i++;
    }
    }
    return s;
}


int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    s=cutst(s);
    cout<<s<<"\n";
}
}