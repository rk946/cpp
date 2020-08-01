#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Stack{
private:
	vector<T> v;
public:
	void push(T data)
	{
		v.push_back(data);
	}
	bool empty()
	{
		return v.size()==0;
	}
	T top()
	{
		if(!empty())
		{
			return v[v.size()-1];
		}
	}
	void pop()
	{
		if(!empty())
		{
			v.pop_back();
		}
	}
};


int main()
{
	Stack<string> s;
	s.push("Hello");
	s.push("World");
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;

	return 0;
}