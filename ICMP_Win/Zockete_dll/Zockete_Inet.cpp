#include "pch.h"
#include "Zockete_Inet.h"


Zockete_Inet::Zockete_Inet(const std::string host) : Zockete() {
	this->host = host;
	this->puerto = SIN_PUERTO;
}


Zockete_Inet::Zockete_Inet(const std::string host, int puerto) : Zockete() {
	this->host = host;
	this->puerto = puerto;
}


Zockete_Inet::~Zockete_Inet() {

}


void  Zockete_Inet::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

void Zockete_Inet::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_INET_CLASS << std::endl;
}