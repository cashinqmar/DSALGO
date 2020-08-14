#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

void bfs (vector<vector<int>> &dist,vector<vector<char>> &matrix,int si,int sj){

queue<vector<int>> q;
q.push({si,sj,0});
matrix[si][sj]='*';


while(!q.empty()){
vector<int> temp=q.front();
q.pop();

int x=temp[0];
int y=temp[1];
int len=temp[2];
dist[x][y]=temp[2];

for(int i=0;i<4;i++){
    int newx=x+dir[i][0];
    int newy=y+dir[i][1];

    if(newx<dist.size()&&newx>=0&&newy<dist[0].size()&&newy>=0&&matrix[newx][newy]=='O'){
        q.push({newx,newy,len+1});
        matrix[newx][newy]='*';
    }
}
}

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<char>> matrix(n,vector<char>(m));
    vector<vector<int>> dist(n,vector<int>(m,-1));



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;
    bfs(dist,matrix,si-1,sj-1);


    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dist[x-1][y-1]<<"\n";
    }

}