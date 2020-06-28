#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> patt;
    unordered_map<char, int> str;

    for (int i = 0; i < p.size(); i++)
    {
        patt[p[i]]++;
    }
    int matchcount = 0;
    for (int i = 0; i < p.size(); i++)
    {
        str[s[i]]++;
        if (str[s[i]] <= patt[s[i]])
            matchcount++;
    }

    vector<int> ans;

    if (matchcount == p.size())
        ans.push_back(0);

    int i = 0, j = p.size() - 1;
    while (j < s.size())
    {
        str[s[i]]--;
        if (str[s[i]] < patt[s[i]])
            matchcount--;
        i++;
        j++;
        str[s[j]]++;
        if (str[s[j]] <= patt[s[j]])
            matchcount++;
        if (matchcount == p.size())
            ans.push_back(i);
    }
    return ans;
}

int main()
{
}