#include <bits/stdc++.h>

using namespace std;



// Complete the braces function below.
 bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                if(st.size()==0)return false;
                if(st.top()=='{'||st.top()=='[')return false;
                else st.pop();
            }
             else if(s[i]==']'){
                  if(st.size()==0)return false;
                if(st.top()=='('||st.top()=='{')return false;
                else st.pop();
            }
             else if(s[i]=='}'){
                  if(st.size()==0)return false;
                if(st.top()=='('||st.top()=='[')return false;
                else st.pop();
            }
        }
        return st.empty();
    }
vector<string> braces(vector<string> values) {
vector<string> ans;

for(int i=0;i<values.size();i++){
    if(isValid(values[i]))ans.push_back("YES");
    else ans.push_back("NO");
}

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int values_count;
    cin >> values_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item;
        getline(cin, values_item);

        values[i] = values_item;
    }

    vector<string> res = braces(values);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
