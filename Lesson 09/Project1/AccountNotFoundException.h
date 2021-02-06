#pragma once
#include <iostream>

class AccountNotFoundException : std::exception
{
	const char* message;
public:
	AccountNotFoundException(const char* msg) : std::exception(msg) {
		message = msg;
	}
	const char* what() const override {
		return message;
	}
};

