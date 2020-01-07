#include<bits/stdc++.h>
using namespace std;

int permutations01(vector<int>& arr,int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
   if(n-arr[i]>=0)     
   count+=permutations01(arr,n-arr[i],ans+to_string(arr[i]));
   }
   return count;
}

int permutations02(vector<int> &arr, int tar, string ans, vector<bool> &vis)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!vis[i] && tar - arr[i] >= 0)
        {
            vis[i] = true;
            count += permutations02(arr, tar - arr[i], ans + to_string(arr[i]) + " ", vis);
            vis[i] = false;
        }
    }

    return count;
}


int permutations03(vector<int>& arr,int n,string ans,int vidx){
    if(n==0||(arr.size())==vidx){
        if(n==0){
        cout<<ans<<endl;
        return 1;
        }
        return 0;
    }
    int count=0;
    if((n-arr[vidx])>=0){
     count+=permutations03(arr,n-arr[vidx],ans+to_string(arr[vidx]),0);
    }
     count+=permutations03(arr,n,ans,vidx+1);
     return count;
}

int permutations04(vector<int>& arr, int n,string ans,int vidx,vector<bool>& vis){
    if(n==0||vidx==arr.size()){
        if(n==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(!vis[arr[vidx]]&&(n-arr[vidx])>=0){
        vis[arr[vidx]]=true;
        count+=permutations04(arr,n-arr[vidx],ans+to_string(arr[vidx]),vidx+1,vis);
        vis[arr[vidx]]=false;
    }
    count+=permutations04(arr,n,ans,vidx+1,vis);
    return count;
}


void solve(){
    vector<int> arr={2,3,5,7};
    vector<bool> vis(4, false);
//cout<<permutations01(arr,10,"")<<endl;
cout<<permutations02(arr,10,"",vis)<<endl;
//cout<<permutations03(arr,10,"",0);
cout<<permutations04(arr,10,"",0,vis);
}



int main(){
solve();
return 0;

}