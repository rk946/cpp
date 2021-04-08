#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first<b.first;
}

int main(){
    int n, start, end, requiredMeetingHalls = 1;
    cin>>n;
    vector<pair<int,int> > timePeriod;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        timePeriod.push_back(make_pair(start, end));
    }
    sort(timePeriod.begin(), timePeriod.end(), compare);
    int alreadyBookedTime = timePeriod[0].second;
    priority_queue<int> pq;
    pq.push(timePeriod[0].second);
    for(int i=1;i<n;i++){
        cout<<pq.top()<<" "<<timePeriod[i].first<<"\n";
        if(pq.top() < timePeriod[i].first){
            requiredMeetingHalls++;
        } else {
            pq.pop();
        }
        pq.push(timePeriod[i].second);
    }
    cout<<requiredMeetingHalls<<"\n";
}