#include<bits/stdc++.h>
using namespace std;


string convert_to_digital_time(int minutes){
    //complete this function
    int mins = minutes%60;
    int hours = (minutes-mins)/60;
    string time="";
    string minsString="";
    if(mins<10)
    minsString+="0"+to_string(mins);
    else
    minsString+=to_string(mins);
    time+=to_string(hours)+":"+minsString;
    return time;
    
}
int main()
{
	cout << convert_to_digital_time(1408);
	return 0;
}