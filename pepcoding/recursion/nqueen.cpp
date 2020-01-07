#include<bits/stdc++.h>
 using namespace std;
bool isqueensafe2( vector< vector<bool>>& boxes,int x,int y){
    vector< vector<int> > dir={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int radius=max(boxes.size(),boxes[0].size());
    for(int i=0;i<dir.size();i++){
        for(int j=1;j<=radius;j++){
            int r=x+j*dir[i][0];
            int c=y+j*dir[i][1];
            if(r<0||c<0||r>=boxes.size()||c>=boxes[0].size()) break;
            if(boxes[r][c])return false;
        }
    }
    return true;
}
 
int nqueenperm(vector< vector<bool>>& boxes,int lqpl,int tnq,int qpsf,string ans){
     if(qpsf==tnq){
         cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes[0].size()*boxes[0].size();i++){
         int x=i/boxes[0].size();
         int y=i%boxes[0].size();
         if(!boxes[x][y]){
             if(isqueensafe2(boxes,x,y)){
         boxes[x][y]=true;
         count+=nqueenperm(boxes,0,tnq,qpsf+1,ans+"( "+to_string(x)+" "+to_string(y)+" ) ");
         boxes[x][y]=false;
         }
         }

     }

        return count;
    }


int isqueensafe(vector< vector<bool>> boxes,int x,int y ){
    vector< vector<int> > dir={{0,-1},{-1,-1},{-1,0},{-1,1}};
    int radius=max(boxes.size(),boxes[0].size());
    for(int i=0;i<dir.size();i++){
        for(int j=1;j<=radius;j++){
            int r=x+j*dir[i][0];
            int c=y+j*dir[i][1];
            if(r<0||c<0||r>=boxes.size()||c>=boxes[0].size()) break;
            if(boxes[r][c])return false;
        }
    }
    return true;
}


 int nqueencomb(vector< vector<bool>>& boxes,int lqpl,int tnq,int qpsf,string ans){
     if(qpsf==tnq){
         cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes.size()*boxes[0].size();i++){
         int x=i/boxes.size();
         int y=i%boxes.size();
         
             if(isqueensafe(boxes, x, y)){
                 boxes[x][y]=true;
             count+=nqueencomb(boxes,i+1,tnq,qpsf+1,ans+"( "+to_string(x)+" "+to_string(y)+" )");
             boxes[x][y]=false;
             }

    }
    
        return count;
 }

int main(){
    vector< vector<bool>>  boxes(4, vector<bool>(4,false));
    cout<<nqueencomb(boxes,0,4,0,"")<<endl;
   // cout<<nqueenperm(boxes,0,4,0,"")<<endl;
}