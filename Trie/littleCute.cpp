#include<bits/stdc++.h>

using namespace std;

/*
Given a paragraph/document and a list of words which needs to found in the 










*/


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
};

void searchWordHelper(string document, int i, unordered_map<string,bool>&m, Trie &t)
{
	Node*temp = t.root;
	for(int j=i;j<document.length();j++)
	{
		
		if(temp->m.count(document[j])==0)
		{
			return;
		}
		temp = temp->m[document[j]];
		if(temp->isTerminal==true)
		{
			string temps = document.substr(i,j-i+1);
			m[temps]=true; 
			return;
		}

	}
}

void searchWord(string document, vector<string> words)
{
	Trie t;
	for(string s:words)
		t.insert(s);

	unordered_map<string,bool> m;
	for(string word:words)
		m[word]=false;
	for(int i=0;i<document.length();i++)
	{
		searchWordHelper(document,i,m,t);
	}
	cout << m.size()<<endl;
	for(auto element:m)
	{
		if(element.second)
			cout << element.first <<" : "<<"Yes"<<endl;
		else
			cout << element.first << " : "<<"No"<<endl;
	}


}

int main(){
	
	string document = "little cute cat loves to code in c++, java & python";
	vector<string> words = {"cute cat","ttle","cat","quick","big"};
	searchWord(document,words);
	return 0;
}