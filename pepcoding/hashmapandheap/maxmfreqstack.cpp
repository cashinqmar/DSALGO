#include<bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    unordered_map<int,stack<int>> mstack;
    unordered_map<int,int> freq;
    int maxm;
    FreqStack() {
        maxm=INT_MIN;
    }
    
    void push(int x) {
        freq[x]++;
        maxm=max(freq[x],maxm);
        mstack[freq[x]].push(x);
    }
    
    int pop() {
        int x=mstack[maxm].top();mstack[maxm].pop();
        if(mstack[maxm].size()==0){
            maxm--;
        }
        return x;
    }
};
int main(){

}