#pragma once
#include <vector>
#include "Student.h"

class Journal
{
	std::vector<Student> students;
public:
	const std::vector<Student>& getStudents() const;
};

