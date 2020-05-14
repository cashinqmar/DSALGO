#include<bits/stdc++.h>
using namespace std;

int  longestpalindromicsubstringtabulation(string str){
    int l=str.size();
    vector<vector<int>> dp(l,vector<int>(l,0));

int maxm=1;
    for(int gap=0;gap<str.size();gap++){
        for(int si=0,ei=gap;ei<str.size();si++,ei++){
            if(gap==0)dp[si][ei]=1;
            else if(str[si]==str[ei]&&gap==1)dp[si][ei]=2;
            else if(str[si]==str[ei]&&dp[si+1][ei-1]!=0){
                dp[si][ei]=dp[si+1][ei-1]+2;
            }
          maxm=max(maxm,dp[si][ei]);
        }
    }
    return maxm;
}

void ispalindrome(string str,vector<vector<bool>> &dp){
     for(int gap=0;gap<str.size();gap++){
        for(int si=0,ei=gap;ei<str.size();si++,ei++){
            if(gap==0)dp[si][ei]=true;
            else if(str[si]==str[ei]&&gap==1)dp[si][ei]=true;
            else if(str[si]==str[ei]&&dp[si+1][ei-1]){
                dp[si][ei]=true;
            }
        }
    }
}

int longestpalindromicsubstringrecusrsion(string str,int si,int ei,vector<vector<bool>> &dp){
    if(si>ei)return 0;
    if(si==ei)return 1;
    
    int count=1;

    if(str[si]==str[ei]){
        if(dp[si+1][ei-1])return ei-si+1;
        else count=max(count,longestpalindromicsubstringrecusrsion(str,si+1,ei-1,dp));
    }

    else {
        count=max(count,longestpalindromicsubstringrecusrsion(str,si+1,ei,dp));
        count=max(count,longestpalindromicsubstringrecusrsion(str,si,ei-1,dp));
    }

return count;

}

int main(){
    string s;
    cin>>s;

       int l=s.size();
    vector<vector<bool>> dp(l,vector<bool>(l,false));
   
    cout<<longestpalindromicsubstringtabulation(s)<<" ";
    ispalindrome(s,dp);
    cout<<longestpalindromicsubstringrecusrsion(s,0,l-1,dp);
}
