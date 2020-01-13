#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &box, int lqpl, int tnq, int qpsf, string ans, int row, int col, int diag, int anti)
{
    if (tnq == qpsf)
    {
        cout << "[" << ans << "]";
        return 1;
    }
    int count = 0;
    for (int i = lqpl; i < box.size() * box.size(); i++)
    {
        int x = i / box.size();
        int y = i % box.size();

        int a = 1 << x;
        int b = 1 << y;
        int c = 1 << (x + y);
        int d = 1 << (x - y + box.size() - 1);

        if (((row & a) == 0) && ((col & b) == 0) && ((diag & c) == 0) && ((anti & d) == 0))
        {
            row ^= a;
            col ^= b;
            diag ^= c;
            anti ^= d;
            count += solve(box, i + 1, tnq, qpsf + 1, ans + to_string(y + 1) + " ", row, col, diag, anti);
            row ^= a;
            col ^= b;
            diag ^= c;
            anti ^= d;
        }
    }
    return count;
}
void nqueen(int n)
{
    vector<vector<int>> box(n, vector<int>(n, 0));
    solve(box, 0, n, 0, "", 0, 0, 0, 0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        nqueen(n);
        cout << endl;
    }
}