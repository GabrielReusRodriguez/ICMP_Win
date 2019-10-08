// ICMP_Win_Client.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
//#include "../Zockete_dll/Zockete_Client.h"
#include "Zockete_Inet_Client_ICMP.h"
#include "ZocketeLibrary.h"
#include "ArgsManager.h"


//#define DEFAULT_PAYLOAD "ABCDEFGHIJKLMNOPQRSTVWXYZabcdefghijklmnopqrstuvwxyz1234567890"

#define DEFAULT_PAYLOAD "ABCDEFGHIJKLMNOPQRSTVWXYZ"


int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";
	Zockete_Inet_Client_ICMP *mySocket = NULL;
	ArgsManager* args = NULL;

	std::string host = "";
	std::string payload = "";

	/*
	if (argc < 2) {
		std::cout << "Faltan argumentos, uso:" << std::endl;
		std::cout << "ZocketePing  host" << std::endl;
		return 1;
	}

	if (argc == 2) {
		host = argv[1];
		payload = "ABCDEFGHIJKLMNOPQRSTVWXYZ";
	}

	if (argc == 3) {
		host = argv[1];
		payload = argv[2];
	}
	*/


	try {
		args = new ArgsManager(argc,argv,1);
		host = args->getDestino();
		payload = args->getPayload();
		if (payload.empty()) {
			payload = DEFAULT_PAYLOAD;
		}
		
	}
	catch (ArgsException e) {
		return 1;
	}



	if (host.empty() || payload.empty()) {
		std::cout << "No hemos recibido o host o payload " << std::endl;
		return 1;
	}

	std::cout << "Ping a " << host << "Con el payload: " << payload << std::endl;
	try{
		ZocketeLibrary::initLibrary();

		mySocket = new Zockete_Inet_Client_ICMP(host);
		mySocket->creaSocket();
		mySocket->conecta();
		mySocket->envia(payload);
		mySocket->recibe();
		mySocket->desconecta();
		mySocket->cierraSocket();
		mySocket->about();
		delete mySocket;

		ZocketeLibrary::closeLibrary();
	}
	catch (ZocketeException& e) {
		std::cout << "ERROR EXCEPCION" << std::endl;
	}

	//Liberamos memoria.
	delete args;
	std::cout << "Goodbye World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
