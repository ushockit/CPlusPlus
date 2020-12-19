#include <iostream>
#include "Stack.h"
using namespace std;


int main() {

	Stack stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);



	/*int item = stack.pop();
	std::cout << item << std::endl;*/

	while (!stack.isEmpty()) {
		int item = stack.pop();
		std::cout << item << std::endl;
	}

	return 0;
}