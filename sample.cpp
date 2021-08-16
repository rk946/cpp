
#include<iostream>
using namespace std;
  

void print(int *x){
  cout << *x;

}
int main(void)
{ 
  const int* a;
  int b = 15;
  a=&b;
  int*temp = const_cast<int*>(a);
  print(temp);

  return 0;
}