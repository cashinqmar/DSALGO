#include<bits/stdc++.h>
using namespace std;
bool valid(int x,int y,int n){
    return (x>=0)&&(x<n)&&(y>=0)&&(y<n);
}
vector< vector<int>> arr={{0,1},{1,0},{-1,0},{0,-1}};
vector<string> dir={"r","d","u","l"};

int permutations(vector< vector<int>> &visited,int sr,int sc,int dr,int dc ,string ans,int radius){
if(sr==dr&&sc==dc){
    cout<<ans<<endl;
    return 1;
    }
int count=0;
visited[sr][sc]=1;
for(int j=1;j<=radius;j++){
for(int i=0;i<4;i++){
    int x=sr+arr[i][0]*j;
    int y=sc+arr[i][1]*j;
    if(valid(x,y,visited.size())&&visited[x][y]==0){
       count+= permutations(visited,x,y,dr,dc,ans+dir[i]+to_string(radius),radius);
    }
}
}
visited[sr][sc]=0;
return count;
}



int main(){
    int m=3;
    int n=3;
    vector< vector<int>> arr(n,vector<int> (m,0));
    cout<<permutations(arr,0,0,2,2,"",1);
    return 0;
}