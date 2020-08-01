#include<iostream>
using namespace std;

class queue{
private:
	int *arr;
	int front,rear;
	int ms,cs;
public:
	queue(int size=7)
	{
		this->ms = size;
		arr = new int[ms];
		front=0;
		rear=ms-1;
		cs=0;
	}

	bool isEmpty(){
		if(cs==0)
			return true;
		else
			return false;
	}

	bool isFull(){
		if(cs==ms)
			return true;
		else
			return false;
	}
	void enque(int data)
	{
		if(!isFull())
		{
			rear = (rear+1)%ms;
			arr[rear] = data;
			cs++;
		}
		else
			cout<<"queue is full";
	}

	void deque()
	{
		if(!isEmpty())
		{
			front = (front+1)%ms;
			cs--;
		}
		else
			cout<<"queue is isEmpty"<<endl;


	}



	int seeTop()
	{
		if(!isEmpty())
			return arr[front];
		else
			return -1;
	}
};
int main()
{
	queue q(5);
	// cout << q.isEmpty()<<endl;
	// cout<<q.seeTop()<<endl;

	for(int i=1;i<=5;i++)
		{q.enque(i*i);}
	for(int i=0;i<5;i++)
	{
		cout << q.seeTop()<<endl;
		q.deque();

	}
cout << q.seeTop()<<endl;
	
	

	return 0;
}