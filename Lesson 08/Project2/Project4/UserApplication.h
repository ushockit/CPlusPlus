#pragma once
#include <iostream>
#include "Application.h"

class UserApplication : public Application
{
public:

	// Inherited via Application
	virtual void menu() override;
	//virtual void start() override;
	virtual void runMenuAction(int action) override;
};

