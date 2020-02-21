#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<vector<int>> &board, int x, int y)
{
    return((x >= 0) && (x < board.size()) && (y >= 0) && (y < board[0].size()));
}

vector<vector<int>> arr1 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int safepath(vector<vector<int>> &board, int x, int y, int idx)
{
    if (y == board[0].size() - 1)
    {
        int temp = idx;
        idx = 0;
        return temp;
    }
    int smallest = 1e8;

    for (int i = 0; i < 4; i++)
    {
        int newx = x + arr1[i][0];
        int newy = y + arr1[i][1];

        if (isvalid(board, newx, newy) && (board[newx][newy] != 0))
        {   board[newx][newy]=0;
            smallest = min(smallest, safepath(board, newx, newy, idx + 1));
             board[newx][newy]=1;
        }
    }
    return smallest;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int newx = i + arr1[k][0];
                    int newy = j + arr1[k][1];
                    if (isvalid(board, newx, newy))
                        board[newx][newy] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == -1)
                board[i][j] = 0;
        }
    }
    int ans = 1e8;
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] != 0)
        {
            ans = min(ans, safepath(board, i, 0, 0));
            if (ans == board[0].size() - 1)
            {
                break;
            }
        }
    }
    cout<<ans;
}
int main()
{
    solve();
    return 0;
}