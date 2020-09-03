
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long  n;
    cin>>n;
    vector<long long > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    if(n<=2){
        cout<<arr[0]-1;
    }
    long long res=1e18;
    for(int i=1;i<1e6;i++){
		long long now=0,k=1;
		for(int j=0;j<n;j++){
            if(k>1e14){
                cout<<res<<" ";
                return ;
            }
			now+=abs(k-arr[j]);
			k*=i;
		}
		res=min(res,now);
	}
    cout<<res<<"\n";
}

int main(){
    solve();
    return 0;
}

