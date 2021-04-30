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
	node() : data(0), next(NULL) {}
	node(int x, node *next) : data(x), next(next) {}
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
	
class solution{

public:

	class comparator{
	public:
		bool operator()(const node*node1, const node*node2) const
		{
			return node1->data < node2->data;
		}
	};
	node* sortLL(node*&head)
	{
		set<node*,comparator> nodeset;
		node*temp = head;
		while(temp!=NULL)
		{
			nodeset.insert(temp);	
			temp = temp->next;
		}
		head = *nodeset.begin();
		temp = head;
		auto it = nodeset.begin();
		it++;
		for(; it!=nodeset.end();it++)
		{
			temp->next = *it;
			temp = temp->next;
		}
		temp->next=NULL;
		return head;
	}
};
int main()
{
	node* head=NULL;
	insertAtHead(head,3);
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,4);
	// insertAtHead(head,5);
	// insertAtHead(head,2);
	print(head);
	solution s;
	head = s.sortLL(head);
	print(head);
	return 0;
}