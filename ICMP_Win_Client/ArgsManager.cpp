#include "ArgsManager.h"

#include <vector>
#include <iostream>

#define NO_MIN_ARGS_CHECK -1

ArgsManager::ArgsManager(int _argc, char* _argv[]) throw (ArgsException) {

	procesa(_argc, _argv, NO_MIN_ARGS_CHECK);

}

ArgsManager::ArgsManager(int _argc, char* _argv[], int _minArgc) throw (ArgsException)  {
	
	procesa(_argc, _argv, -_minArgc);
}


ArgsManager::~ArgsManager() {

}

void ArgsManager::procesa(int _argc, char* _argv[], int _minArgc) throw (ArgsException){

	//http://www.cplusplus.com/articles/DEN36Up4/


	if (_minArgc != NO_MIN_ARGS_CHECK && _argc < _minArgc) {
		muestraUso(_argv[0]);
		throw ArgsException(1, "Incorrect number of arguments");
	}
	//std::vector <std::string> sources;
	//std::string destination;
	for (int i = 1; i < _argc; ++i) {
		std::string arg = _argv[i];
		if ((arg == "-h") || (arg == "--help")) {
			muestraUso(_argv[0]);
			return;
		}
		/*
		else if ((arg == "-d") || (arg == "--destination")) {
			if (i + 1 < argc) { // Make sure we aren't at the end of argv!
				destination = argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
			}
			else { // Uh-oh, there was no argument to the destination option.
				std::cerr << "--destination option requires one argument." << std::endl;
				return 1;
			}
		}
		*/
		else if ((arg == "-p") || (arg == "--payload")) {
			if (i + 1 < _argc) { // Make sure we aren't at the end of argv!
				this->payload = _argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
			}
			else { // Uh-oh, there was no argument to the destination option.
				std::cerr << "--payload option requires one argument." << std::endl;
				throw ArgsException(2, "Payload option requires one argument");
			}
		}
		else {

			this->destino = _argv[i];
			//sources.push_back(argv[i]);
		}
	}

}

void ArgsManager::muestraUso(std::string name) {

	std::cerr << "Usage: " << name << " <option(s)> SOURCES"
		<< "Options:\n"
		<< "\t-h,--help\t\tShow this help message\n"
		//<< "\t-d,--destination\tSpecify the destination HOST\n"
		<< "\t-p,--payload \tSpecify the Payload to send\n"
		<< "\tdestination\n"
		<< std::endl;

}


std::string ArgsManager::getDestino() {
	return this->destino;
}


std::string ArgsManager::getPayload() {
	return this->payload;
}