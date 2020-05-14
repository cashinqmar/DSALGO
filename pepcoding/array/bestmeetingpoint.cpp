#include<bits/stdc++.h>
using namespace std;

int minTotalDistance(vector<vector<int>> &grid) {
        // Write your code here
        vector<int> row;
        vector<int> col;
        vector<pair<int,int>> all;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    row.push_back(i);
                    col.push_back(j);
                    all.push_back({i,j});
                }
            }
        }

        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        int  n=row.size();
        n=n/2;
        int x=row[n];
        int y=col[n];

        int distance=0;
        for(int i=0;i<all.size();i++){
            distance+=abs(all[i].first-x)+abs(all[i].second-y);
        }
        return distance;
    }
int main(){
    vector<vector<int>> grid={{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout<<minTotalDistance(grid);
}