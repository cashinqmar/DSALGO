#include <bits/stdc++.h>
using namespace std;

int mismatch(string &a, string &b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    return count;
}

int kSimilarity(string A, string B)
{
    queue<pair<string, pair<int, int>>> q;

    int i = 0;
    for (; i < A.size(); i++)
    {
        if (A[i] != B[i])
            break;
    }

    q.push({A, {0, i}});

    while (!q.empty())
    {
        pair<string, pair<int, int>> temp = q.front();
        q.pop();
        string s = temp.first;
        int k = temp.second.first;

        if (s == B)
            return k;

        int before = mismatch(s, B);

        int i = temp.second.second;
        for (; i < s.size(); i++)
        {
            if (s[i] != B[i])
                break;
        }

        int j = i;
        int h = i;
        char ch = B[i];

        vector<pair<string, pair<int, int>>> arr;

        bool flag = true;
        for (; i < s.size(); i++)
        {
            if (s[i] == ch)
            {
                swap(s[i], s[j]);
                int after = mismatch(s, B);
                arr.push_back({s, {k + 1, h}});
                if (before - after == 2)
                {
                    flag = false;
                    q.push({s, {k + 1, h}});
                    break;
                }
                swap(s[i], s[j]);
            }
        }
        if (flag)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                q.push(arr[i]);
            }
        }
    }
    return 0;
}

int main()
{
}