#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        unordered_map<int, int> m1;
        unordered_map<int, pair<int, int>> m2;

        for (int i = 0; i < n; i++)
        {
            if (m1.find(arr[i]) == m1.end())
            {
                m1[arr[i]]++;
                m2[arr[i]] = {i, i};
            }
            else
            {
                m1[arr[i]]++;
                int start = m2[arr[i]].first;
                m2[arr[i]] = {start, i};
            }
        }
        int length = INT_MAX;
        int maxmfreq = INT_MIN;

        int newi = 0;
        int newj = 0;
        for (auto i : m1)
        {
            if (i.second > maxmfreq)
            {
                maxmfreq = i.second;
                length = m2[i.first].second - m2[i.first].first + 1;
                newi = m2[i.first].first;
                newj = m2[i.first].second;
            }
            else if (i.second == maxmfreq && (m2[i.first].second - m2[i.first].first + 1 < length))
            {
                length = m2[i.first].second - m2[i.first].first + 1;
                newi = m2[i.first].first;
                newj = m2[i.first].second;
            }
        }
        if (newj - newi + 1 == 1)
            cout << arr[0] << "\n";

        else
        {
            for (int i = newi; i <= newj; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
}