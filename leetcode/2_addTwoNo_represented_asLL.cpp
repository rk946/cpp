#include<iostream>
#include<bits/stdc++.h>
using namespace std;



/*
2. Add Two Numbers
Medium

9488

2392

Add to List

Share
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


*/


 // * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

      void printLL(ListNode*head)
    {
    	ListNode*temp = head;
    	while(temp!=NULL)
    	{
    		cout << temp->val <<" -> ";
    		temp = temp->next;
    	}
    	cout << endl;
    }

ListNode* reverseLL(ListNode*l)
    {
        ListNode*curr=l,*prev=NULL,*next;
        while(curr!=NULL)
        {
        	next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        // printLL(l1);
        // printLL(l2);
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        // printLL(l1);
        // printLL(l2);
        
        ListNode*temp1=l1,*temp2=l2,*l3=NULL,*temp3=NULL;
        int carry = 0;
        while(temp1!=NULL and temp2!=NULL)
        {
            int d = temp1->val + temp2->val + carry;
            carry = d/10;
            d = d%10;
            if(l3==NULL)             
            {
                l3 = new ListNode(d);
                temp3 = l3;
            }
            else
            {
            	temp3->next = new ListNode(d);
            	temp3 = temp3->next;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
            // printLL(l3);
        
            
        }
        
        while(temp1!=NULL)
        {
        	int d = temp1->val + carry;
            carry = d/10;
            d = d%10;
            temp3->next = new ListNode(d);
            temp3 = temp3->next;
            temp1 = temp1->next;
            
        }
        while(temp2!=NULL)
        {
        	int d = temp2->val + carry;
            carry = d/10;
            d = d%10;
            temp3->next = new ListNode(d);
            temp3 = temp3->next;
            temp2 = temp2->next;
            
        }
        if(carry==1)
        	temp3->next = new ListNode(carry);
        return l3;
    }



/*
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
int main()
{
 
	ListNode*l1,*l2;
	l1 = new ListNode(9);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	l1->next->next->next = new ListNode(9);
	l1->next->next->next->next = new ListNode(9);
	l1->next->next->next->next->next = new ListNode(9);
	l1->next->next->next->next->next->next = new ListNode(9);
	
	l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(9);
	l2->next->next->next = new ListNode(9);


	ListNode*l3 = addTwoNumbers(l1,l2);
	printLL(l3); 



	
	return 0;
}