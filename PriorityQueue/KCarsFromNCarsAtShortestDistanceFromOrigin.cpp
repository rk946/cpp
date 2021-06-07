#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Car{
    public:
        int x;
	int y;
        Car(int x, int y)
        {
            this->x = x;
            this->y = y;
}
        
    int dist()
    {

        return x*x+y*y;
}
    void print()
    {
    	cout << x <<" , "<<y<< " , distance = "<<dist()<<"\n";
    }
};
class CarCompare{
public:
bool operator()(Car a, Car b){
    return a.dist() > b.dist();

}};
int main()
{
vector<Car> cars;
cars.push_back(Car(10,2));
cars.push_back(Car(5,13));
cars.push_back(Car(3,7));
cars.push_back(Car(0,6));
cars.push_back(Car(2,3));
priority_queue<Car,vector<Car>, CarCompare> pq;
for(int i=0;i<5;i++)
{
    pq.push(cars[i]);
}
for(int i=0;i<2;i++)
{
Car c =  pq.top();
c.print();
pq.pop();

}
return 0;
}
