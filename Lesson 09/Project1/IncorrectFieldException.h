#pragma once
#include <iostream>

class IncorrectFieldException : std::exception
{
	const char* message;
public:
	IncorrectFieldException(const char* msg) : std::exception(msg) {
		message = msg;
	}
	const char* what() const override {
		return message;
	}
};

