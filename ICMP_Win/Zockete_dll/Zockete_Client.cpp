#include "pch.h"
#include "Zockete_Client.h"


Zockete_Client::Zockete_Client(const std::string host) : Zockete(host){

	this->puerto = SIN_PUERTO;
}

Zockete_Client::Zockete_Client(const std::string host, int puerto) : Zockete(host) {

	this->puerto = puerto;

}


Zockete_Client::~Zockete_Client() {

}

void  Zockete_Client::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

void Zockete_Client::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_CLIENT_CLASS << std::endl;
}