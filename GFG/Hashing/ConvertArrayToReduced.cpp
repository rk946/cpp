#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main()
{
	vector<int> arr = {5,15,35,55,25,45};
	//output = {0,1,3,5,2,4}
	map<int,int> s;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		s[arr[i]] = i;
	}
	
	for(auto it=s.begin();it != s.end() ; it++)
	{
		cout << it->first << " , "<<it->second<<endl;
	}

	// vector<int> res;
	// int i=0;
	// for(auto it = s.begin(); it != s.end();it++)
	// {
	// 	res.push_back(s[arr[i]]);
	// 	cout << s[arr[i]];
	// 	i++;
	// }
 




	return 0;
}