#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <aes.h>
#include <modes.h>
#include <filters.h>
#include <osrng.h>
#include <files.h>
#include <base64.h>
class AesGestion
{

private:
	/**
	 * Clef AES.
	 */
	CryptoPP::byte aesKey[CryptoPP::AES::DEFAULT_KEYLENGTH];
	CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];
public:
	AesGestion();
	~AesGestion();
	void GenerateAESKey();
	void SaveAESKeyToFile(const std::string& filename);
	void LoadAESKeyFromFile(const std::string& filename);
	void EncryptFileAES256(const std::string& inputFile, const std::string& outputFile);
	void DecryptFileAES256(const std::string& inputFile, const std::string& outputFile);
};