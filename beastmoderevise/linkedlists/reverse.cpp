#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

ListNode* reverseList(ListNode* head) {
ListNode* temp=head;
ListNode*prev=NULL;
ListNode* next=nullptr;

while(temp!=NULL){
next=temp->next;
temp->next=prev;
prev=temp;
temp=next;
}

return temp->next;
}
