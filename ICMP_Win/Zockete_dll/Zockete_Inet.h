#pragma once
#include "Zockete.h"
#include "ZocketeException.h"


#define ZOCKETE_INET_CLASS "ZOCKETE_INET"


#define SIN_PUERTO -1




class ZOCKETELIBRARY_API Zockete_Inet :
	public Zockete
{

public:
	Zockete_Inet(const std::string host) throw (ZocketeException);
	Zockete_Inet(const std::string host, int puerto) throw (ZocketeException);
	~Zockete_Inet();
	
	virtual void about();

	virtual void version();
	
protected:
	std::string host;
	int puerto = SIN_PUERTO;

	

};

