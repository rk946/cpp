#include<iostream>
#include<string>
// #include<cstring>
#include "hashtable.h"

using namespace std;

int main()
{

	HashTable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Coke",40);
	price_menu.print();

	int *value = price_menu.search("Noodles");
	if(value == NULL)
		cout << "Not found"<<endl;
	else
		cout << "Price is = "<<*value<<endl;

	price_menu.erase("Pepsi");
	price_menu.print();

	price_menu["Dosa"]=60;
	cout << " Price = "<<price_menu["Dosa"]<<endl;
	price_menu["Dosa"]+=10;
	cout << " Price = "<<price_menu["Dosa"]<<endl;

	return 0;
}