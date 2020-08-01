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
int main()
{
	node* head=NULL;
	cin>>head;
	cout<<head;
	node * res = findMiddle(head);
	cout << res->data;
	
	return 0;
}