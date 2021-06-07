    #include <iostream>  
    #include <set> 
    #include<bits/stdc++.h> 
      
    using namespace std;  
    
 vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> m;
        unordered_map<char,char> m1;
        int n = words.size();
        int len = pattern.length();
        vector<string> ans;
        for(string s:words)
        {
            if(s.length()!=len)
                continue;
            else
            {
                m.clear();
                m1.clear();
                bool flag=false;
                // s.clear();
                for(int i=0;i<len;i++)
                {
                    char c = pattern[i];
                    if(m.count(c)==0 and m1.count(s[i])==0)
                    {
                        m[c]=s[i];
                        m1[s[i]] = c;
                    }
                    else if(s[i]!=m[c])
                    {
                        flag=true;
                        break;
                    }
                        
                        
                }
                if(!flag)
                    ans.push_back(s);
                    
            }
            
        }
        return ans;
        
    }

    int main()  
    {  
     string s1 = "3";
     string s2="39";
     if(s1<s2)
      cout <<"s1 is smaller";
    else
      cout << "s2 is smaller";
     return 0;
    }  