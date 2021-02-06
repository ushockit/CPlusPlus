#pragma once
#include <iostream>
#include "Application.h"
#include <conio.h>
#include "UserApplication.h"

class MainApplication : public Application
{
	Application* active;
public:
	// Inherited via Application
	virtual void menu() override;
	//virtual void start() override;
	virtual void runMenuAction(int action) override;
};

