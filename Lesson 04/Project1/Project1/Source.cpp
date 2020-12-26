#include <iostream>
#include "List.h"


using namespace std;


int main() {

	List list;

	list.addToTail(10);
	list.addToTail(20);
	list.addToTail(30);
	list.addToTail(40);
	list.addToHead(100);
	list.addToHead(200);

	//list.removeFromHead();

	//list.removeFromTail();

	list.removeAt(4);
	list.removeAt(0);
	list.removeAt(2);

	list.print();


	system("pause");
	return 0;
}