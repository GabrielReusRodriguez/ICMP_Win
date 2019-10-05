#include "pch.h"
#include "Zockete_Inet_Client_ICMP.h"
#include <ws2tcpip.h>


Zockete_Inet_Client_ICMP::Zockete_Inet_Client_ICMP(const std::string host) : Zockete_Inet_Client(host) {
	this->limpiaRecvBuffer();
}

Zockete_Inet_Client_ICMP::~Zockete_Inet_Client_ICMP() {

}


void  Zockete_Inet_Client_ICMP::version() {
	std::cout << "Version libreria: " << ZOCKETE_LIB_VERSION << std::endl;
}

void Zockete_Inet_Client_ICMP::about() {
	std::cout << "Zockete Library v " << ZOCKETE_LIB_VERSION << " Class " << ZOCKETE_INET_CLIENT_ICMP_CLASS << std::endl;
}

void Zockete_Inet_Client_ICMP::creaSocket() {
	//Limpiamos la memoria de la dirección del servidor.
	//ZeroMemory(&(this->direccionServidor),sizeof(this->direccionServidor));
	//https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo
	int iResult;
	struct addrinfo queryServidor = { 0 };
	struct addrinfo *ptr = NULL;
	//struct addrinfo *resultadoServidor = NULL;
	int connectedSocket = INVALID_SOCKET;

	addrinfo a;
	PADDRINFOA resultadoServidor = nullptr;
	//PCSTR host = this->host.c_str();

	ZeroMemory(&queryServidor, sizeof(queryServidor));
	//memset(&(this->direccionServidor), 0, sizeof(this->direccionServidor));

	//queryServidor = createAddrInfo(AF_UNSPEC, SOCK_RAW, IPPROTO_ICMP);
	queryServidor = createAddrInfo(AF_UNSPEC, SOCK_RAW, IPPROTO_ICMP);
	iResult = getaddrinfo(this->host.c_str(),nullptr,&queryServidor,&resultadoServidor);
	//iResult = getaddrinfo("www.google.es", "80", &queryServidor, &resultadoServidor);
	//iResult = getaddrinfo("www.google.es", "80", &queryServidor, &resultadoServidor);
	//iResult = getaddrinfo("www.google.es", "80", &queryServidor, &resultadoServidor);
	
	//iResult = getaddrinfo(host, nullptr, &queryServidor, &resultadoServidor);
	if (iResult != 0) {
		//Error => retornamos.
		WCHAR* mesg = gai_strerror(iResult);
		return;
	}


	this->direccionServidor = *resultadoServidor;
	//Probamos diferentes direcciones.
	//for (ptr = resultadoServidor; ptr != NULL; ptr = ptr->ai_next) {
	for (ptr = &(this->direccionServidor); ptr != NULL; ptr = ptr->ai_next) {

		connectedSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (connectedSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			//WSACleanup();
			//return 1;
			continue;
		}
		else {
			this->sd = connectedSocket;
			return;
		}

	}

	//this->direccionServidor.ai_family = AF_INET;
	//this->direccionServidor.ai_socktype = SOCK_RAW;
}

void Zockete_Inet_Client_ICMP::envia(std::string sendBuffer) {
	
	int iResult = SOCKET_ERROR;

	if (this->sd == INVALID_SOCKET) {
		//error
		return;
	}

	iResult = send(this->sd, sendBuffer.c_str(), int(strlen(sendBuffer.c_str())), 0);
	if (iResult == SOCKET_ERROR) {
		return;
	}

}

void Zockete_Inet_Client_ICMP::recibe() {

	int recvbuflen = 1024;
	char recvbuf[1024];
	char* payload = NULL;
	int iResult;

	char* nullChar = NULL;

	do {

		nullChar = NULL;
		iResult = recv(this->sd, recvbuf, recvbuflen, 0);
		if (iResult > 0){
			payload = new char[iResult+1];
			strncpy_s(payload, iResult+1, recvbuf, iResult);
			
			nullChar = strchr(payload, '\0');
			//nullChar = strchr(recvbuf, '\0');
			this->recvBuffer.push_back(payload);
			printf("Bytes received: %d payload: %s\n", iResult, payload);
			delete payload;
		}	
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0 && nullChar == NULL);


	/*
	
	const char* p = str;
std::vector<std::string> vector;

do {
  vector.push_back(std::string(p));
  p += vector.back().size() + 1;
} while ( // whatever condition applies );

	*/

}
