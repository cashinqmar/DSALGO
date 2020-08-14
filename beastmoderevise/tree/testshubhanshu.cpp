#include<bits/stdc++.h>
#define int        long long
#define MOD        1000000007
#define MAX        100005
#define pb         push_back
#define mp         make_pair
#define pii        pair<int,int>
#define mii        map<int,int>
#define vi         vector<int>
#define ff         first
#define ss         second
#define T          int t;cin>>t;while(t--)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define umi        unordered_map<int,int>
#define maxheap    priority_queue<int>
#define minheap    priority_queue<int,vector<int>,greater<int> >
#define inp(n)     for(int i=0;i<n;i++)
#define N          200005
#define mxN           2000005
#define all(v)        v.begin(),v.end()
#define lb(v,val)  (int)(lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (int)(upper_bound(v.begin(),v.end(),val)-v.begin())
#define debug(x) cout << #x << " = " << x << '\n';
using namespace std;
using namespace std::chrono;

void solve(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int x,y;
    cin >> x >> y;
    int n = s1.length(),m = s2.length();
    int dp[n+1][m+1] = {};

    for(int i=1;i<=m;i++){
        dp[0][i] = i*x;
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = i*x;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans = INT_MAX;
            if(s1[i-1]==s2[j-1])
                ans = dp[i-1][j-1];
            else ans = dp[i-1][j-1] + y;
            ans = min(ans,min(dp[i-1][j],dp[i][j-1])+x);
            dp[i][j] = ans;
        }
    }

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<' ';
        cout << '\n';

    }*/

    cout << dp[n][m] << '\n';

}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; 
    //cin >> t;
    while(t--){
    solve(); 
    }
}