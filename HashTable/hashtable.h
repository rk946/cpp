#include<iostream>
#include<string>
// #include<cstring>

using namespace std;


template<typename T>
class Node{
public: 
	string key;
	T value;
	Node<T> *next;
	Node(string key, T val)
	{
		this->key = key;
		value=val;
		next=NULL;
	}

	~Node()
	{
		if(next!=NULL)
		{
			delete next;
		}
	}

};



template<typename T>
class HashTable{

	Node<T>** table;
	int table_size;
	int curr_size;

	int HashFn(string key)
	{
		int index=0;
		int power=1;
		for(int i=0;i<key.length();i++)
		{
			// index = index+(key[i]*power)%table_size
			index = index+(key[i]*power)%table_size;
			index = index%table_size;
			power = (power*27)%table_size;
		}
		return index;
	}


	void rehash()
	{
		// cout << "rehashed called";
		Node<T> **oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		curr_size=0;
		table = new Node<T>*[table_size];
		for(int i=0;i<oldTableSize;i++)
		{
			//get pointer of first element of linked list
			Node<T> *temp = oldTable[i];
			//iterate over linked list
			while(temp!=NULL)
			{
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			if(oldTable[i]!=NULL)
				delete oldTable[i];
		}
		delete [] oldTable;
	}

public:
	HashTable(int ts=7)
	{
		table_size = ts;
		curr_size=0;
		table = new Node<T>*[table_size];
		for(int i=0;i<table_size;i++)
		{
			table[i]=NULL;
		}
	}

	void insert(string key, T value)
	{
		//get index
		int index = HashFn(key);
		//create a node of key value pair
		Node<T> *newNode = new Node<T>(key,value);
		//insert the new node at the head
		newNode->next = table[index];
		table[index]=newNode;
		curr_size++;
		
		float load_factor = curr_size/(1.0*table_size);
		
		if(load_factor>0.7)
		{
			// rehash();
		}

	}

	void print()
	{
		for(int i=0;i<table_size;i++)
		{
			cout<<"Bucket "<<i<<" -> ";
			Node<T> * temp = table[i];
			while(temp!=NULL)
			{
				cout << temp->key <<" , "<< temp->value<<" -> ";
				temp=temp->next;
			}
			cout <<endl;
		}
	}

	T* search(string key)
	{
		for(int i=0;i<table_size;i++)
		{
			Node<T>*temp = table[i];
			while(temp!=NULL)
			{
				if(temp->key==key)
					return &temp->value;
				temp=temp->next;
			}
		}
		return NULL;

	}
	void erase(string key)
	{
		for(int i=0;i<table_size;i++)
		{
			Node<T>*temp=table[i];
			Node<T>*prev=NULL;
			while(temp!=NULL)
			{
				if(temp->key==key)
				{
					if(prev==NULL)
					{
						table[i] = temp->next;
					}
					else
					{
						prev->next = temp->next;
					}
					temp->next=NULL;
					delete temp;
					return;

				}
				else
				{
					prev=temp;
					temp=temp->next;
			}
			}
		}
	}

	T& operator [](string key)
	{
		T *f=search(key);
		if(f==NULL)
		{
			T garbage;
			insert(key,garbage);
			f=search(key);
		}
		return *f;
	}

};



