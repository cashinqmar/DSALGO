#include <bits/stdc++.h>

using namespace std;

// Complete the winningLotteryTicket function below.
bool checkxor(string s1,string s2){
    for(int i=0;i<10;i++){
        if(s1[i]=='0'&&s2[i]=='0'){
            return false;
        }
    }
    return true;
}

long winningLotteryTicket(vector<string> tickets) {

map<string,int> m;

for(int i=0;i<tickets.size();i++){
    string s="0000000000";
    for(int j=0;j<tickets[i].size();j++){
        s[tickets[i][j]-'0']='1';
    }
m[s]++;
}

long ans=0;
map<string,int> ::iterator it;
for(it=m.begin();it!=m.end();){
map<string,int> ::iterator jt;
jt=it++;
for(jt;jt!=m.end();jt++){
if(checkxor(it->first,jt->first)){
    ans+=it->second*jt->second;
}
}

}

if(m["1111111111"]>0){
int k=m["1111111111"];
ans+=(k*(k-1))/2;
}

return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> tickets(n);

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);

        tickets[i] = tickets_item;
    }

    long result = winningLotteryTicket(tickets);

    fout << result << "\n";

    fout.close();

    return 0;
}
