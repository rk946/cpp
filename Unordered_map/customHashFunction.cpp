#include<iostream>
#include<string>
#include<unordered_map>
 
using namespace std;

class Student{
	public:
		string firstName;
		string lastName;
		int rollNo;

	Student(string fn,string ln,int no)
	{
		firstName=fn;
		lastName=ln;
		rollNo=no;
	}


	bool operator ==(const Student &s)const{
		return s.rollNo==rollNo?true:false;
	}
};

class HashFn{
public:
	size_t operator()(const Student &s)const{
		return s.firstName.length()+s.lastName.length();
	}
};
int main()
{
	unordered_map<Student,int,HashFn> s;
	Student s1("Prateek","Kumar",40);
	Student s2("Rahul","Kumar",20);
	Student s3("Rahul","Kumar",10);
	Student s4("Prateek","Narang",30);

	
	s[s1]=36;
	s[s2]=56;
	s[s3]=39;
	s[s4]=76;

	cout << s[s2];

	return 0;
}