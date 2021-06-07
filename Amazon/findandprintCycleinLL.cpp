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

	bool checkloop(ll *head)
	{
		ll *slow = head,*fast=head;
		while(fast!=NULL and fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
			if(slow==fast)
				return true;
		}
		return false;

	}
	void printloop(ll *head)
	{
		ll *slow = head,*fast=head;
		bool looppresent=false;
		while(fast!=NULL and fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
			if(slow==fast)
			{
				looppresent=true;
				break;
			}
		}
		if(!looppresent)
		{
			cout << "loop not present"<<endl;
			return;
		}

		slow=head;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
		cout<<"Printing loop"<<endl;
		cout << slow->val<<" ";
		slow=slow->next;

		while(slow!=fast)
		{
			cout << slow->val<<" ";
		slow=slow->next;
		}

		

	}
	
};

int main(){
	ll *l=new ll(1);
	l->next = new ll(2);
	ll *loop=new ll(3);
	l->next->next =loop;
	loop->next = new ll(4);
	loop->next->next = loop;

	if(l->checkloop(l))
		cout <<"loop present"<<endl;
	else
		cout <<"loop not present"<<endl;

	l->printloop(l);


	return 0;
}