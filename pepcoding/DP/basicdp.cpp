#include <bits/stdc++.h>
using namespace std;

int fib01(int n)
{
    if (n <= 1)
        return n;
    int ans = fib01(n - 1) + fib01(n - 2);
    return ans;
}

int fib02(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        dp[n] = n;
        return n;
    }
    int ans = fib01(n - 1) + fib01(n - 2);
    return dp[n] = ans;
}

int fib03(int n, vector<int> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = i;
        }
        else
        {
            int ans = dp[i - 1] + dp[i - 2];
            dp[i] = ans;
        }
    }
    return dp[n];
}

int fib04(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;
    int a = 1;
    int b = 1;
    int ans;
    for (int i = 3; i <= n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}

vector<vector<int>> multiplication(vector<vector<int>> a, vector<vector<int>> b)
{

    vector<vector<int>> ans(2, vector<int>(2, 0));
    ans[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1] [0];
    ans[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][ 1];
    ans[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][ 0];
    ans[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][ 1];
    return ans;
}

vector<vector<int>> fiblogn(vector<vector<int>> mat, int n)
{

    if (n == 1) return mat;
    vector<vector<int>> rec=fiblogn(mat,n/2);
    vector<vector<int>> ans=multiplication(rec,rec);
    return n&1?multiplication(mat,ans):ans;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, 0);

    // cout<<fib02(n,dp);
    vector<vector<int>> mat={{1,1},{1,0}};
    vector<vector<int>> ans=fiblogn(mat,n);
    cout <<ans[0][1];
}