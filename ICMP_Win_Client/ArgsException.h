#pragma once

#include<string>

class ArgsException
{

private:
	int code;
	std::string msg;

public:
	ArgsException(const int code, const std::string& msg);
	~ArgsException();
	std::string getMessage();
	int getCode();

};

