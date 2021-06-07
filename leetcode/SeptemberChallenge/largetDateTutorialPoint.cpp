#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  
   bool isValid(const string a) {

      if (a[0] > '2')
         return false;
         if (a[0] == '2' && a[1] > '3')
            return false;
         if (a[3] > '5')
            return false;
         return true;
   }
   void dfs(vector<int>& A, string& res, string& cur) {
    static int count=0;

      if (cur.size() == 5) {
        cout <<cur<<" , "<<++count<<endl;
        
         if (isValid(cur) && cur > res)
            res = cur;
            return;
         }
         for (int i = 0; i < 4; ++i) {
            if (A[i] != -1) {
               int tmp = A[i];
               cur += A[i] + '0';
            if (cur.size() == 2)
               cur += ':';
               A[i] = -1;
               dfs(A, res, cur);
               A[i] = tmp;
               cur.pop_back();
               if (cur.size() == 2)
                  cur.pop_back();
            }
         }
   }
  
 string largestTimeFromDigits(vector<int>& A) {
         string res = "", tmp = "";
      dfs(A, res, tmp);
      return res;
    }


int main()
{
 
 	vector<int> A;
 	for(int i=0;i<4;i++)
 	{
 		int a;
 		cin>>a;
 		A.push_back(a);
 	}
 	string s = largestTimeFromDigits(A);
 	cout << s<<endl;
    // cout <<count <<endl;
	return 0;
}