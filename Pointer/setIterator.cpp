#include<bits/stdc++.h>

using namespace std;

int main(){
	set<int> s;
	for(int i=0;i<10;i++)
		s.insert(i);
	  int maxlen=1;
        int len=1;
        auto it=s.begin();
        it++;
        int i=1;
        for(;it!=s.end();it++){
        	cout << i++<<" ";
            if(*(it) - (*(--it))==1){
                len++;
                
                maxlen = max(maxlen,len);
            }
            else{
                len=1;
            }
                it++;
        }
        cout << endl;
        cout << maxlen<<endl;
	return 0;
}