#include<bits/stdc++.h>
using namespace std;

class ll{
public:
	int val;
	ll *next;
	ll(int x){
		val=x;
		next=NULL;
	}

	void printll(ll* head)
	{
		ll*temp=head;
		while(temp!=NULL)
		{
			cout << temp->val<<" ";
			temp=temp->next;
		}
		cout << endl;
	}

ll* reverse(ll*head)
{
	if(head->next==NULL)
		return head;
	ll* newhead=reverse(head->next);
	
	ll*temp=newhead;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head;
	head->next=NULL;
	return newhead;
}	
};



int main(){
	ll *l=new ll(1);
	l->next = new ll(2);
	ll *loop=new ll(3);
	l->next->next =loop;
	loop->next = new ll(4);
	// loop->next->next = loop;
	l->printll(l);
	ll*newhead = l->reverse(l);
	l->printll(newhead);

	


	return 0;
}