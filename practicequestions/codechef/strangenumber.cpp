#include<bits/stdc++.h>
using namespace std;

bool kFactors(int n, int k) 
{ 
	// A vector to store all prime factors of n 
	vector<int> P; 

	// Insert all 2's in vector 
	while (n%2 == 0) 
	{ 
		P.push_back(2); 
		n /= 2; 
	} 

	// n must be odd at this point 
	// So we skip one element (i = i + 2) 
	for (int i=3; i*i<=n; i=i+2) 
	{ 
		while (n%i == 0) 
		{ 
			n = n/i; 
			P.push_back(i); 
		} 
	} 

	// This is to handle when n > 2 and 
	// n is prime 
	if (n > 2) 
		P.push_back(n); 

	// If size(P) < k, k factors are not possible 
	if (P.size() < k) 
	{ 
		
		return false; 
	} 

	// printing first k-1 factors 
	return true;
} 
  
int main(){
 int t;
 cin>>t;
 while(t--){
     int x,k;
     cin>>x>>k;

    
     if(kFactors(x,k))cout<<"1"<<"\n";
     else cout<<"0"<<"\n";

 }


}