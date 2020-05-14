#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> dep(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
         for(int i=0;i<n;i++){
            cin>>dep[i];
        }

        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());

        int i=1;
        int j=0;
        int platform=1;
        int ans=1;

        while(i<n){
            if(arr[i]<dep[j]){
                platform++;
                 ans=max(ans,platform);
            }
            else if(arr[i]>dep[j]){
                platform=platform-1==0?1:platform--;
                j++;
                 ans=max(ans,platform);
            }
            else{
                  platform++;
                 ans=max(ans,platform);
            }
            i++;
           
        }
        cout<<ans<<"\n";
    }
}