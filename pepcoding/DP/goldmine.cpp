#include <bits/stdc++.h>
using namespace std;

// int total=INT_MIN;
// void helper(vector<vector<int>> &grid,int x,int y,int count,vector<vector<int>> &dp){

//     if(y==grid[0].size()-1){
//        total=max(total,count);

//        return;
//     }

//     if(y+1<grid[0].size()){
//        helper(grid,x,y+1,count+grid[x][y+1]);
//     }

//      if(y+1<grid[0].size()&&x-1>=0){
//        helper(grid,x,y+1,count+grid[x-1][y+1]);
//     }
//      if(y+1<grid[0].size()&&x+1<grid.size()){
//          helper(grid,x,y+1,count+grid[x+1][y+1]);
//     }

// }

bool isvalid(vector<vector<int>> &grid, int x, int y)
{
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
}

int goldminerec01(vector<vector<int>> grid, int sr, int sc, vector<vector<int>> &dp)
{
    if (sr < 0 || sr >= grid.size())
        return 0;
    if (sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int cost = 0;
    cost = max(cost, goldminerec01(grid, sr - 1, sc + 1, dp));
    cost = max(cost, goldminerec01(grid, sr, sc + 1, dp));
    cost = max(cost, goldminerec01(grid, sr + 1, sc + 1, dp));

    return dp[sr][sc] = cost + grid[sr][sc];
}

void tabulation(vector<vector<int>> grid, int sr, int sc, vector<vector<int>> &dp)
{

    for (int j = grid[0].size() - 1; j >= 0; j--)
    {
        for (int i = grid.size() - 1; i >= 0; i--)
        {

            if (j == grid[0].size() - 1)
            {
                dp[i][j] = grid[i][j];
            }

            int cost = 0;
            if (isvalid(grid, i - 1, j + 1))
                cost = max(cost, dp[i - 1][j + 1]);

            if (isvalid(grid, i, j + 1))
                cost = max(cost, dp[i][j + 1]);

            if (isvalid(grid, i + 1, j + 1))
                cost = max(cost, dp[i + 1][j + 1]);

            dp[i][j] = cost + grid[i][j];
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                grid[i][j] = x;
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, 0));

        //  tabulation(grid,0,0,dp);
        int maxm = 0;
        for (int i = 0; i < n; i++)
        {
            maxm = max(maxm, goldminerec01(grid, i, 0, dp));
        }
        cout << maxm << "\n";
    }
}
