#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"

using namespace std;


int main() {

	PriorityQueue q(30);


	for (int i = 0; i < 20; i++)
	{
		int item = rand() % 100 + 1;
		int priority = rand() % 5 + 1;
		q.add(item, priority);
	}

	q.show();
	q.showByPriorities();

	return 0;
}