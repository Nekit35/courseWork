#include "Encryption.h";
Encryption::Encryption()
{

}

void Encryption::iniCryptProvider()
{
	if (!CryptAcquireContext(&hProv, NULL, NULL,
		PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		std::cout << "CryptAcquireContext" << std::endl;
		return;
	}
	std::cout << "Cryptographic provider initialized" << std::endl;
}

void Encryption::genSessionKey()
{
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))
	{
		std::cout << "CryptGenKey" << std::endl;
		return;
	}
	std::cout << "Session key generated" << std::endl;
}
void Encryption::encrypt(char* data)
{
	stringForEncrypt = data;
	count = strlen(stringForEncrypt);
	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)stringForEncrypt, &count, strlen(stringForEncrypt)))
	{
		std::cout << "CryptEncrypt" << std::endl;
		return;
	}
	std::cout << "Encryption completed" << std::endl;
	std::cout << "Encrypted string: " << stringForEncrypt << "::::" << strlen(stringForEncrypt) << std::endl;
}
void Encryption::decrypt(char* data)
{
	if (!CryptDecrypt(hSessionKey, 0, true, 0, (BYTE*)data, &count))
	{
		std::cout << "CryptDecrypt" << std::endl;
		return;
	}
	std::cout << "Deccrypted string: " << data << "::::" << strlen(data) << std::endl;
}