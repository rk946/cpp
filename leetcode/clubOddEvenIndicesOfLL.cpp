#include<iostream>

using namespace std;

class node{
public:
	int data;
	node * next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

 
void club(node *head)
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return head;
	node*head2=head->next;
	

}

int main(){

	node *head=new node(1);
	node*temp=head;
	for(int i=0;i<5;i++)
	{
		temp->next=new node(i+2);
		temp=temp->next;
	}

	cout << "original linked list"<<endl;
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->data<<"->";
		temp=temp->next;
	}
	cout << endl;
	cout << "linked list after clubbing"<<endl;
	club(head);
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->data<<"->";
		temp=temp->next;
	}
	cout << endl;

	return 0;
}