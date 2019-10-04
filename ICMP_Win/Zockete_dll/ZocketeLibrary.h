#pragma once

#define ZOCKETELIBRARY_EXPORTS 1

#ifdef ZOCKETELIBRARY_EXPORTS
#define ZOCKETELIBRARY_API __declspec(dllexport)
#else
#define ZOCKETELIBRARY_API __declspec(dllimport)
#endif

#include<WinSock2.h>
#include "ZocketeException.h"

//Necesario para winsock
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class ZOCKETELIBRARY_API ZocketeLibrary {
public:

	static void initLibrary() throw (ZocketeException);
	static void closeLibrary();
	static bool isInit();

protected:
	static WSADATA wsaData;
	static bool winsockIniciado;

private:




};