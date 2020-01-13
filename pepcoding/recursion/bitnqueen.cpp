#include <bits/stdc++.h>
using namespace std;
vector<bool> r(10, false);
vector<bool> c(10, false);
vector<bool> ad(r.size() + c.size() - 1, false);
vector<bool> d(r.size() + c.size() - 1, false);

int isqueensafe(vector<vector<bool>> boxes, int x, int y)
{
    if (r[x] == true || c[y] == true || d[x + y] == true || ad[x - y + ad.size()] == true)
        return false;
    return true;
}

int nqueencomb(vector<vector<bool>> &boxes, int lqpl, int tnq, int qpsf, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpl; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes.size();
        int y = i % boxes.size();

        if (isqueensafe(boxes, x, y))
        {
            r[x] = true;
            c[y] = true;
            d[x + y] = true;
            ad[x - y + ad.size()] = true;
            count += nqueencomb(boxes, i + 1, tnq, qpsf + 1, ans + "( " + to_string(x) + " " + to_string(y) + " )");
            r[x] = false;
            c[y] = false;
            d[x + y] = false;
            ad[x - y + ad.size()] = false;
        }
    }

    return count;
}

int main()
{
    vector<vector<bool>> boxes(4, vector<bool>(4, false));
    cout << nqueencomb(boxes, 0, 4, 0, "") << endl;
    // cout<<nqueenperm(boxes,0,4,0,"")<<endl;
}