#include <iostream>
#include "SmartPointer.h"

using namespace std;

int main() {
	
	SmartPointer ptr1(10);
	SmartPointer ptr2 = ptr1;

	cout << &ptr1 << endl;
	cout << &ptr2 << endl;

	system("pause");
	return 0;
}