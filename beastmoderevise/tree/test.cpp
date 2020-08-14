 #include <bits/stdc++.h> 
using namespace std; 


int helper(string x,string y,int s1,int s2,int pgap,int pxy,vector<vector<int>> &dp){

if(s1==x.size()){
    return dp[s1][s2]=(y.size()-s2)*pgap;
}

if(s2==y.size()){
    return dp[s1][s2]=(x.size()-s1)*pgap;
}

if(dp[s1][s2]!=INT_MAX){
    return dp[s1][s2];
}

int res1=0,res2=0,res3=0;

if(x[s1]!=x[s2]){
    res1+=pxy;
}

res1+=helper(x,y,s1+1,s2+1,pgap,pxy,dp);
res2+=pgap+helper(x,y,s1,s2+1,pgap,pxy,dp);
res3+=helper(x,y,s1+1,s2,pgap,pxy,dp);

int count=min(res1,min(res2,res3));
return dp[s1][s2]+=count;

}
int getMinimumPenalty(string x,string y,int pgap,int pxy)  // x and y are given input strings. pgap and pxy are given mismatch scores.
{
    int res=0;
    
    vector<vector<int>> dp(x.size()+1,vector<int>(y.size()+1,INT_MAX));
    // WRITE YOUR CODE HERE
   res= helper(x,y,0,0,pgap,pxy,dp);
    return res;
}

int main()
{
    string gene1,gene2;
    int gapPenalty,misMatchPenalty;
    cin>>gene1>>gene2;
    cin>>gapPenalty;
    cin>>misMatchPenalty;
    cout<<getMinimumPenalty(gene1, gene2, gapPenalty, misMatchPenalty);
}
