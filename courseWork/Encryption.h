
#include <iostream>
#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
using namespace std;

class Encryption {
private:
	char* stringForEncrypt;
	DWORD dwIndex = 0;
	DWORD dwType;
	DWORD cbName;
	LPTSTR pszName, x;
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;
	DWORD count;


public:
	Encryption();
	void iniCryptProvider();
	void genSessionKey();
	void encrypt(char* data);
	void decrypt(char*data);
};