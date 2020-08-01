#include<iostream>
#include<algorithm>
using namespace std;
class vector{
	
public:
	int *arr;
	int curr_size;
	int max_size;
	vector()
	{
		max_size = 1;
		arr=new int[max_size];
		curr_size=0;
	}

	vector(vector &a)
	{
		arr=a.arr;
		curr_size=a.curr_size;
		max_size=a.max_size;

	}
	vector(int size)
	{
		curr_size = 0;
		max_size=size;
		arr = new int[max_size];
	}
	void push_back(int n)
	{
		*(arr+curr_size) = n;
		curr_size++;
		if(curr_size==max_size)
			{
				int *arr2;
				max_size*=2;
				
				arr2= new int[max_size];
				for(int i=0;i<curr_size;i++)
					arr2[i]=arr[i];
				delete arr;
				arr = arr2;
			}
	}

	int size()
	{
		return curr_size;
	}

	void print()
	{
		for(int i=0;i<curr_size;i++)
			cout << *(arr+i) << ",";
		cout <<endl;
	}

 	int operator[](int b)
 	{
 		return arr[b] ;
 	}




};

 	ostream & operator<<(ostream &o,vector &v)
 	{
 		for(int i=0;i<v.size();i++)
 		{
 			cout << v.arr[i] << " ";
 		}
 		cout <<endl;
 		return o;
 	}
int main()
{

	vector v1;
	// v1.print();
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.push_back(102);
	v1.print();

cout << v1[2]<<endl;
	vector v2(v1);
	v2.print();
	vector v3 = v1;
	v3.push_back(51);
	v3.print();

cout <<"all elements"<<endl;
cout << v3 << v1;
	// vector v4 = v1+v3;
	// v4.print();
	return 0;

}