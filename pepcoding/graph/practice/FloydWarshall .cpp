#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int **matrix=new int*[n];
        for(int i=0;i<n;i++)matrix[i]=new int[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                matrix[i][j]=x;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]==INT_MAX||matrix[k][j]==INT_MAX)continue;
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=matrix[i][j];

                if(x==10000000){
                    cout<<"INF ";
                }
               else cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}