#pragma once

#define ZOCKETELIBRARY_EXPORTS 1

#ifdef ZOCKETELIBRARY_EXPORTS
#define ZOCKETELIBRARY_API __declspec(dllexport)
#else
#define ZOCKETELIBRARY_API __declspec(dllimport)
#endif

//https://docs.microsoft.com/es-es/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=vs-2019
//https://docs.microsoft.com/en-us/windows/win32/winsock/finished-server-and-client-code

#include<WinSock2.h>
#include <string>
#include "ZocketeException.h"

//Necesario para winsock
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define ZOCKETE_LIB_VERSION 1.0f
#define ZOCKETE_CLASS "Zockete"

class ZOCKETELIBRARY_API Zockete
{
protected: 

	SOCKET sd = INVALID_SOCKET;
	std::string host;
	WSADATA wsaData;

	//Metodos.
	void closeSocket();
	virtual void createSocket() = 0;
	void runSocket();
	void initWinsock() throw (ZocketeException);
	void closeWinsock();


public:
	virtual void version();
	virtual void about();
	//Zockete() throw (ZocketeException);
	Zockete(const std::string host) throw (ZocketeException);
	~Zockete();
};