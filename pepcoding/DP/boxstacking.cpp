#include<bits/stdc++.h>
using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

void push( vector<vector<int>> &bigarr,vector<int> &arr){
   
        vector<int> temp={max(arr[0],arr[1]),min(arr[0],arr[1]),arr[2]};
        bigarr.push_back(temp);
        
        vector<int> temp={max(arr[0],arr[2]),min(arr[0],arr[2]),arr[1]};
        bigarr.push_back(temp);
        
        vector<int> temp={max(arr[2],arr[1]),min(arr[2],arr[1]),arr[0]};
        bigarr.push_back(temp);

}

int lis(vector<pair<int,int>> &nums){
    int n=nums.size();
    int ans=0;
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        dp[i]=nums[i].second;
        for(int j=0;j<i;j++){
            if(nums[j].first<nums[i].first){
                dp[i]=max(dp[i],dp[j]+nums[i].second);
            }
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<vector<int>> bigarr;
    for(int i=0;i<n;i++){
        vector<int> arr(3);
        arr[2]=height[i];
        arr[1]=width[i];
        arr[0]=length[i];
        push(bigarr,arr);
    }

    sort(bigarr.begin(),bigarr.end(),[](vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]>b[1];
        else return a[0]<b[0];
    });

    vector<pair<int,int>> lisarr;

    for(int i=0;i<bigarr.size();i++){
        lisarr.push_back({bigarr[i][1],bigarr[i][2]});
    }

    return lis(lisarr);
}