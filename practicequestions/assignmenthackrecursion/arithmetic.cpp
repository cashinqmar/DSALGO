#include<bits/stdc++.h>
using namespace std;

bool arithmetic(vector<int>& arr,int vsf,string exp,int idx){
	if(idx==arr.size()){
		if(vsf%101==0){
        cout<<exp<<endl;
		return true;
		}
		else return false;
	}

	bool res=false;

	 res=res|arithmetic(arr,vsf+arr[idx],exp+"+"+to_string(arr[idx]),idx+1);
	 if(res)return true;
	 res=res|arithmetic(arr,vsf-arr[idx],exp+"-"+to_string(arr[idx]),idx+1);if(res)return true;
	 res=res|arithmetic(arr,vsf*arr[idx],exp+"*"+to_string(arr[idx]),idx+1);if(res)return true;
	return res;
}

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int vsf=arr[0];
	string exp=to_string(arr[0])+"";
	arithmetic(arr,vsf,exp,1);


}
int main(){
	solve();
	return 0;
}