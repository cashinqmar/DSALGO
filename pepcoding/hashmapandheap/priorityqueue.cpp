#include <iostream>
#include <vector>

using namespace std;

vector<int> pq;

void display()
{
    for (int ele : pq)
        cout << ele << " ";
    cout << endl;
}

void upheapify(int ci,bool down)
{
    if(down){
int pi = (ci - 1) / 2;
    if (pi >= 0 && pq[pi] < pq[ci])
    {
        swap(pq[pi], pq[ci]);
        upheapify(pi,down);
    }
    }
    else{
        int pi = (ci - 1) / 2;
    if (pi >= 0 && pq[pi] > pq[ci])
    {
        swap(pq[pi], pq[ci]);
        upheapify(pi,down);
    }
    }
    
}

void downHeapify(int pi,bool down)
{
    int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;
    int maxi = pi;
    if(down){
  if (lci < pq.size() && pq[lci] > pq[maxi])
        maxi = lci;
    if (rci < pq.size() && pq[rci] > pq[maxi])
        maxi = rci;

    if (maxi != pi)
    {
        swap(pq[maxi], pq[pi]);
        downHeapify(maxi,down);
    }
    }
    else{
          if (lci < pq.size() && pq[lci] < pq[maxi])
        maxi = lci;
    if (rci < pq.size() && pq[rci] < pq[maxi])
        maxi = rci;

    if (maxi != pi)
    {
        swap(pq[maxi], pq[pi]);
        downHeapify(maxi,down);
    }
    }
  
}

void push(int val,bool down)
{
    pq.push_back(val);
    upheapify(pq.size() - 1,down);
}

void pop(bool down)
{
    int n = pq.size() - 1;
    swap(pq[0], pq[n]);
    pq.erase(pq.begin() + n);
    downHeapify(0,down);
}

int top()
{
    return pq[0];
}

void heapify(int pi,int ei,bool down)
{
    if(down){
 int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;
    int maxi = pi;

    if (lci <=ei && pq[lci] > pq[maxi])
        maxi = lci;
    if (rci <=ei&& pq[rci] > pq[maxi])
        maxi = rci;

    if (maxi != pi)
    {
        swap(pq[maxi], pq[pi]);
        heapify(maxi,ei,down);
    }
    }
    else{
         int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;
    int maxi = pi;

    if (lci <=ei && pq[lci] < pq[maxi])
        maxi = lci;
    if (rci <=ei&& pq[rci] <pq[maxi])
        maxi = rci;

    if (maxi != pi)
    {
        swap(pq[maxi], pq[pi]);
        heapify(maxi,ei,down);
    }
    }
   
}

void heapsort(int si,int ei,bool down){


    
if(si>ei)return ;
swap(pq[si],pq[ei]);
heapify(si,ei-1,down);
heapsort(si,ei-1,down);
}


void SetPriorityQueue(vector<int> &arr,bool down)
{
    for (int ele : arr)
        pq.push_back(ele);

    for (int i = pq.size() - 1; i >= 0; i--)
        downHeapify(i,down);
}



void set1()
{    bool down=false;
    vector<int> arr{10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13,100,-100};
    SetPriorityQueue(arr,down);

    // while (pq.size() != 0)
    // {
    //     cout << top() << " ";
    //     // display();
    //     pop(down);

    // }

    heapsort(0,pq.size()-1,down);
    for(auto i:pq)cout<<i<<" ";
}

void solve()
{
    set1();
}

int main()
{
    solve();
    return 0;
}