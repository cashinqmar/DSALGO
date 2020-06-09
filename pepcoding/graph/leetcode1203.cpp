#include<bits/stdc++.h>
using namespace std;

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n+2*m);
        for(int i=0;i<group.size();i++){
            if(group[i]==-1)continue;
            
            graph[n+2*(group[i])].push_back(i);
            graph[i].push_back(n+2*(group[i])+1);
        }

        for(int i=0;i<beforeItems.size();i++){
           if(beforeItems[i].size()==0)continue;

           for(int j=0;j<beforeItems[i].size();j++){
               int gn1=group[i];
               int gn2=group[beforeItems[i][j]];

               if(gn1==-1&&gn2==-1){
                   graph[beforeItems[i][j]].push_back(i);
               }
               else if(gn1==-1&&gn2>-1){
                    graph[n+2*(gn2)+1].push_back(i);
               }
               else if(gn1>1&&gn2==-1){
                   graph[beforeItems[i][j]].push_back(n+2*gn1);
               }
               else if(gn1==gn2){
                    graph[beforeItems[i][j]].push_back(i);
               }
               else{
                    graph[n+2*(gn2)+1].push_back(n+2*gn1);
               }
           }
        }

        vector<int> incoming(n+2*m,0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                incoming[graph[i][j]]++;
            }
        }

        queue<int> q;
     for(int i=0;i<incoming.size();i++)if(incoming[i]==0)q.push(i);


     vector<int> ans;
     while(!q.empty()){
         int temp=q.front();
         q.pop();
         if(temp<n)ans.push_back(temp);

         for(auto i:graph[temp]){
             if(--incoming[i]==0){
                 q.push(i);
             }
         }
     }

     return ans;

}
int main(){

}