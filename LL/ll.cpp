#include<iostream>
#include<vector>
#include<bits/stdc++.h>
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
<<<<<<< HEAD
=======

>>>>>>> laptop
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
<<<<<<< HEAD

=======
>>>>>>> laptop
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
int main()
{
	node* head=NULL;
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	insertAtHead(head,7);
	insertAtHead(head,8);
	print(head);
<<<<<<< HEAD
	
=======

>>>>>>> laptop
	return 0;
}