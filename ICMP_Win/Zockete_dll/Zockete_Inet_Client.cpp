#include "pch.h"
#include "Zockete_Inet_Client.h"


Zockete_Inet_Client::Zockete_Inet_Client(const std::string host) : Zockete_Inet(host){

	//this->puerto = SIN_PUERTO;
}

Zockete_Inet_Client::Zockete_Inet_Client(const std::string host, int puerto) : Zockete_Inet(host, puerto) {

	//this->puerto = puerto;

}

Zockete_Inet_Client::~Zockete_Inet_Client() {

}

void  Zockete_Inet_Client::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

void Zockete_Inet_Client::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_INET_CLIENT_CLASS << std::endl;
}

void Zockete_Inet_Client::conecta() {

	int iResult = SOCKET_ERROR;

	iResult = connect(this->sd,this->direccionServidor.ai_addr,(int)this->direccionServidor.ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(this->sd);
		this->sd = INVALID_SOCKET;
		//Falta el throw
		return;
	}

}

void Zockete_Inet_Client::desconecta() {

	int iResult = -1000;

	if (this->sd != INVALID_SOCKET) {
		iResult = shutdown(this->sd,SD_BOTH);
		if (iResult == SOCKET_ERROR) {
			//retornamos error.
			return;
		}
		return;
	}

}



void Zockete_Inet_Client::limpiaRecvBuffer() {
	this->recvBuffer.clear();
}

