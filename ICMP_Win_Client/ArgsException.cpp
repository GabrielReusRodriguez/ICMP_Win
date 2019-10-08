#include "ArgsException.h"


ArgsException::ArgsException(const int code, const std::string& msg) {
}

ArgsException::~ArgsException() {

}


int ArgsException::getCode() {

	return this->code;
}

std::string ArgsException::getMessage() {

	return this->msg;

}
