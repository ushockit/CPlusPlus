#include <iostream>
#include "Queue.h"
using namespace std;


int main() {

	Queue q(10);

	for (int i = 0; i < 5; i++)
	{
		int item = rand() % 50 + 1;
		q.add(item);
		cout << item << " ";
	}
	cout << endl << endl;

	while (!q.isEmpty()) {
		cout << q.extract() << " ";
	}
	cout << endl;
	

	return 0;
}