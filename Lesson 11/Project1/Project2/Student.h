#pragma once
#include <string>
#include "Date.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Student
{
	string firstName;
	string lastName;
	string middleName;
	Date birth;
public:
	Student();
	Student(string firstName, string lastName, string middleName, Date birth);

	string getFirstName() const;
	string getLastName() const;
	string getMiddleName() const;
	Date getBirth() const;

	friend std::ostream& operator << (std::ostream& os, const Student& obj);
};

