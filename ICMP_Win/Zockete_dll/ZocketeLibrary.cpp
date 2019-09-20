#include "pch.h"
#include "ZocketeLibrary.h"

#include <iostream>

void  Zockete::version() {
	std::cout << "Version libreria: " << ZOCKETE_VERSION << std::endl;
}

Zockete::Zockete(const std::string host) {
	this->host = host;
}


Zockete::~Zockete() {

}