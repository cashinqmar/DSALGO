#include <bits/stdc++.h>
using namespace std;

bool isReflected(vector<vector<int>> &points)
{
    // Write your code here
    int k;
    unordered_map<string, int> m;

    int minm = INT_MAX;
    int maxm = INT_MIN;

    for (int i = 0; i < points.size(); i++)
    {
        minm = min(points[i][0], minm);
        maxm = max(points[i][0], maxm);
        string str = to_string(points[i][0]) + "x" + to_string(points[i][1]);
        m[str]++;
    }
    k = (minm + maxm);

    for (int i = 0; i < points.size(); i++)
    {
        string str = to_string(points[i][0]) + "x" + to_string(points[i][1]);
        if (m[str] == 0)
            continue;
        int newx = k - points[i][0];
        str = to_string(newx) + "x" + to_string(points[i][1]);
        if (m[str] == 0)
            return false;
        m[str]--;
    }
    return true;
}
int main()
{
}