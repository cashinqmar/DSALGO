 #include<bits/stdc++.h>
 using namespace std;
 
 int distinctSubseqII(string s) {
         vector<int> last(26,-1);
    vector<int> dp(s.size()+1,0);
    dp[0] =1;
    for(int i=1;i<dp.size();i++){
        dp[i]=dp[i-1]*2;
        int loc=s[i-1]-'a';
        // cout<<loc<<" ";
        int idx=last[loc];
        if(idx!=-1){
            dp[i]-=dp[idx-1];
        }
        last[loc]=i;
    }
        return dp[s.size()]-1;
    }


int main(){
    string s;
    cin>>s;
    cout<<distinctSubseqII(s)<<"\n";
}