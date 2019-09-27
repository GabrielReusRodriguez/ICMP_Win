#include "pch.h"
//#include "ZocketeLibrary.h"
#include "Zockete.h"

#include <iostream>

void  Zockete::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

Zockete::Zockete() throw (ZocketeException) {
	this->initWinsock();
}


Zockete::~Zockete() {
	this->cierraSocket();
	this->closeWinsock();
}

void Zockete::cierraSocket() {

	if ( this->sd != INVALID_SOCKET) {
		closesocket(this->sd);
	}

}

void Zockete::initWinsock() throw (ZocketeException) {

	//Inicializo el Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		//Error al inicializar Winsock
		throw ZocketeException(1, "Error inicializando WinSock");
	}
}

void Zockete::closeWinsock() {

	//Sólo limpio la librearía en caso que wsaData haya sido inicializada.
	if (&(this->wsaData) != NULL) {
		WSACleanup();
	}
}


void Zockete::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_CLASS  << std::endl;
}

struct addrinfo Zockete::createAddrInfo(int familia, int tipoSocket, int protocolo) {
	struct addrinfo a;
	//ZeroMemory(&a, sizeof(a));
	a.ai_family = familia;
	a.ai_socktype = tipoSocket;
	a.ai_protocol = protocolo;
	return a;
}