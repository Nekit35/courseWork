#pragma once
#include <string>
using namespace std;
class CryptoTools
{
	string pathToFile;
public:
	CryptoTools();
	CryptoTools(string _pathToFile);
	bool encrypt(const char* password);
	bool decrypt(const char* password);
};

