#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 5, 1}, {4, 2}};

int slidingPuzzle(vector<vector<int>> &board)
{
    unordered_set<string> s;

    string str = "";

    string ans="123450";

    for (auto i : board)
        for (auto j : i)
            str =str+ to_string(j);

    s.insert(str);
    cout<<str<<" ";
    queue<pair<string, int>> q;
    q.push({str,0});

    while (!q.empty())
    {
        pair<string, int> temp=q.front(); q.pop();

        str=temp.first;
        int k=temp.second;

        if(ans==str)return k;

        int i=0;
        for(;i<str.size();i++)if(str[i]=='0')break;

     

        for(int j=0;j<dir[i].size();j++){
            swap(str[i],str[dir[i][j]]);
            if(s.find(str)==s.end()){
                s.insert(str);
                q.push({str,k+1});
            }
            swap(str[i],str[dir[i][j]]);
        }
    }
    return -1;
}
int main()
{
}