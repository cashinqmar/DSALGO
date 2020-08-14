#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;

        vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,0)));

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                for(int k=n3-1;k>=0;k--){
                    int count=0;
                    if((s1[i]==s2[j])&&(s2[j]==s3[k])){
                        count=1;
                        if(i+1<n1&&j+1<n2&&k+1<n3){
                        count+=dp[i+1][j+1][k+1];
                        }
                    }
                    else{
                         if(i+1<n1){
                             count=max(count,dp[i+1][j][k]);
                         }
                          if(j+1<n2){
                               count=max(count,dp[i][j+1][k]);
                          }
                           if(k+1<n3){
                                count=max(count,dp[i][j][k+1]);
                           }
                    }
                    dp[i][j][k]=count;
                }
            }
        }

        cout<<dp[0][0][0]<<"\n";
    }
}