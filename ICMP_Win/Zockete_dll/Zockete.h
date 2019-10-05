#pragma once

//https://docs.microsoft.com/es-es/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=vs-2019
//https://docs.microsoft.com/en-us/windows/win32/winsock/finished-server-and-client-code

//#include<WinSock2.h>
#include <string>
#include "ZocketeLibrary.h"
#include "ZocketeException.h"

//Necesario para winsock
//#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")

#define ZOCKETE_LIB_VERSION 1.0f
#define ZOCKETE_CLASS "Zockete"

class ZOCKETELIBRARY_API Zockete
{
protected:

	SOCKET sd = INVALID_SOCKET;
	
	//static WSADATA wsaData;
	//static bool winsockIniciado;

	//Metodos.
	void closeSocket();
	
	//static void initWinsock() throw (ZocketeException);
	//static void closeWinsock();
	struct addrinfo createAddrInfo(int familia, int tipoSocket, int protocolo) throw (ZocketeException);
	//struct addrinfo

public:

	virtual void creaSocket() = 0;
	virtual void cierraSocket();
	virtual void version();
	virtual void about();
	//Zockete() throw (ZocketeException);
	Zockete() throw (ZocketeException);
	~Zockete();
};