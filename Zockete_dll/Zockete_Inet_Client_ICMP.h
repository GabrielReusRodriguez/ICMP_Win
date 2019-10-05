#pragma once
#include "Zockete_Inet_Client.h"

#define ZOCKETE_INET_CLIENT_ICMP_CLASS "ZOCKETE_INET_CLIENT_ICMP"

class ZOCKETELIBRARY_API Zockete_Inet_Client_ICMP :
	public Zockete_Inet_Client
{

public:

	Zockete_Inet_Client_ICMP(const std::string host) throw (ZocketeException);
	~Zockete_Inet_Client_ICMP();

	virtual void about();
	virtual void version();

	virtual void creaSocket() throw (ZocketeException);
	virtual void envia(std::string sendBuffer) throw (ZocketeException);
	virtual void recibe() throw (ZocketeException);

protected:
	
	

private:


};

