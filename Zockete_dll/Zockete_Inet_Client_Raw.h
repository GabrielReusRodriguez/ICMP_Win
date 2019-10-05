#pragma once

#include "Zockete_Inet_Client.h"

#define ZOCKETE_INET_CLIENT_RAW_CLASS "ZOCKETE_INET_CLIENT_RAW"

class ZOCKETELIBRARY_API Zockete_Inet_Client_Raw :
	public Zockete_Inet_Client
{
public:
	Zockete_Inet_Client_Raw(const std::string host, int puerto) throw (ZocketeException);
	~Zockete_Inet_Client_Raw();
	virtual void creaSocket() throw (ZocketeException);
	virtual void about();
	virtual void version();
protected:
private:



};

