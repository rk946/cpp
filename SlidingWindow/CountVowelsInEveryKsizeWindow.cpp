#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
	if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
		return true;
	return false;
}

vector<int> count(string s, int k)
{
	int n = s.length();
	vector<int> ans;
	if(n==0)
		return ans;
	int countVowel=0;
	for(int i=0;i<k;i++)
	{
		if(isVowel(s[i]))
			countVowel++;
	}
	ans.push_back(countVowel);
	for(int i=k;i<n;i++)
	{
		if(isVowel(s[i-k]))
			countVowel--;
		if(isVowel(s[i]))
			countVowel++;
		ans.push_back(countVowel);
	}
	return ans;


}


int main()
{
	string s = "aesbvisdosdf";
	int k=3;
	vector<int> ans = count(s,k);
	for(auto i:ans)
		cout << i <<" ";
	return 0;
}