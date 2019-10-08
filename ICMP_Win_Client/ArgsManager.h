#pragma once

#include<string>
#include"ArgsException.h"

class ArgsManager
{

private:
	
	std::string destino;
	std::string payload;

	void muestraUso(std::string name);
	void procesa(int argc, char* argv[], int minArgc) throw(ArgsException);


protected:

public:

	ArgsManager(int argc, char* argv[])  throw(ArgsException);
	ArgsManager(int argc, char* argv[],int minArgc)  throw(ArgsException) ;
	~ArgsManager();
	
	std::string getDestino();
	std::string getPayload();

};

