#pragma once

#define ZOCKETELIBRARY_EXPORTS 1

#ifdef ZOCKETELIBRARY_EXPORTS
#define ZOCKETELIBRARY_API __declspec(dllexport)
#else
#define ZOCKETELIBRARY_API __declspec(dllimport)
#endif

//https://docs.microsoft.com/es-es/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=vs-2019

#include<WinSock2.h>

#define ZOCKETE_VERSION "1.0"

class ZOCKETELIBRARY_API Zockete
{
protected: 
	SOCKET sd;
public:
	void version();
	Zockete();
	~Zockete();
};