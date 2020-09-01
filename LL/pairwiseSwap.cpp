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

node* pairwiseSwap(node*head)
{
	
	if(head==NULL or head->next==NULL)
		return head;
	node*newHead=head->next;
	node*remaining = head->next->next;
	newHead->next = head;
	head->next = pairwiseSwap(remaining);
	return newHead;

}
int main()
{
	node* head=NULL;
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	// insertAtHead(head,8);
	print(head);
	head=pairwiseSwap(head);
	print(head);	

	return 0;
}