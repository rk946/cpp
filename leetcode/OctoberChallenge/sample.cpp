#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 // * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 


    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL || k==0)
            return head;
        ListNode*fast=head,*slow=head;
        int length=0;
        while(k!=0)
        {
            if(fast!=NULL)
                fast=fast->next;
            else
            {
                fast=head;
                k = k%	length;
                
                cout << k << " , "<< length <<endl;
                length=0;
            }
                
            k--;
            length++;
        }
        if(fast==head)
            return fast;
        ListNode*newHead;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        newHead=slow->next;
        slow->next=NULL;
        fast->next=head;
        return newHead;
        
    }

void printList(ListNode*head)
{
	while(head!=NULL)
	{
		cout << head->val << " -> ";
		head=head->next;
	}
	cout << endl;
}

int main()
{
 	ListNode*head = new ListNode(0);
 	head->next = new ListNode(1);
 	head->next->next = new ListNode(2);
 	printList(head);
 	ListNode*newHead = rotateRight(head,4);
 	printList(newHead);

	return 0;
}