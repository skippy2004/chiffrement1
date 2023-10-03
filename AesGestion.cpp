#include "AesGestion.h"

using namespace CryptoPP;
AesGestion::AesGestion()
{

}

AesGestion::~AesGestion()
{

}

/**
 * \brief generation d'une clef AES
 * Le resultat est mid dans un tbl octet privee
 *
 */
void AesGestion::GenerateAESKey()
{
    CryptoPP::AutoSeededRandomPool rng;
    rng.GenerateBlock(this->aesKey, sizeof(this->aesKey));
    std::cout << "Generation de clef OK" << std::endl;
}


/**
 * \brief Sauvegarde de la clef dans un fichier
 *
 * \param filename : nom du fichier qui va contenir la clef
 */
void AesGestion::SaveAESKeyToFile(const std::string& filename)
{
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier de sortie." << std::endl;
        return;
    }

    ofs.write(reinterpret_cast<const char*>(this->aesKey), sizeof(this->aesKey));

    ofs.close();

    std::cout << "Sauvegarde clef AES dans : " << filename << std::endl;
}

/**
 * \brief Chargement de la clef depuis un fichier
 *
 * \param filename nom du ficheir contenant la clef
 */
void AesGestion::LoadAESKeyFromFile(const std::string& filename)
{
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier d'entrée." << std::endl;
        return;
    }

    ifs.read(reinterpret_cast<char*>(this->aesKey), sizeof(this->aesKey));

    ifs.close();

    std::cout << "Chargement clef AES depuis " << filename << std::endl;
}



/**
 * \brief Chiffre un fichier et met le resultat dans un autre
 *
 * \param inputFile fichier contenant les donnees a chiffrer
 * \param outputFile ficheir contenant les donnes chiffrees
 */
void AesGestion::EncryptFileAES256(const std::string& inputFile, const std::string& outputFile)
{
    AutoSeededRandomPool rng;

    rng.GenerateBlock(iv, sizeof(this->iv));
    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(this->aesKey, sizeof(this->aesKey), iv);

    std::cout << inputFile.c_str() << std::endl;
    FileSource(inputFile.c_str(), true,
        new StreamTransformationFilter(encryptor,
            new FileSink(outputFile.c_str()), BlockPaddingSchemeDef::PKCS_PADDING)
    );

    std::cout << "Fin chiffrement AES-256" << std::endl;
}

/**
 * \brief Dechiffre les donnees d'un fichier
 *
 * \param inputFile Fichier a dechiffrer
 * \param outputFile Resultat du dechiffrement
 */
void AesGestion::DecryptFileAES256(const std::string& inputFile, const std::string& outputFile)
{
    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(this->aesKey, sizeof(this->aesKey), this->iv);

    std::cout << inputFile.c_str() << std::endl;
    FileSource(inputFile.c_str(), true,
        new StreamTransformationFilter(decryptor,
            new FileSink(outputFile.c_str()), BlockPaddingSchemeDef::PKCS_PADDING)
    );

    std::cout << "Fin Dechiffrement  AES-256" << std::endl;
}