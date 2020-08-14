#include<bits/stdc++.h>
using namespace std;


bool ismatch(string &a,string &b){
    int count=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])count++;
        if(count>2)return false;
    }
    return true;
}

int root(vector<int>& par,int vtx){
    if(par[vtx]==vtx)return vtx;
    return par[vtx]=root(par,par[vtx]);
}

void merge(vector<int> &par,vector<int> &size,int x,int y,int &count){
    int a=root(par,x);
    int b=root(par,y);

    if(a!=b){
        if(size[a]<size[b]){
            size[b]+=size[a];
            par[a]=b;
        }
        else{
            size[a]+=size[b];
            par[b]=a;
        }
        count--;
    }
}
int numSimilarGroups(vector<string>& A) {
int count=A.size();
    
vector<int> par(A.size(),0);

for(int i=0;i<A.size();i++)par[i]=i;

vector<int> size(A.size(),0);

for(int i=0;i<A.size();i++){
    for(int j=i+1;j<A.size();j++){
         if(ismatch(A[i],A[j])){
             merge(par,size,i,j,count);
         }
    }
}

unordered_set<int> s;
for(int i=0;i<par.size();i++){
    s.insert(root(par,i));
}
// return count;
return s.size();
}


int main(){

}