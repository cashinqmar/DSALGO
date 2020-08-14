 
 #include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 ListNode *detectCycle(ListNode *head) {

ListNode*slow=head;
ListNode*fast=head;

while(1){
slow=slow->next;
fast=fast->next->next;

if(fast==NULL||fast->next==NULL)return NULL;
if(fast==slow)break;
}
int count=0;
ListNode*start=head;
while(1){
    start->next;
    slow-slow->next;
    if(start==slow)return start;
}
return NULL;

}