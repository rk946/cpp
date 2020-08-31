#include<iostream>
using namespace std;

class node{
public:
	int data; node*next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
void insertAtHead(node*&head, int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp = new node(data);
	temp->next=head;
	head=temp;
}
int size(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		len++;
		head=head->next;
	}
	return len;
}
void insertAtTail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp = head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = new node(data);
	
} 
void insertInMiddle(node*&head, int data, int p)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	if(p>size(head))
	{
		insertAtTail(head,data);
		return;
	}
	node*temp = head;
	node*temp2 = new node(data);
	while(p-2!=0)
	{
		temp=temp->next;
		p--;
	}
	temp2->next = temp->next;
	temp->next = temp2;

}

void print(node *head)
{
	while(head!=NULL)
	{
		cout << head->data << "->";
		head=head->next;
	}
	cout <<endl;
}
void buildll(node*&head)
{
	int data;
	cin>>data;

	while(data!=-1)
	{
		insertAtTail(head,data);
		cin>>data;
	}
}

istream& operator>>(istream &is,node*&head)
{
	buildll(head);
	return is;
}

ostream& operator<<(ostream &os, node*head)
{
	print(head);
	return os;
}
void reverse(node*&head)
{
	node*curr=head,*prev=NULL,*next=head;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next=  prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

node* findMiddle(node*head)
{
	node*slow=head,*fast=head;
	while(fast !=NULL and fast->next !=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
node *kthNodeFromLast(node*head, int k)
{
	node*slow=head,*fast=head;
	while(k!=1)
	{
		fast = fast->next;
		k--;
	}
	while(fast->next!=NULL)
	{
		fast = fast->next;
		slow=slow->next;
	}
	return slow;
}
void mergeLL(node*&head1,node*head2)
{
	node*temp1=head1,*temp2=head2,*temp3=NULL;
	while(temp1!=NULL and temp2!=NULL)
	{
		if((temp1->data)>(temp2->data))
		{
			insertAtTail(temp3,temp2->data);
			temp2=temp2->next;
		}
		else
		{
			insertAtTail(temp3,temp1->data);
			temp1 = temp1->next;
		}
		if(temp3!=NULL)
			head1 = temp3;

	}
	while(temp1!=NULL)
	{

		insertAtTail(temp3,temp1->data);
		temp1 = temp1->next;
		if(temp3!=NULL)
			head1 = temp3;
	}
	while(temp2!=NULL)
	{
		insertAtTail(temp3,temp2->data);
		temp2 = temp2->next;
		if(temp3!=NULL)
			head1 = temp3;
	}


}
node* mergeLLRec(node*head1,node*head2)
{
	if(head1==NULL)
		return head2;

if(head2==NULL)
		return head1;
	node * head3;
	if(head1->data < head2->data)
	{
		head3 = head1;
		head3->next = mergeLLRec(head1->next,head2);
	}
	else
	{
		head3 = head2;
		head3->next = mergeLLRec(head1,head2->next);
	}
	return head3;
	

}
node* mergeSort(node*head)
{
	if(head==NULL || head->next==NULL)
		return head;

	node*mid = findMiddle(head);
	cout << mid->data<<endl;
	node*a=head;
	node*b=mid->next;
	mid->next=NULL;

	a=mergeSort(a);
	b = mergeSort(b);
	node *c = mergeLLRec(a,b);
	return c;


}

bool detectCycle(node*head)
{
	node*slow=head, *fast=head;
	while(fast!=NULL and fast->next!=NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}
void removeCycle(node*&head)
{
	if(head==NULL || head->next==NULL)
		return;
	node *slow=head,*fast=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	node*prev;
	slow=head;
	while(slow!=fast)
	{
		prev = fast;
		fast=fast->next;
		slow=slow->next;
	}
	prev->next=NULL;
}
int main()
{
	node* head=NULL;
	cin>>head;
	cout<<head;
	cout << detectCycle(head)<<endl;
	if(detectCycle(head))
	removeCycle(head);
	cout << detectCycle(head)<<endl;

	
	return 0;
}