#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"

#include "HashGestion.h"
#include "AesGestion.h"
#include "RsaGestion.h"

#include <iostream>
#include <string>
using namespace std;


int main()
{
    bool w = 1;
    while (w == 1) {

        cout << "<------------------------------------------------------------------------->" << endl;

        int x = 0;
        cout << "1/Hash    2/Rsa    3/Aes    4/quitter : ";
        cin >> x;
        /* int c = 0;
         int p = 0;
         int t = 0;
         int taille = 0;
         string text = "";

         string fichpublic = "pu";
         string fichpriver = "pr";
         string fichentrer = "";
         string fichsortie = "test.txt";

         RsaGestion ha;

         ha.chargementClefsPublic(fichpublic);
         ha.chargementClefsPrive(fichpriver);
         ha.chiffreDansFichier("ca crain", fichsortie);*/

        if (x == 4) {
            w = 0;
        }

        if (x == 1) {
            int c;
            string text = "";
            string fich = "";


            HashGestion ha;

            cout << "vous avez choisi SHA256" << endl;

            cout << "voulez-vous hashé un text(1) ou un fichier(2)  (ou autre chiffre pour revenir a la page d'aceuil) : ";
            cin >> c;

            if (c == 1) {
                cout << "vous avez choisi un text" << endl;
                cout << endl;
                cout << "merci de rentrée le text : " << endl;
                cin >> text;
                cout << endl;
                cout << "text : " << text << endl;
                cout << "SHA256 : " << ha.CalculateSHA256(text) << endl;
                ha.~HashGestion();

            }
            if (c == 2) {
                cout << "vous avez choisi un fichier" << endl;
                cout << endl;
                cout << "merci de rentrée le chemin et le nom du fichier : " << endl;
                cin >> fich;
                cout << endl;
                cout << "le fichier : " << fich << endl;
                cout << "SHA256 : " << ha.CalculateFileSHA256(fich) << endl;
                ha.~HashGestion();


            }



        }
        if (x == 2) {
            int c = 0;
            int p = 0;
            int t = 0;
            int taille = 0;
            string text = "";

            string fichpublic = "";
            string fichpriver = "";
            string fichentrer = "";
            string fichsortie = "";

            RsaGestion ha;
            cout << "vous avez choisi SHA256" << endl;

            cout << "(1) j'ai la clefs publique et je veut encoder" << endl << "(2) j'ai la clef publique et priver" << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
            cin >> p;



            if (p == 1) {
                cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef publique : " << endl;
                cin >> fichpublic;
                ha.chargementClefsPublic(fichpublic);

                cout << "(1) encoder un text" << endl << "(2) encoder dans un fichier" << endl << "(3) encoder un fichier " << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
                cin >> c;

                if (c == 1) {
                    cout << "merci de rentrée le text a encoder : " << endl;
                    cin >> text;
                    cout << "text encoder :" << endl << ha.chiffrementRsa(text) << endl;
                }
                if (c == 2) {
                    cout << "merci de rentrée le chemin et le nom du fichier a encoder : " << endl;
                    cin >> fichentrer;
                    cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                    cin >> fichsortie;
                    ha.chiffrementFichier(fichentrer, fichsortie);
                    cout << "chiffrement effectuer" << endl;
                }
                if (c == 3) {
                    cout << "merci de rentrée le text a encoder : " << endl;
                    cin >> text;
                    cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                    cin >> fichsortie;
                    ha.chiffreDansFichier(text, fichsortie);
                    cout << "chiffrement effectuer" << endl;
                }
                if (c == 4) {

                }


            }
            if (p == 2) {

                cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef publique : " << endl;
                cin >> fichpublic;
                ha.chargementClefsPublic(fichpublic);

                cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef priver : " << endl;
                cin >> fichpriver;
                ha.chargementClefsPrive(fichpriver);

                cout << "(1) encoder" << endl << "(2) decoder" << endl;
                cin >> t;


                if (t == 1) {
                    cout << "(1) encoder un text" << endl << "(2) encoder dans un fichier" << endl << "(3) encoder un fichier " << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
                    cin >> c;

                    if (c == 1) {
                        cout << "merci de rentrée le text a encoder : " << endl;
                        cin >> text;
                        cout << "text encoder :" << endl << ha.chiffrementRsa(text) << endl;
                    }
                    if (c == 2) {
                        cout << "merci de rentrée le chemin et le nom du fichier a encoder : " << endl;
                        cin >> fichentrer;
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        cin >> fichsortie;
                        ha.chiffrementFichier(fichentrer, fichsortie);
                        cout << "chiffrement effectuer" << endl;
                    }
                    if (c == 3) {
                        cout << "merci de rentrée le text a encoder : " << endl;
                        cin >> text;
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        cin >> fichsortie;
                        ha.chiffreDansFichier("ca crain", fichsortie);
                        cout << "chiffrement effectuer" << endl;
                    }
                    if (c == 4) {

                    }

                }
                if (t == 2) {

                    cout << "(1) decoder un text" << endl << "(2) decoder un fichier" << endl << "(3) decoder dans un fichier " << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
                    cin >> c;

                    if (c == 1) {
                        cout << "merci de rentrée le text a decoder : " << endl;
                        cin >> text;
                        cout << "text encoder :" << endl << ha.dechiffrementRsa(text) << endl;
                    }
                    if (c == 2) {
                        cout << "merci de rentrée le chemin et le nom du fichier a decoder : " << endl;
                        cin >> fichentrer;
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        cin >> fichsortie;
                        ha.dechiffrementFichier(fichentrer, fichsortie);
                        cout << "dechiffrement effectuer" << endl;
                    }
                    if (c == 3) {
                        cout << "merci de rentrée le chemin et le nom du fichier a decoder : " << endl;
                        cin >> fichentrer;
                        cout << ha.dechiffreFichier(fichentrer) << endl;
                    }
                    if (c == 4) {

                    }


                }
            }
            if (p == 3) {
                cout << "merci de rentrée le nom de votre fichier clef publique : " << endl;
                cin >> fichpublic;
                cout << "merci de rentrée le nom de votre fichier clef priver : " << endl;
                cin >> fichpriver;
                cout << "merci de rentrée la taille de votre cléf : " << endl;
                cin >> taille;
                ha.generationClef(fichpublic, fichpriver, taille);

                ha.chargementClefsPublic(fichpublic);
                ha.chargementClefsPrive(fichpriver);

                cout << "(1) encoder" << endl << "(2) decoder" << endl;
                cin >> t;


                if (t == 1) {
                    cout << "(1) encoder un text" << endl << "(2) encoder un fichier" << endl << "(3) encoder dans un fichier " << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
                    cin >> c;

                    if (c == 1) {
                        cout << "merci de rentrée le text a encoder : " << endl;
                        cin >> text;
                        cout << "text encoder :" << endl << ha.chiffrementRsa(text) << endl;
                    }
                    if (c == 2) {
                        cout << "merci de rentrée le chemin et le nom du fichier a encoder : " << endl;
                        cin >> fichentrer;
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        cin >> fichsortie;
                        ha.chiffrementFichier(fichentrer, fichsortie);
                        cout << "chiffrement effectuer" << endl;
                    }
                    if (c == 3) {
                        cout << "merci de rentrée le text a encoder : " << endl;
                        //cin >> text;
                        std::string message;
                        std::string fichier;
                        std::getline(std::cin >> std::ws, message);
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        std::getline(std::cin >> std::ws, fichier);


                        ha.chiffreDansFichier(text, fichsortie);
                        cout << "chiffrement effectuer" << endl;
                    }
                    if (c == 4) {

                    }

                }
                if (t == 2) {

                    cout << "(1) decoder un text" << endl << "(2) decoder un fichier" << endl << "(3) decoder dans un fichier " << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
                    cin >> c;

                    if (c == 1) {
                        cout << "merci de rentrée le text a decoder : " << endl;
                        cin >> text;
                        cout << "text encoder :" << endl << ha.dechiffrementRsa(text) << endl;
                    }
                    if (c == 2) {
                        cout << "merci de rentrée le chemin et le nom du fichier a decoder : " << endl;
                        cin >> fichentrer;
                        cout << "merci de rentrée le nom du fichier de sortie : " << endl;
                        cin >> fichsortie;
                        ha.dechiffrementFichier(fichentrer, fichsortie);
                        cout << "dechiffrement effectuer" << endl;
                    }
                    if (c == 3) {
                        cout << "merci de rentrée le chemin et le nom du fichier a decoder : " << endl;
                        cin >> fichentrer;
                        cout << ha.dechiffreFichier(fichentrer) << endl;
                    }
                    if (c == 4) {

                    }

                }

            }
        }

        if (x == 3) {

            int c = 0;
            int p = 0;
            int t = 0;
            int taille = 0;
            string text = "";

            string fichpublic = "";
            string fichpriver = "";
            string fichentrer = "";
            string fichsortie = "";


            AesGestion ha;


            cout << "(1) generer clef" << endl << "(2) charger une clef" << endl << "(3) ne pas generer clef" << endl << "(3) je veut creer la clef publique et priver" << endl << "(ou autre chiffre pour revenir a la page d'aceuil)" << endl;
            cin >> c;

            if (c == 1) {
                ha.GenerateAESKey();
                cout << "merci de rentrée le chemin et le nom du fichier ou la clef serra sauvegarder : " << endl;
                cin >> fichentrer;
                ha.SaveAESKeyToFile(fichentrer);
            }
            if (c == 2) {
                cout << "merci de rentrée le chemin et le nom du fichier contenent la clef :  : " << endl;
                cin >> fichentrer;
                ha.LoadAESKeyFromFile(fichentrer);
            }

            cout << "(1) encrypter" << endl << "(2) decrypter" << endl;
            cin >> p;

            if (p == 1) {

                cout << "merci de rentrée le chemin et le nom du fichier a encrypter  : " << endl;
                cin >> fichentrer;
                cout << "merci de rentrée le chemin et le nom du fichier de sortie : " << endl;
                cin >> fichsortie;
                ha.EncryptFileAES256(fichentrer, fichsortie);
            }
            if (p == 2) {
                cout << "merci de rentrée le chemin et le nom du fichier a decrypter :  : " << endl;
                cin >> fichentrer;
                cout << "merci de rentrée le chemin et le nom du fichier de sortie " << endl;
                cin >> fichsortie;
                ha.DecryptFileAES256(fichentrer, fichsortie);
            }





        }
        if(x != 1 and x != 2 and x != 3 and x != 4){
            cout << "merci de choisir l'option 1, 2, 3 ou 4." << endl;
        }

    }
    return 0;
}