#include <iostream>
#include <algorithm>
#include <vector>
#include "Person.h"
#include "Source.h"

using namespace std;


void fillVector(vector<int>& nums, int size) {
	for (int i = 0; i < size; i++)
	{
		nums.push_back(rand() % 100 + 1);
	}
}
void printVector(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}


void printNum(int n) {
	cout << "-= " << n << " =-" << endl;
}

bool evenNum(int n) {
	return n % 2 == 0;
}

bool oddNum(int n) {
	return n % 2 == 1;
}


bool greatherThatZero(int n) {
	return n > 0;
}

void printPeopleList(vector<Person>& people)
{
	for_each(people.begin(), people.end(), [](const Person& person) {
		cout << person << endl;
	});
}

int main() {

	vector<int> values;

	fillVector(values, 15);
	printVector(values);

	//-= Работа с функциями библиотеки "algorithm" =-

	//вывод элементов
	//for_each(values.begin(), values.end(), printNum);

	//поиск значения по заданному условию
	/*auto it = find_if(values.begin(), values.begin(), evenNum);
	auto it2 = find_if(values.begin(), values.end(), oddNum);

	//значение было найдено
	if (it != values.end()) {
		cout << "Even num was found - " << *it << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	if (it2 != values.end()) {
		cout << "Odd num was found - " << *it2 << endl;
	}
	else {
		cout << "Not found" << endl;
	}*/


	//все значения соответствуют заданному условию
	/*values[1] = -10;
	bool result = all_of(values.begin(), values.end(), greatherThatZero);

	if (result) {
		cout << "All nums > 0" << endl;
	}
	else {
		cout << "Some num is <= 0" << endl;
	}*/


	//-= Лямбда выражения =-
	/*
		[](){}
		[](параметры) {
			...тело функции
		}
	*/
	//вывод значений
	/*for_each(values.begin(), values.end(), [](int n) {
		cout << "(" << n << ")" << endl;
	});*/

	/*int countNums = count_if(values.begin(), values.end(), [](int n) {
		return n % 2 == 0;
	});
	cout << "Count even nums = " << countNums << endl;*/

	/*
	//поиск заданного значения
	int srchNum = 50;

	int count = count_if(values.begin(), values.end(), [srchNum](int n) {
		return n >= srchNum;
	});
	cout << "count = " << count << endl;*/

	/*
	//захват всех примитивных переменных
	int from = 30, to = 70;

	int count = count_if(values.begin(), values.end(), [=](int n) {
		return n >= from && n <= to;
	});*/


	vector<Person> people;

	people.push_back(Person("Vasya", "Pupkin", 17));
	people.push_back(Person("Petya", "Ivanov", 16));
	people.push_back(Person("Kolya", "Sidorov", 19));
	people.push_back(Person("Dima", "Stepanov", 38));
	people.push_back(Person("Masha", "Rudova", 32));
	people.push_back(Person("Gogi", "Kurochkin", 28));


	//вывод людей
	printPeopleList(people);

	//кол-во совершеннолетних
	/*int count = count_if(people.begin(), people.end(), [](const Person& person) {
		return person.getAge() >= 18;
	});

	cout << "count = " << count << endl;*/

	//удаление эл-от по заданному условию
	/*auto start = people.begin();
	auto end = people.end();

	int count = count_if(people.begin(), people.end(), [](const Person& person) {
		return person.getAge() < 18;
	});
	end = remove_if(start, end, [](const Person& person) {
		return person.getAge() < 18;
	});

	cout << "----------------------------" << endl;
	while (start != end) {
		cout << *start << endl;
		start++;
	}

	people.resize(people.size() - count);*/

	/*string firstName = "Vasiliy", lastName = "Pupkin";

	auto it = find_if(people.begin(), people.end(), [firstName, lastName](const Person& person) {
		return person.getFirstName() == firstName && person.getLastName() == lastName;
	});

	if (it != people.end()) {
		cout << *it << endl;
	}
	else {
		cout << "Person was not found" << endl;
	}*/

	//поиск максимального
	/*auto it = max_element(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
		return p1.getAge() < p2.getAge();
	});
	cout << *it << endl;*/

	partial_sort(people.begin(), people.end(), people.end(), [](const Person& p1, const Person& p2) {
		return p1.getAge() < p2.getAge();
	});

	cout << "----------------------------" << endl;
	printPeopleList(people);


	return 0;
}


