#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Person{
	public:
		int age;
		string name;
		Person(int age,string name)
		{
			this->age = age;
			this->name = name;
		}
};

class comparePerson{
public:
	bool operator ()(const Person p1, const Person p2){
		return (p1.name<p2.name);

	}
};

int main(){
	priority_queue<Person,vector<Person>,comparePerson> pq;
	Person p1(65,"Sam");
	pq.push(p1);
	pq.push(Person(35,"Sam2"));
	pq.push(Person(15,"Sam3"));
	pq.push(Person(55,"Sam4"));
	pq.push(Person(45,"Sam5"));


	while(!pq.empty())
	{
		Person p = pq.top();
		cout<<p.age<<" "<<p.name<<endl;
		pq.pop();
	}
	return 0;
}