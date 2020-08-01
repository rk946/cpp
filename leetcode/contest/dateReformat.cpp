#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

string reformatDate(string date) {
        
        map<string,string> month;
        month.insert({"Jan","01"});
        month.insert({"Feb","02"});
        month.insert({"Mar","03"});
        month.insert({"Apr","04"});
        month.insert({"May","05"});
        month.insert({"Jun","06"});
        month.insert({"Jul","07"});
        month.insert({"Aug","08"});
        month.insert({"Sep","09"});
        month.insert({"Oct","10"});
        month.insert({"Nov","11"});
        month.insert({"Dec","12"});
        
        string day,monthS,year;
        
        stringstream s(date);
        getline(s,day,' ');
        getline(s,monthS,' ');
        getline(s,year,' ');
        
        int l = day.size();
        // string temp="0";
        if(l==3)
        {
            day = day.substr(0,1);
      		day = "0" + day;
        }
        else
        {
            day = day.substr(0,2);
        }

        monthS = month[monthS];

      return year+"-"+monthS+"-"+day;
}
int main()
{

	string s = "31st Jan 1900";
	cout << reformatDate(s);

	// char* token = strtok(s," ");
	return 0;
}