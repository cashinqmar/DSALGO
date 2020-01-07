#include<bits/stdc++.h>
 using namespace std;



 int nqueencomb(vector< vector<bool>>& boxes,int lqpl,int tnq,int qpsf,string ans,int row,int col,int d,int ad){
     if(qpsf==tnq){
         cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes.size()*boxes[0].size();i++){
         int x=i/boxes[0].size();
         int y=i%boxes[0].size();
                 int a=1<<x;
                 int b=1<<y;
                 int dg=1<<(x+y);
                 int adg=1<<(x-y+boxes[0].size()-1);
                 if(((row&a)==0) && ((col&b)==0) && ((d&dg)==0) && ((ad&adg)==0)){
                     boxes[x][y]=true;
                     row^=a;col^=b;d^=dg;ad^=adg;
                      count+=nqueencomb(boxes,i+1,tnq,qpsf+1,ans+"( "+to_string(x)+" "+to_string(y)+" )",row,col,d,ad);
                     boxes[x][y]=false;
                     row^=a;col^=b;d^=dg;ad^=adg; 
                 }
             }
    
        return count;
 }

int main(){
    vector< vector<bool>>  boxes(4, vector<bool>(4,false));
    int r=0;
    int c=0;
    int d=0;
    int ad=0;
    cout<<nqueencomb(boxes,0,4,0,"",0,0,0,0)<<endl;
   // cout<<nqueenperm(boxes,0,4,0,"")<<endl;
}