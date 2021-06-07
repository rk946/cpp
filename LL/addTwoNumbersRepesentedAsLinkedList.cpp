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
 
class Solution {
public:
    
    void reverse(ListNode*&head)
    {
        if(head==NULL and head->next==NULL)
            return;
        ListNode*curr= head,*prev=NULL,*temp;
        while(curr!=NULL)
        {
            
            temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
            // curr = curr->next;
        }
        head=prev;
    }
    
    void add(ListNode*&head1,ListNode*head2)
    {
        int carry=0;
        ListNode*temp1=head1,*temp2=head2,*prev=NULL;
        while(temp1!=NULL and temp2!=NULL)
        {
            int digitsum = temp2->val+carry+temp1->val;
            temp1->val = digitsum%10;
            carry = digitsum/10;
            prev=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp2!=NULL)
        {
            prev->next=temp2;
            temp1 = temp2;
        }
        while(temp1!=NULL){
            int digitsum = carry+temp1->val;
            temp1->val = digitsum%10;
            carry = digitsum/10;
            prev = temp1;
            temp1=temp1->next;
        }
        if(carry!=0)
            prev->next = new ListNode(carry);
    }
    
    void printll(ListNode*head)
    {
        ListNode*temp = head;
        while(temp!=NULL)
        {
            cout <<temp->val<<" -> ";
            temp=temp->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        // printll(l1);
        // cout << endl;
        // printll(l2);
        // cout << endl;
        reverse(l1);
        reverse(l2);
        add(l1,l2);
        // reverse(l1);
        printll(l1);
        cout << endl;
        // printll(l2);
        // cout << endl;
        
        
        
        return l1;
    }
};

int main()
{
    ListNode *l1 = new ListNode(5);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

   ListNode *l2 = new ListNode(7);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    s.reverse(l1);
    s.reverse(l2);
    s.add(l1,l2);
    s.reverse(l1);
    s.printll(l1);
    return 0;
}