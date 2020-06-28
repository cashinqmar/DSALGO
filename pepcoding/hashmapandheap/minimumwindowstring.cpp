#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{

    if (s.size() < t.size())
        return "";

    unordered_map<char, int> patt;
    unordered_map<char, int> str;

    for (int i = 0; i < t.size(); i++)
    {
        patt[t[i]]++;
    }

    int newi = 0;
    int newj = 0;
    int length = INT_MAX;

    int matchcount = 0;
    for (int i = 0; i < t.size(); i++)
    {
        str[s[i]]++;
        if (patt[s[i]] > 0)
        {
            if (str[s[i]] <= patt[s[i]])
                matchcount++;
        }
    }

    // cout << matchcount << " ";

    if (matchcount == t.size())
    {
        length = t.size();
        newi = 0;
        newj = t.size() - 1;
    }

    int i = 0;
    int j = t.size() - 1;

    bool flag = false;

    while (1)
    {
        while(matchcount < t.size())
        {
            // cout<<"j"<<j<<" ";
            j++;
            if (s.size() == j)
            {
                flag = true;
                break;
            }
            str[s[j]]++;
            if (patt[s[j]] > 0)
                if (str[s[j]] <= patt[s[j]])
                    matchcount++;
        }
        // cout<<"i"<<i<<" "<<"j"<<j<<" "<<"match"<<matchcount<<"\n";

        if (matchcount == t.size() && (length > (j - i + 1)))
        {
            length = j - i + 1;
            newi = i;
            newj = j;
        }
        if (flag)
            break;
        str[s[i]]--;
        if (patt[s[i]] > 0){
            if (str[s[i]] < patt[s[i]])
                matchcount--;
        }
        i++;

    }

    // cout << newi << " " << newj << " ";
    if (newj - newi + 1 >= t.size())
    {
        return s.substr(newi, newj - newi + 1);
    }
    return "";
}
int main()
{
    string a = "ADOBECODEBANC";
    string b = "ABC";

    cout << minWindow(a, b);
}