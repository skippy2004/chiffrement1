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
    // Générez un IV aléatoire
    AutoSeededRandomPool rng;
    rng.GenerateBlock(this->iv, sizeof(this->iv));

    // IV BASE 64
    // A COMMENTER
    std::string ivBase64;
    StringSource(this->iv, sizeof(this->iv), true,
        new Base64Encoder(
            new StringSink(ivBase64),
            false // ne pas ajouter de saut de ligne
        )
    );
    std::cout << "E+++++++" << ivBase64 << std::endl;
    // Initialisez le chiffreur avec la clé et l'IV
    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(this->aesKey, sizeof(this->aesKey), this->iv);

    // Lisez le contenu du fichier dans une chaîne de caractères
    std::string fileContent;
    FileSource(inputFile.c_str(), true,
        new StringSink(fileContent)
    );

    // Chiffre le fichier
    std::string encryptedContent;
    StringSource(fileContent, true,
        new StreamTransformationFilter(encryptor,
            new StringSink(encryptedContent)
        )
    );

    // Ouvrez le fichier de sortie en mode binaire
    std::ofstream file(outputFile.c_str(), std::ios::binary);

    // IV en préfixe
    file.write(reinterpret_cast<const char*>(this->iv), sizeof(this->iv));

    //Donnee chiffre apres
    file.write(encryptedContent.c_str(), encryptedContent.size());

    std::cout << "Fichier chiffre avec IV en prefixe : " << outputFile << std::endl;
}


/**
 * \brief Dechiffre les donnees d'un fichier
 *
 * \param inputFile Fichier a dechiffrer
 * \param outputFile Resultat du dechiffrement
 */
void AesGestion::DecryptFileAES256(const std::string& inputFile, const std::string& outputFile)
{
    // Ouvrez len binaire
    std::ifstream input(inputFile.c_str(), std::ios::binary);

    //on enelvee l'IV
    input.read(reinterpret_cast<char*>(this->iv), sizeof(this->iv));

    // IV BASE 64
    // A COMMENTER
    std::string ivBase64;
    StringSource(this->iv, sizeof(this->iv), true,
        new Base64Encoder(
            new StringSink(ivBase64),
            false // ne pas ajouter de saut de ligne
        )
    );
    std::cout << "D+++++++" << ivBase64 << std::endl;

    //Deplacement curseur
    input.seekg(sizeof(this->iv));

    // Initialiser
    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(this->aesKey, sizeof(this->aesKey), this->iv);

    // Ouvrer le fichier de sortie en mode binaire
    //std::ofstream output(outputFile.c_str(), std::ios::binary);

    //Lire le reste et dechiffre
    FileSource(input, true,
        new StreamTransformationFilter(decryptor,
            new FileSink(outputFile.c_str()), BlockPaddingSchemeDef::PKCS_PADDING)
    );

    std::cout << "Fin Déchiffrement AES-256" << std::endl;
}