#include <iostream>
#include <map>
#include <vector>
#include <Windows.h>
using namespace std;


void print1(int a) {
	cout << "-= " << a << " =-" << endl;
}

void print2(int a) {
	cout << "*| " << a << " |*" << endl;
}

void showArray(int arr[], int size, void (*print)(int)) {
	while (size > 0) {
		print(*arr);
		arr++;
		size--;
	}
}


int sum(int a, int b) {
	return a + b;
}

int diff(int a, int b) {
	return a - b;
}

int mult(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}

int main() {
	//setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*map<string, string> map;

	map.insert(make_pair("Key1", "Value1"));
	map.insert(make_pair("Key2", "Value2"));
	map.insert(make_pair("Key3", "Value3"));

	auto it = map.begin();

	while (it != map.end()) {
		pair<string, string> pair = (*it);
		cout << "Key = " << pair.first << 
			" Value = " << pair.second << " " << endl;
		it++;
	}*/


	/*map<string, vector<string>> dict;

	vector<string> vals;
	vals.push_back("Книга");
	vals.push_back("Бронировать");
	dict.insert(make_pair("Book", vals));

	vector<string> vals2;
	vals2.push_back("Оранжевый");
	vals2.push_back("Апельсин");
	dict.insert(make_pair("Orange", vals2));


	auto it = dict.begin();

	while (it != dict.end()) {
		pair<string, vector<string>> pair = (*it);
		//auto pair = (*it);
		cout << pair.first << endl;
		//проход по вектору
		auto it2 = pair.second.begin();
		while (it2 != pair.second.end()) {
			cout << "  " << (*it2) << endl;
			it2++;
		}
		it++;
	}*/



	/*void (*ptr)(int);

	ptr = print1;
	ptr(10);

	ptr = print2;
	ptr(20);*/

	/*int arr[5] = { 1, 2, 3, 4, 5 };

	//showArray(arr, 5, print1);
	showArray(arr, 5, print2);


	map<char, int(*)(int, int)> actions;

	actions.insert(make_pair('+', sum));
	actions.insert(make_pair('-', diff));
	actions.insert(make_pair('*', mult));
	actions.insert(make_pair('/', division));



	auto it = actions.find('*');
	//действие найдено
	if (it != actions.end()) {
		int result = (*it).second(10, 20);
		cout << "Result = " << result << endl;
	}

	char action = '*';
	int a = 10, b = 20;
	int result = 0;
	switch (action) {
	case '+':
		result = sum(a, b);
		break;
	case '-':
		result = diff(a, b);
		break;
	case '*':
		result = mult(a, b);
		break;
	case '/':
		result = division(a, b);
		break;
	}

	cout << "Result = " << result << endl;*/

	map<int, string> map;

	map.insert(make_pair(1, "Hello"));
	map.insert(make_pair(1, "World"));


	auto it = map.begin();

	while (it != map.end()) {
		cout << (*it).first << " - " << (*it).second << endl;
		it++;
	}



	return 0;
}