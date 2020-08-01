#include<iostream>
#include<vector>
#include<algorithm>


//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]


// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
using namespace std;
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int f,s;
        f=newInterval.front();
        s=newInterval.back();
        cout << f << " " <<s <<endl;
        int i=0;
        for(vector<int> v:intervals)
        {
        	vector<int> v1 = v.at(i);
        	if(v1.front()>f)
        		break;
        	else
        		i++;
        }
        i--;
        int j=0;
        for(vector<int> v:intervals)
        {
        	vector<int> v1 = v.at(j);
        	if(v1.at(j).end()>s)
        	{
        		if(v1.at(j).begin()<s)
        			j--;
        		break;
        	}
        	else
        		j++;
        }

        if(i<j)
        {
        	for(int k=i+1;k<j;k++)
        	{
        		intervals.erase(k);
        	}
        }

        intervals.at(i).at(1) = intervals.at(j).at(0);
        intervals.erase(j);


        return intervals;
    }
int main()
{
    vector<vector<int>> intervals {{1,3},{6,9}};
    vector<int> newInterval {2,5};

    insert(intervals,newInterval); 


	return 0;
}