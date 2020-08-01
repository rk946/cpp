#include<iostream>
using namespace std;


class node{
public:
	int data;
	node*next;
	node(int d)
	{
		this->data=d;
		// next=NULL;
	}
};

void push(node*&head,int data)
{
	node*ptr = new node(data);
	ptr->next = head;
	if(head==NULL)
	{
		
		ptr->next=ptr;
	}
	else{
		
		
		node*temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		
	}
	head = ptr;

}
void printLL(node*head)
{
	node*temp=head;
	while(temp->next!=head)
	{
		cout << temp->data << "->";
		temp=temp->next;
	}
	cout << temp->data <<" END" <<endl;
}
int main()
{
	node*head=NULL;
	push(head,10);
	push(head,20);
	push(head,30);
	push(head,40);
	printLL(head);
	push(head,50);
	printLL(head);
	return 0;
}