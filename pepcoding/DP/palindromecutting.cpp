  #include<bits/stdc++.h>
  using namespace std;

  
  int helper(string &s,int st,int end,vector<vector<int>> &dp,vector<vector<bool>> &ispalindrome){
        if(st==end||ispalindrome[st][end])return dp[st][end]=0;
        if(dp[st][end]!=-1)return dp[st][end];
        
        int min_=INT_MAX;
        for(int cut=st;cut<end;cut++){
            int left=helper(s,st,cut,dp,ispalindrome);
            int right=helper(s,cut+1,end,dp,ispalindrome);
            min_=min(min_,left+right+1);
        }
        return dp[st][end]=min_;
    }
    int minCut(string &s){
        int l=s.size();
        if(l==0||l==1)return 0;
        vector<vector<int>> dp(l,vector<int>(l,-1));
        vector<vector<bool>> ispalindrome(l,vector<bool>(l,false));
        
        for(int gap=0;gap<l;gap++){
            for(int st=0,end=gap;end<l;st++,end++){
                if(gap==0)ispalindrome[st][end]=true;
              else  if(gap==1&&s[st]==s[end])ispalindrome[st][end]=true;
              else  if((s[st]==s[end])&&ispalindrome[st+1][end-1])ispalindrome[st][end]=true;
            }
        }
        
        return helper(s,0,l-1,dp,ispalindrome);
        
        
    }

    int main(){
        string s;
        cin>>s;
        cout<<minCut(s);
    }