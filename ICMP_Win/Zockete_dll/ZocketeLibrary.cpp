#include "pch.h"
#include "ZocketeLibrary.h"

#include <iostream>

void  Zockete::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

Zockete::Zockete(const std::string host) throw (ZocketeException) {
	this->host = host;
	this->initWinsock();
}


Zockete::~Zockete() {
	this->closeSocket();
	this->closeWinsock();
}

void Zockete::closeSocket() {

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