#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	
	char a[]="aabcdeabxyzijk";
	int n=strlen(a);
	int visited[256];
	for(int i=0;i<256;i++)
		visited[i]=-1;

	visited[a[0]]=0;
	int curr_len=1;
	int max_len=1;

	for(int i=1;i<n;i++)
	{
		if(visited[a[i]]==-1)
		{
			visited[a[i]] = i;
			curr_len++;
			max_len = max(max_len,curr_len);
		}
		else
		{
			curr_len=i-visited[a[i]];
			visited[a[i]]=i;
			max_len = max(max_len,curr_len);
		}

	}
max_len = max(max_len,curr_len);
cout <<max_len<<endl;


	return 0;

}