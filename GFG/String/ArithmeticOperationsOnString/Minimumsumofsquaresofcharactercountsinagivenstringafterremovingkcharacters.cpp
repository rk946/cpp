#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2 = 9.

Expected Time Complexity: O(k*logn)

Examples:

Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 12 + 12 + 22

Input :  str = aaab, K = 2
Output :  2*/
int MAX_CHAR = 26;

int main()
{
 	string input = "abccc";
 	int k=1;
 	int frequency[MAX_CHAR]={0};
 	priority_queue<int> pq;
 	int n=input.length();
 	for(int i=0;i<n;i++)
 	{
 		frequency[input[i]-'a']++;
 	}

 	for(int i=0;i<MAX_CHAR;i++)
 	{
 		pq.push(frequency[i]);
 	}

 	while(k--)
 	{
 		int temp = pq.top();
 		pq.pop();
 		temp--;
 		pq.push(temp);
 	}
 	int result = 0;
 	while(!pq.empty())
 	{
 		int temp = pq.top();
 		pq.pop();
 		result+= temp*temp;
 	}

 	cout << result;

	return 0;
}