#include<iostream>
#include<stack>
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
int getMiddle(node *head)
{
	if(head==NULL || head->next == NULL)
	return 0;	
	node*slow=head;
	node*fast=head->next;
	int i=0;
	while(fast!=NULL or fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		i++;
	}
	return i;



}
bool checkPalindrome(node * head)
{
	stack<int> s;
	node*temp=head;
	while(temp!=NULL)
	{
		s.push(temp->data);
		temp=temp->next;
	}

	temp=head;
	while(temp!=NULL)
	{
		if(s.top() != temp->data)
			break;
		s.pop();
		temp=temp->next;

	}
	if(temp!=NULL)
		return false;
	return true;

	

}
int main()
{
	node* head=NULL;
	insertAtHead(head,3);
	// print(head);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,8);
	print(head);
	cout << checkPalindrome(head);

	return 0;
}