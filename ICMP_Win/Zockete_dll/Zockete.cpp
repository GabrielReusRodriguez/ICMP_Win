#include "pch.h"
//#include "ZocketeLibrary.h"
#include "Zockete.h"
#include <iostream>

void  Zockete::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

Zockete::Zockete() throw (ZocketeException) {
	/*
	if (!ZocketeLibrary::isInit()) {
		ZocketeLibrary::initLibrary();
	}
	*/
	
}


Zockete::~Zockete() {
	this->cierraSocket();
	/*
	ZocketeLibrary::closeLibrary();
	*/
}

void Zockete::cierraSocket() {

	if ( this->sd != INVALID_SOCKET) {
		closesocket(this->sd);
	}

}
/*
void Zockete::initWinsock() throw (ZocketeException) {

	//Inicializo el Winsock
	if (Zockete::winsockIniciado)
		if ( WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		//Error al inicializar Winsock
		Zockete::winsockIniciado = false;
		throw ZocketeException(1, "Error inicializando WinSock");
	}
	Zockete::winsockIniciado = true;
}

void Zockete::closeWinsock() {

	//Sólo limpio la librearía en caso que wsaData haya sido inicializada.
	//if (&(this->wsaData) != NULL) {
	if (Zockete::winsockIniciado  && &(Zockete::wsaData) != NULL) {
		WSACleanup();
		Zockete::winsockIniciado = false;
	}
}
*/

void Zockete::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_CLASS  << std::endl;
}

struct addrinfo Zockete::createAddrInfo(int familia, int tipoSocket, int protocolo) {
	struct addrinfo a;
	ZeroMemory(&a, sizeof(a));
	a.ai_family = familia;
	a.ai_socktype = tipoSocket;
	a.ai_protocol = protocolo;
	return a;

}