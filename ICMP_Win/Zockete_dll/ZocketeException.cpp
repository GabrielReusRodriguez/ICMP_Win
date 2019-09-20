#include "pch.h"
#include "ZocketeException.h"


ZocketeException::ZocketeException(const int valor, const std::string& msg) {
	this->code = valor;
	this->msg = msg;

}

ZocketeException::~ZocketeException() {

}

int ZocketeException::getCode() {
	return this->code;
}


std::string ZocketeException::getMessage() {
	return this->msg;
}