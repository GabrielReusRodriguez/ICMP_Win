#pragma once
#include "ZocketeLibrary.h"

#define ZOCKETE_CLIENT_CLASS "ZOCKETE_CLIENT"

#define SIN_PUERTO -1


class Zockete_Client :
	public Zockete
{
private:
	int puerto = SIN_PUERTO;
public:
	void envia();
	void recibe();
	Zockete_Client(const std::string host);
	Zockete_Client(const std::string host, int puerto);
	~Zockete_Client();
	virtual void version();
	virtual void about();

};

