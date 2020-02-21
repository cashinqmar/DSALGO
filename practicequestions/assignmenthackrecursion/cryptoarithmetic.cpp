#include <iostream>
#include <vector>
using namespace std;
string str1, str2, str3;
vector<int> mapping(26, 0);
int vis = 0;
void display(string str)
{
    cout << "{";
    for (int i = 0; i < str.size() - 1; i++)
    {
        cout << str[i] << "=" << mapping[str[i] - 'a'] << ", ";
    }
    cout << str[str.size() - 1] << "=" << mapping[str[str.size() - 1]-'a'] << "}"<<endl;
}
int getinteger(string str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum = sum * 10 + mapping[str[i] - 'a'];
    }
    return sum;
}
int crypto(string str, int idx)
{
    if (idx == str.size())
    {
        int a = getinteger(str1);
        int b = getinteger(str2);
        int c = getinteger(str3);
        if ((a + b == c) && (to_string(a).size() == str1.size()) && (to_string(b).size() == str2.size()) && (to_string(c).size() == str3.size()))
        {
            display(str);
            return 1;
        }
        return 0;
    }
    int count = 0;
    int ch=str[idx]-'a';
    for(int i=0;i<=9;i++){
        int mask=1<<i;
        if((vis&mask)==0){
            vis^=mask;
            mapping[ch]=i;
            count+=crypto(str,idx+1);
            vis^=mask;
            mapping[ch]=0;
        }
    }
    return count;
}

void solve()
{
    cin >> str1 >> str2 >> str3;
    string str = str1 + str2 + str3;
    int arr[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        arr[str[i] - 'a']++;
    }
    string ans;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
            ans += (char)(i + (int)'a');
    }
    crypto(ans,0);
}
int main()
{
    solve();
    return 0;
}