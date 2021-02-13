#include <iostream>

using namespace std;


void ex01(const int* ptr) {
	int* tmp = const_cast<int*>(ptr);
	*tmp = *tmp + 10;
}


class A {
public:
	virtual void demo() {
		cout << "Hello demo of the A class" << endl;
	}
};

class B : public A {
public:
	void demo() override {
		cout << "Hello demo of the B class" << endl;
	}
};

int main() {
	/*
		static_cast<>
		reinterpret_cast<>
		dynamic_cast<>
		const_cast<>
	*/

	// -= const_cast<> =-
	/*int x = 10;
	ex01(&x);
	cout << "x = " << x << endl;*/

	// -= dynamic_cast<> =-
	/*A* ptrA, objA;
	B* ptrB, objB;

	ptrB = dynamic_cast<B*>(&objB);

	if (ptrB) {
		ptrB->demo();
	}


	ptrA = dynamic_cast<A*>(&objB);

	if (ptrA) {
		ptrA->demo();
	}*/

	// -= static_cast<> =-
	/*int a = 10, b = 3;
	double c = 0.0;
	c = static_cast<double>(a) / b;
	cout << "c = " << c << endl;*/

	// -= reinterpret_cast<> =-
	/*int value;
	const char* str = "Hello my dear friend!!!";

	value = reinterpret_cast<int>(str);
	cout << value << endl;
	char* str2 = reinterpret_cast<char*>(value);
	cout << str2 << endl;*/
	/*int val = 2464560;
	char* str = reinterpret_cast<char*>(val);
	cout << str << endl;*/

	


	string str = "10+35";

	int idx = str.find('+');
	cout << idx << endl;

	string first = str.substr(0, idx);
	cout << first << endl;

	string second = str.substr(idx + 1);
	cout << second << endl;

	int a = atoi(first.c_str());
	int b = atoi(second.c_str());
	cout << a << " + " << b << " = " << a + b << endl;



	return 0;
}