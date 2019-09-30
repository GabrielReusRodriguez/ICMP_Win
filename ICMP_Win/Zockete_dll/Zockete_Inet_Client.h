#pragma once

#include<vector>
#include "Zockete_Inet.h"

#define ZOCKETE_INET_CLIENT_CLASS "ZOCKETE_INET_CLIENT"




class ZOCKETELIBRARY_API Zockete_Inet_Client :
	public Zockete_Inet
{
private:
	
public:

	Zockete_Inet_Client(const std::string host) throw (ZocketeException);
	Zockete_Inet_Client(const std::string host, int puerto) throw (ZocketeException);
	~Zockete_Inet_Client();

	virtual void envia(std::string sendBuffer) throw (ZocketeException)  = 0;
	virtual void recibe() throw (ZocketeException)  = 0;
	
	virtual void conecta() throw (ZocketeException); 
	virtual void desconecta()throw (ZocketeException);
	
	virtual void version();
	virtual void about();

protected:
	
	struct addrinfo direccionServidor;
	std::vector<std::string> recvBuffer;
	
	void limpiaRecvBuffer();


};

