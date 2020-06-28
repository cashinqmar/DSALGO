#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1},{0,0}};
unordered_set<long long int> s;

bool process(int i,int j,unordered_map<int,int> &row,unordered_map<int,int> &col,unordered_map<int,int> &diag,unordered_map<int,int> &anti,long long int n){
    bool flag=false;
    if(row[i]>0)flag=true;
    if(col[j]>0)flag=true;
    if(diag[j-i]>0)flag=true;
    if(anti[i+j]>0)flag=true;

    for(int k=0;k<9;k++){
        int newx=i+dir[k][0];
        int newy=j+dir[k][1];

        if(newx<0||newx>=n||newy<0||newy>=n)continue;

        long long int  str=newx*n+newy;
        if(s.find(str)!=s.end()){
        s.erase(str);
        row[newx]--;
        col[newy]--;
        diag[newy-newx]--;
        anti[newx+newy]--;
        }
    }
    return flag;
}
vector<int> gridIllumination(long long int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
unordered_map<int,int> row;
unordered_map<int,int> col;
unordered_map<int,int> diag;
unordered_map<int,int> anti;
 


for(int i=0;i<lamps.size();i++){
    int x=lamps[i][0];
    int y=lamps[i][1];
   long long int str =x*n+y;
    s.insert(str);

      row[x]++;
        col[y]++;
        diag[y-x]++;
        anti[x+y]++;
}

vector<int> ans;
for(int i=0;i<queries.size();i++){
    int x=queries[i][0];
    int y=queries[i][1];
    if(process(x,y,row,col,diag,anti,n))ans.push_back(1);
    else ans.push_back(0);
}

return ans;
}


int main(){

}