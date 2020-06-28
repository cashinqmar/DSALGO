#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int one = 0;
        int two = 0;
        int zero = 0;

        unordered_map<string, int> m;
        m["0x0"] = 1;

        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
            if (s[i] == '2')
                two++;

            int diff1 = one - zero;
            int diff2 = zero - two;

            string temp = to_string(diff1) + "x" + to_string(diff2);
            ans += m[temp];
            m[temp]++;
        }
        cout << ans << "\n";
    }
}