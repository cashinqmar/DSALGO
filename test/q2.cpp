#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'quicksortMedianOf3Pivots' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */


void helper(vector<int> a,vector<int> &pivot){
int n=a.size();
if(n<3)return;

vector<int> three;
three.push_back(a[0]);
three.push_back(a[n/2]);
three.push_back(a[n-1]);
sort(three.begin(),three.end());

int median=three[1];
pivot.push_back(median);

vector<int> left;
vector<int> right;

for(int i=0;i<a.size();i++){
    if(a[i]<median)left.push_back(a[i]);
    else if(a[i]>median)right.push_back(a[i]);
}

helper(left,pivot);
helper(right,pivot);
return;
}
vector<int> quicksortMedianOf3Pivots(vector<int> a) {
vector<int> pivot;
helper(a,pivot);
return pivot;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<int> result = quicksortMedianOf3Pivots(a);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
