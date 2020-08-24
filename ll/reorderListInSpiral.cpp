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



void insertAtHead(node * &head, int data)
{
	node *n = new node(data);
	n->next = head;
	head = n;
}
void insertAtTail(node *&head,int data)
{
	if(head==NULL)
	{
		head= new node(data);
		return;
	}
	node * temp = head;
	while(temp->next!=NULL)
		temp=temp->next;
	// temp->next = head->next;
	// head->next=temp;
	temp->next = new node(data);

}

void insertAtMiddle(node*head,int data, int p)
{
	int i=0;
	while(i!=p-1)
	{
		head=head->next;
		i++;
	}
	node * temp = new node(data);
	temp->next = head->next;
	head->next = temp;
}
void print(node*head)
{
	while(head!=NULL)
	{
		cout << head->data << "->";
		head=head->next;
	}
	cout <<endl;
}

void deleteAtHead(node*&head)
{
	if(head==NULL)
		return;
	node*temp = head;
	head=head->next;
	delete temp;
}

void deleteAtTail(node*&head)
{
	if(head==NULL)
		return;
	node*temp=head, *prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	delete temp;
}
int size(node*&head)
{
	node*temp=head;
	int i=1;
	while(temp->next!=NULL)
	{
		i++;
		temp=temp->next;
	}
	return i;
}
void deleteInMiddle(node*&head, int p)
{
	if(head==NULL)
		return;
	if(p>size(head))
		return;
	node *prev=NULL, *temp=head;
	while(p-1!=0)
	{
		p--;
		prev=temp;
		temp=temp->next;

	}
	prev->next = temp->next;
	delete temp;
}
void buildll(node *&head)
{

	int data;
	cin>>data;
	while(data!=-1)
	{
		insertAtTail(head,data);
		cin>>data;

	}

}


istream& operator>>(istream &is, node *&head)
{
	buildll(head);
	return is;
}


ostream& operator<<(ostream &os, node *&head)
{
	print(head);
	return os;
}

void reverse(node*&head)
{
	node *prev=NULL,*curr=head,*next=head;
	while(curr->next!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev = curr;
		curr = next;
	}
	head=curr;
}

    void reorderList(node* head) {
    	// cout << "in reorderList";
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        
        node *temp=head,*it=head,*itPrev=NULL,*prev=NULL;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        temp->next=it->next;
        itPrev = it;
        it=it->next;
        itPrev->next=temp;
        prev->next=NULL;
        print(head);
        reorderList(it);
    }

int main()
{

	node *head=NULL;
	cin>>head;
	// cout<<head;

	reorderList(head);
	cout << "final"<<endl;
	cout<<head;
		return 0;
}