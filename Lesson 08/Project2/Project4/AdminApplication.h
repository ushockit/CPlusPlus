#pragma once
#include "Application.h"
class AdminApplication : public Application
{
public:

	// Inherited via Application
	virtual void menu() override;
	virtual void runMenuAction(int action) override;
};