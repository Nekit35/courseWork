#include "CryptoTools.h"
CryptoTools::CryptoTools()
{
	pathToFile = "db.bin";
}

CryptoTools::CryptoTools(string _pathToFile)
{
	pathToFile = _pathToFile;
}

bool CryptoTools::encrypt(const char* password)
{
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in " + pathToFile + " -out db.enc -pass pass:" + password;
	system(command.c_str());
	if (remove("db.bin") != 0) {
		return false;
	}
	return true;
}

bool CryptoTools::decrypt(const char* password)
{
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in db.enc -out db.bin -pass pass:";
	command += password;
	system(command.c_str());
	if (remove("db.enc") != 0) {
		return false;
	}
	return true;
}