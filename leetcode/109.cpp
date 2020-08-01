#include<iostream>
#include<queue>
using namespace std;


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


    ListNode * findMiddle(ListNode *head)
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode * slow=head,*fast=head->next;
        while(fast !=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
        	return NULL;
        if(head->next ==NULL)
        	return new TreeNode(head->val);
        ListNode * prev=NULL,*slow=head,*fast=head->next;
        while(fast!=NULL)
        {
        	prev = slow;
        	slow = slow->next;
        	fast = fast->next;
        	if(fast!=NULL)
        		fast=fast->next;
        }
        prev->next = NULL;
        TreeNode * root = new TreeNode(slow->val);
  root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
      
        return root;
    }

    void printTree(TreeNode * root)
    {
    	if(root==NULL)
    		return;
    	cout<< root->val;
    	printTree(root->left);
    	printTree(root->right);
    }

    void printList(ListNode *head)
    {
    	while(head!=NULL)
    	{
    		cout << head->val << "-->";
    		head=head->next;
    	}
    	cout << endl;
    }

    void BFSwithNewLine(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		TreeNode * f = q.front();
		if(f==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout << f->val << " ";
			q.pop();
if(f->left!=NULL)
			q.push(f->left);
		if(f->right!=NULL)
			q.push(f->right);
		}


	}
}
    int main()
    {
    	ListNode * head;
    	head = new ListNode(1);
    	head->next = new ListNode(2);
    	head->next->next = new ListNode(3);
    	head->next->next->next = new ListNode(4);
    	head->next->next->next->next = new ListNode(5);
    	head->next->next->next->next->next = new ListNode(6);
    	printList(head);
    	TreeNode * root = sortedListToBST(head);
    	printTree(root);
    	cout <<endl;
    	BFSwithNewLine(root);
    	return 0;
    }