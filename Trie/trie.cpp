#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;
	Node(){
		isTerminal=false;
	}
	Node(char c)
	{
		data=c;
		isTerminal=false;
	}
};

class Trie{
public:
	Node*root;
	Trie(){
		root= new Node('\0');
	}
	void insert(string word){
		Node*temp = root;
		for(char c: word)
		{
			if(temp->m.count(c)==0)
			{
				Node*n = new Node(c);
				temp->m[c]=n;		
			}
			temp=temp->m[c];
		}
		temp->isTerminal=true;
	}
	bool search(string word){
		Node*temp = root;
		for(char ch:word)
		{
			if(temp->m.count(ch)==0)
				return false;
			temp=temp->m[ch];
		}
		if(temp->isTerminal==true)
			return true; 
		return false;
	}
};

int main(){
	Trie t;
	t.insert("apple");
	t.insert("ape");
	t.insert("mango");
	if(t.search("app"))
		cout << "Present";
	else
		cout <<"Not Present";
	return 0;
}