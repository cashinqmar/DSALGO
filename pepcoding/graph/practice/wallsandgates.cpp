#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<int>> &rooms,int x,int y){
    return x>=0&&x<rooms.size()&&y>=0&&y<rooms[0].size();
}

void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<rooms.size();i++){
        for(int j=0;j<rooms[0].size();j++){
             if(rooms[i][j]==0){
                 q.push({{i,j},1});
             }
        }
    }

    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

    while(!q.empty()){
        pair<pair<int,int>,int> temp=q.front(); q.pop();
        int x=temp.first.first;
        int y=temp.first.second;
        int dist=temp.second;

        for(int i=0;i<4;i++){
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];

            if(isvalid(rooms,newx,newy)){
                if(rooms[newx][newy]==INT_MAX){
                    rooms[newx][newy]=dist;
                q.push({{newx,newy},dist+1});
            }
        }
    }
}
}

int main(){
}