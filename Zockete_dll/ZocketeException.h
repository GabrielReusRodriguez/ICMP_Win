#pragma once

#include "ZocketeLibraryDefines.h"

/*
#define ZOCKETELIBRARY_EXPORTS 1

#ifdef ZOCKETELIBRARY_EXPORTS
#define ZOCKETELIBRARY_API __declspec(dllexport)
#else
#define ZOCKETELIBRARY_API __declspec(dllimport)
#endif
*/


#include <iostream>
#include <string>

class ZOCKETELIBRARY_API ZocketeException
{

private:
	int code;
	std::string msg;

public:
	ZocketeException(const int code, const std::string& msg);
	~ZocketeException();
	std::string getMessage();
	int getCode();
};

