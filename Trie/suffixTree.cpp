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
	void insert_helper(string word){
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
	void insert(string word){
		int n = word.length();
		for(int i=0;i<n-1;i++)
		{
			insert_helper(word.substr(i));
		}
	}
};

int main(){

	string s = "hello";
	string suffixes[]={"lo","ell","hello"};

	Trie t;
	t.insert(s);
	for(auto sf:suffixes)
	{
		if(t.search(sf))
			cout <<"Yes ";
		else
			cout <<"No";
	}
	
	return 0;
}