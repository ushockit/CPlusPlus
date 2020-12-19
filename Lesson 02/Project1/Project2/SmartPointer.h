#pragma once
#include <iostream>
class SmartPointer
{
	static int copiesCounter;
	int* ptr;
public:
	SmartPointer();
	SmartPointer(SmartPointer&);
	SmartPointer(int);
	~SmartPointer();
};