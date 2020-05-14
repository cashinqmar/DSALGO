#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int ctr=0;
    while(ctr++<t){
        int  n;
        cin>>n;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        vector<vector<int>> row(n+1,vector<int>(n+1,0));
       vector<vector<int>>  col(n+1,vector<int>(n+1,0));

        vector<int> rowcount(n,0);
        vector<int> colcount(n,0);


        int x;
        int count=0;

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cin>>x;
               if(i==j)ans+=x;
             matrix[i][j]=x;
            int mask=1<<x;
            if(rowcount[i]==0&&(row[i][x]!=0)){
                rowcount[i]=1;
            }      
            if(colcount[j]==0&&(col[j][x])!=0){
                colcount[j]=1;
            }     
            row[i][x]=1;
            col[j][x]=1;
            }
        }

       int  ansrow=0;
        int anscol=0;


        for(int i=0;i<n;i++){
            ansrow+=rowcount[i];
            anscol+=colcount[i];
        }

        cout<<"Case #"<<ctr<<": "<<ans<<" "<<ansrow<<" "<<anscol<<"\n";

    }
}


