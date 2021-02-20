#pragma once
#include <vector>
#include "Student.h"
#include <algorithm>

class StudentsStorage
{
	static StudentsStorage* instance;
	std::vector<Student> students;

	StudentsStorage();
public:
	static StudentsStorage* getInstance();
	const std::vector<Student>& getStudents() const;

	Student* searchStudentByLastName(string firstName);
};