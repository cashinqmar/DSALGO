#include<bits/stdc++.h>
using namespace std;

// maxheap
class mypq{
   
void upheapify(vector<int> &arr,int childindex){
    int parentindex=(childindex-1)/2;
    if(arr[parentindex]<arr[childindex]){
        swap(arr[parentindex],arr[childindex]);
        upheapify(arr,parentindex);
    }
    else return;
}

void downheapify(vector<int> &arr,int parentindex){
    int leftchild=parentindex*2+1;
    int rightchild=parentindex*2+2;
    int maxindex=parentindex;

    if(leftchild<arr.size()&&arr[leftchild]>arr[maxindex]){
        maxindex=leftchild;
    }
    if(rightchild<arr.size()&&arr[rightchild]>arr[maxindex]){
        maxindex=rightchild;
    }

    if(maxindex!=parentindex){
        swap(arr[parentindex],arr[maxindex]);
        downheapify(arr,maxindex);
    }
}

 public:
 vector<int> arr;
void print(){
    for(auto i:arr)cout<<i<<" ";
    cout<<'\n';
}

void add(int val){
    arr.push_back(val);
    upheapify(arr,arr.size()-1);
}

int top(){
    return arr[0];
}

int pop(){
    int s=arr.size();
    swap(arr[0],arr[s-1]);
    int x=arr[s-1];
    arr.pop_back();
    downheapify(arr,0);
    return x;
}

mypq(){
    // arr.resize(0);
}
};

int main(){
mypq pq;
pq.add(10);
pq.add(20);
pq.add(30);

// cout<<pq.top()<<"\n";

pq.add(40);
pq.add(50);
pq.add(60);

// cout<<pq.pop()<<"\n";

// pq.print();

// cout<<pq.top()<<"\n";
cout<<pq.pop()<<"\n";
cout<<pq.pop()<<"\n";

cout<<pq.pop()<<"\n";
// pq.print();
// pq.top();
cout<<pq.pop()<<"\n";
cout<<pq.pop()<<"\n";


}