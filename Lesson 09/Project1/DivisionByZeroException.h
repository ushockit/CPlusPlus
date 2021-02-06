#pragma once
#include <iostream>

class DivisionByZeroException : std::exception
{
	const char* message = "Division by zero";
public:
	DivisionByZeroException() : std::exception(message) {}
	DivisionByZeroException(const char* msg) : std::exception(msg) {
		message = msg;
	}

	const char* what() const override {
		return message;
	}
};

