#include "pch.h"
#include "ZocketeLibrary.h"

//Necesario ya que son miembros estaticos de una clase.
WSADATA ZocketeLibrary::wsaData;
bool ZocketeLibrary::winsockIniciado = false;

/*
ZocketeLibrary::ZocketeLibrary() {
	//this->winsockIniciado = false;
}

ZocketeLibrary::~ZocketeLibrary() {
	//this->winsockIniciado = false;
}
*/

void ZocketeLibrary::initLibrary() {
	
	if ( !ZocketeLibrary::winsockIniciado ){
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			//Error al inicializar Winsock
			ZocketeLibrary::winsockIniciado = false;
			throw ZocketeException(1, "Error inicializando WinSock");
		}
		ZocketeLibrary::winsockIniciado = true;
	}
}


void ZocketeLibrary::closeLibrary() {
	//Sólo limpio la librearía en caso que wsaData haya sido inicializada.
	//if (&(this->wsaData) != NULL) {
	if (ZocketeLibrary::winsockIniciado && &(ZocketeLibrary::wsaData) != NULL) {
		WSACleanup();
		ZocketeLibrary::winsockIniciado = false;
	}
}

bool ZocketeLibrary::isInit() {
	return ZocketeLibrary::winsockIniciado;
}

/*
void Zockete::initWinsock() throw (ZocketeException) {

	//Inicializo el Winsock
	if (Zockete::winsockIniciado)
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			//Error al inicializar Winsock
			Zockete::winsockIniciado = false;
			throw ZocketeException(1, "Error inicializando WinSock");
		}
	Zockete::winsockIniciado = true;
}
*/
/*
void Zockete::closeWinsock() {

	//Sólo limpio la librearía en caso que wsaData haya sido inicializada.
	//if (&(this->wsaData) != NULL) {
	if (Zockete::winsockIniciado && &(Zockete::wsaData) != NULL) {
		WSACleanup();
		Zockete::winsockIniciado = false;
	}
}
*/