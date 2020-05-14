 #include<bits/stdc++.h>
 using namespace std;
 int QueenBoxCombi_01(vector<bool>& boxes,int lqpl,int tnq,int qpsf,string ans){
     if(qpsf==tnq){
         cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes.size();i++){
         count+=QueenBoxCombi_01(boxes,i+1,tnq,qpsf+1,ans+"b"+to_string(i)+"q"+to_string(qpsf));
     }

        return count;
    }
int queen2dcomb(vector< vector<bool>>& boxes,int lqpl,int tnq,int qpsf,string ans){
     if(qpsf==tnq){
        cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes[0].size()*boxes[0].size();i++){
         int x=i/boxes.size();
         int y=i%boxes.size();
         count+=queen2dcomb(boxes,i+1,tnq,qpsf+1,ans+"( "+to_string(x)+" "+to_string(y)+" )");
     }

        return count;
    }

    int queen2dperm(vector< vector<bool>>& boxes,int lqpl,int tnq,int qpsf,string ans){
     if(qpsf==tnq){
         cout<<ans<<endl;
         return 1;
     }

     int count=0;
     for(int i=lqpl;i<boxes[0].size()*boxes[0].size();i++){
         int x=i/boxes[0].size();
         int y=i%boxes[0].size();
         if(!boxes[x][y]){
         boxes[x][y]=true;
         count+=queen2dperm(boxes,0,tnq,qpsf+1,ans+"( "+to_string(x)+" "+to_string(y)+" ) ");
         boxes[x][y]=false;
         }

     }

        return count;
    }

    int main(){
        vector< vector<bool>>  boxes(4, vector<bool>(4,false));
    
        cout<<queen2dcomb(boxes,0,4,0,"")<<endl;
        //   cout<<queen2dperm(boxes,0,4,0,"")<<endl;
    }