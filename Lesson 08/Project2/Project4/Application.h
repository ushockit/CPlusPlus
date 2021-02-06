#pragma once
#include <iostream>

class Application
{
public:
	virtual void menu() = 0;
	virtual void start();
	virtual void runMenuAction(int action) = 0;
};