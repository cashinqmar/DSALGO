#include<bits/stdc++.h>
using namespace std;

void tugofwar(int* arr,int n,int select,bool curr[],bool sol[],int &diff,int sum,int total,int pos){
    if(pos==n)return;
    if(n/2-select>n-pos)return;
    tugofwar(arr,n,select,curr,sol,diff,sum,total,pos+1);
    select++;
    curr[pos]=true;
    total+=arr[pos];

    if(n/2==select){
        if(abs(sum/2-total)<diff){
            diff=abs(sum/2-total);
            for(int i=0;i<n;i++){
                sol[i]=curr[i];
            }

        }
    }
   else  tugofwar(arr,n,select,curr,sol,diff,sum,total,pos+1);
   curr[pos]=false;
}
void solve(){
    int n;
    cin>>n;
    int sum=0;
    int *arr=new int[n];
    bool* curr=new bool[n];
    bool* sol=new bool[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        curr[i]=false;
        sol[i]=false;
    }

    
    int diff=1e8;
    tugofwar(arr,n,0,curr,sol,diff,sum,0,0);
    vector<int>left;
    vector<int>right;
    for(int i=0;i<n;i++){
    if(sol[i]==false)left.push_back(arr[i]);
    else right.push_back(arr[i]);
}

int i=0;
cout<<"[";
for(i=0;i<left.size()-1;i++){
cout<<left[i]<<", ";
}
cout<<left[i]<<"]";
i=0;
cout<<"[";
for(i=0;i<right.size()-1;i++){
cout<<right[i]<<", ";
}
cout<<right[i]<<"]";
}
int main(){
    solve();
    return 0;
}