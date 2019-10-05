#include "pch.h"
#include "Zockete_Inet_Client_Raw.h"


Zockete_Inet_Client_Raw::Zockete_Inet_Client_Raw(const std::string host, int puerto) : Zockete_Inet_Client(host, puerto) {

}


Zockete_Inet_Client_Raw::~Zockete_Inet_Client_Raw() {

}

void Zockete_Inet_Client_Raw::creaSocket() {
	//Limpiamos la memoria de la dirección del servidor.
	//ZeroMemory(&(this->direccionServidor),sizeof(this->direccionServidor));
	//struct addrinfo servidor = createAddrInfo(AF_INET, SOCK_RAW, IPPROTO_ICMP);

	//this->direccionServidor.ai_family = AF_INET;
	//this->direccionServidor.ai_socktype = SOCK_RAW;
	

}


void  Zockete_Inet_Client_Raw::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

void Zockete_Inet_Client_Raw::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_INET_CLIENT_RAW_CLASS << std::endl;
}