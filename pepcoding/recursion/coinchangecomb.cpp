#include<bits/stdc++.h>
using namespace std;

int combinations01(vector<int>& arr, int n,string ans,int vidx){
    if(n==0||vidx==arr.size()){
        if(n==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    for(int i=vidx;i<arr.size();i++){
        if(n-arr[i]>=0)
        count+=combinations01(arr,n-arr[i],ans+to_string(arr[i]),i);
    }
    return count;
}
int combinations02(vector<int>& arr, int n,string ans,int vidx){
    if(n==0||vidx==arr.size()){
        if(n==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    for(int i=vidx;i<arr.size();i++){
        if(n-arr[i]>=0)
        count+=combinations02(arr,n-arr[i],ans+to_string(arr[i]),i+1);
    }
    return count;
}


int combinations03(vector<int>& arr,int n,string ans,int vidx){
    if((n==0)&&(vidx==arr.size())){
        if(n==0){
        cout<<ans<<endl;
        return 1;
    }
    return 0;
    }

    int count=0;
    if((n-arr[vidx])>=0){
     count+=combinations03(arr,n-arr[vidx],ans+to_string(arr[vidx]),vidx);
    }
     count+=combinations03(arr,n,ans,vidx+1);
     return count;
}

void solve(){
 vector<int> arr={2,3,5,7};
 vector<bool> vis(4,false);
//  cout<<combinations01(arr,10,"",0)<<endl;
//  cout<<combinations02(arr,10,"",0)<<endl;
cout<<combinations03(arr,10,"",0);
}

int main(){
    solve();
    return 0;
}