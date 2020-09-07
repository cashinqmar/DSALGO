#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool ans=true;
    int i=0;
    int ones=0;
    int zeros=0;
    int uk=0;
    if(k%2==1){
        cout<<"NO"<<"\n";
        return;
    }
    for(int i=0;i<k;i++){
        if(s[i]=='0')zeros++;
        if(s[i]=='1')ones++;
        if(s[i]=='?')uk++;
    }

    if(ones>k/2||zeros>k/2){
        cout<<"NO"<<"\n";
        return;
    }

    for( i=k;i<n-k+1;i++){
        char ch=s[i-k];
        if(s[i-k]=='?'){
            s[i-k]=s[i];
        }
        else if(s[i]=='?'){
            s[i]=s[i-k];
        }
    }

        zeros=0;
        ones=0;
        uk=0;
     for(i=0;i<k;i++){
        if(s[i]=='0')zeros++;
        if(s[i]=='1')ones++;
        if(s[i]=='?')uk++;
    }


int temp=ones-zeros;
    
    for( i=k;i<n-k+1;i++){
        if(s[i-k]=='0'){
            zeros--;
        }
        if(s[i-k]=='1'){
                ones--;
        }
        if(s[i]=='0'){
            zeros++;
        }
        if(s[i]=='1'){
            ones++;
        }
         if(s[i-k]=='?'){
            uk--;
        }
        if(s[i]=='?'){
            uk++;
        }

        // if(s[i]=='?'){
        //     if(ones>zeros){
        //         s[i]==0;
        //         zeros++;
        //     }
        //     else {s[i]==1;
        //         ones++;
        //     }
        // }

        if(temp==ones-zeros){
            continue;
        }
        else { 
            ans=false;
            break;
        }
    }

    if(ans)cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}