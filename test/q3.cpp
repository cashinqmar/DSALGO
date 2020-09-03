#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'maximumLearning' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY iv
 *  2. INTEGER_ARRAY articles
 *  3. INTEGER p
 */

int helper(vector<vector<int>> &dp, vector<int> &value,vector<int> &weight,int wt,int idx){
    if(wt<=0||idx<0){
        return 0;
    }

    if(dp[idx][wt]!=-1)return dp[idx][wt];

    int ans=0;
//picked
    if(wt-weight[idx]>=0){
    ans=helper(dp,value,weight,wt-weight[idx],idx-1)+value[idx];
    }
//notpicked
    ans=max(ans,helper(dp,value,weight,wt,idx-1));

    return dp[idx][wt]=ans;
}


int maximumLearning(vector<int> iv, vector<int> articles, int p) {
    int n=iv.size();
    vector<int> weight(n,0);
    for(int i=0;i<n;i++)weight[i]=articles[i]*2;
   
    vector<vector<int>> dp(n,vector<int> (p+1,-1));
    long long sum=helper(dp,iv,weight,p,n-1);
    return sum;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string iv_count_temp;
    getline(cin, iv_count_temp)
    int iv_count = stoi(ltrim(rtrim(iv_count_temp)));

    vector<int> iv(iv_count);

    for (int i = 0; i < iv_count; i++) {
        string iv_item_temp;
        getline(cin, iv_item_temp);

        int iv_item = stoi(ltrim(rtrim(iv_item_temp)));

        iv[i] = iv_item;
    }

    string articles_count_temp;
    getline(cin, articles_count_temp);

    int articles_count = stoi(ltrim(rtrim(articles_count_temp)));

    vector<int> articles(articles_count);

    for (int i = 0; i < articles_count; i++) {
        string articles_item_temp;
        getline(cin, articles_item_temp);

        int articles_item = stoi(ltrim(rtrim(articles_item_temp)));

        articles[i] = articles_item;
    }

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = maximumLearning(iv, articles, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
