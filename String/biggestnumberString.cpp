#include<bits/stdc++.h>
using namespace std;


bool compare(int n1, int n2)
{
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    string s11 = s1+s2;
    string s22 = s2+s1;
    return s11>s22;
}
string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    sort(numbers.begin(),numbers.end(),compare);
    string ans="";
    for(int no:numbers)
    {
        ans+=to_string(no);
    }
    return ans;

}

int main()
{
	vector<int> numbers={10,11,20,30,3};
	cout << concatenate(numbers); D
	return 0;
}