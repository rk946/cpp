
#include<bits/stdc++.h>
using namespace std;
  
  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* reverse(ListNode*head){
    if(head==NULL)
      return head;
    ListNode*curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL){
      next = curr->next;
      curr->next=prev;
      prev = curr;
      curr=next;
    }
    return prev;
  }
ListNode* addTwoNumbers(ListNode*num1, ListNode*num2){
    if(num1==NULL)
      return num2;
    if(num2==NULL)
      return num1;
    num1 = reverse(num1);
    num2 = reverse(num2);
    ListNode*temp1=num1,*temp2=num2,*prev1=NULL;
    int carry=0;
    while(temp1!=NULL and temp2!=NULL){
      temp1->val = temp1->val + temp2->val + carry;
      carry = (temp1->val)/10;
      temp1->val = temp1->val %10;
      prev1 = temp1;
      temp1=temp1->next;
      temp2=temp2->next;
    }
    if(temp2!=NULL){
      prev1->next = temp2;
      temp1 = temp2;
    }
    while(temp1!=NULL){
      if(carry>0){
        temp1->val+=carry;
        temp1->val %=10;
        carry = temp1->val / 10;
      }
      prev1 = temp1;
      temp1 = temp1->next;
    }
    if(carry>0)
      prev1->next = new ListNode(carry);
    num1 = reverse(num1);
    return num1;
      
}  
int main(void)
{ 
  ListNode*num1 = new ListNode(5);
  num1->next = new ListNode(3);
  num1->next->next = new ListNode(8);

  ListNode*num2 = new ListNode(6);
  num2->next = new ListNode(7);
  num2->next->next = new ListNode(9);

  ListNode*num3 = addTwoNumbers(num1,num2);
  ListNode*temp3 = num3;
  while(temp3!=NULL){
    cout << temp3->val<<"->";
    temp3 = temp3->next;
  }

  return 0;
}