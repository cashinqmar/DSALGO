#include<bits/stdc++.h>
using namespace std;
 int diagonalSum(vector<vector<int>>& mat) {
if(mat.size()==0)return 0;
int ans=0;    
map<pair<int,int>,int> m;
for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[0].size();j++){
        if(i==j){
            m[{i,j}]++;
            ans+=mat[i][j];
        }
    }
}
for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[0].size();j++){
        if(j==mat[0].size()-1-i&&m[{i,j}]==0){
            ans+=mat[i][j];
        }
    }
}
return ans;
}

int main(){

}