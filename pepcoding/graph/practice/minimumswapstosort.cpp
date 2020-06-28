#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int n){
    /*Your code here */
    pair<int,int> newarr[n];
    for(int i=0;i<n;i++){
         newarr[i].first=arr[i];
         newarr[i].second=i;
    }

    sort(newarr,newarr+n);

    int ans=0;
    int visited[n];
    for(int i=0;i<n;i++)visited[i]=-1;

    for(int i=0;i<n;i++){

        if(visited[i]==1)continue;

        int j=i;
        int cycle=0;
        while(visited[j]==-1){
            visited[j]=1;
            pair<int,int> temp=newarr[j];
            j=temp.second;
            cycle++;
        }
        ans+=cycle-1;
    }
return ans;
}