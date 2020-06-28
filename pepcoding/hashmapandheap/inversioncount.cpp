#include <bits/stdc++.h>
using namespace std;


long long int ans=0;

long long int merge(vector<long long int> &arr,long long int si,long long int mi,long long int ei){

int n1=mi-si+1;
int n2=ei-mi;

vector<long long int> arr1(mi-si+1);
vector<long long int> arr2(ei-mi);

for(int i=0;i<mi-si+1;i++)arr1[i]=arr[i+si];
for(int i=0;i<ei-mi;i++)arr2[i]=arr[i+mi+1];


long long int t1=n1-1;
long long int t2=n2-1;

    while(t1>=0)
    {
        while((t2>=0) && (arr2[t2]>=arr1[t1]))
        {
            t2--;
        }
        ans+=t2+1;
        t1--;
    }


int k=si;
int i=0;
int j=0;


while(i<mi-si+1&&j<ei-mi){
    if(arr1[i]<=arr2[j]){
        arr[k++]=arr1[i++];
    }
    else{
        arr[k++]=arr2[j++];
    }
}

while(i<mi-si+1){
    arr[k++]=arr1[i++];
}
while(j<ei-mi){
    arr[k++]=arr2[j++];
}

return 0;

}

long long int mergesort(vector<long long int> &arr,long long int si,long long int ei){
    long long int count=0;
if(si<ei){
    long long int mid=(si+ei)/2;
    count+=mergesort(arr,si,mid);
    count+=mergesort(arr,mid+1,ei);

    count+=merge(arr,si,mid,ei);
    return count;
}
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> arr(n, 0);
        for ( int i = 0; i < n; i++)
            cin >> arr[i];

        ans=0;
    mergesort(arr,0,n-1);
arr.clear();
        // for(int i=0;i<n;i++)cout<<arr[i]<<" ";

        cout<<ans<<"\n";
    }
}