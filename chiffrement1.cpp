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
    int x = 0;
    cout << "1/Hash    2/Rsa    3/Aes : ";
    cin >> x;

    if (x == 1) {
        int c;
        string text = "";
        string fich = "";


        HashGestion ha;

        cout << "vous avez choisi SHA256" << endl;

        cout << "voulez-vous hashé un text(1) ou un fichier(2) : ";
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
        int c;
        int p;
        string text = "";

        string fichpublic = "";
        string fichpriver = "";
        string fichentrer = "";
        string fichsortie = "";

        RsaGestion ha;
        cout << "vous avez choisi SHA256" << endl;

        cout << "(1) j'ai la clefs publique et je veut encoder un fichier" << endl << "(2) j'ai la clef publique et priver" << endl << "(3) je veut creer la clef publique et priver";
        cin >> p;

        if (p == 1) {
            cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef publique : " << endl;
            cin >> fichpublic;
            ha.chargementClefsPublic(fichpublic);


        }
        if (p == 2) {
            cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef publique : " << endl;
            cin >> fichpublic;
            ha.chargementClefsPublic(fichpublic);

            cout << "merci de rentrée le chemin et le nom du fichier contenent votre clef publique : " << endl;
            cin >> fichpriver;
            ha.chargementClefsPrive(fichpriver);
            
        }
        if (p == 3) {

        }
       


        // /*
        cout << "voulez-vous encoder(1) ou décoder(2) en Rsa : ";
        cin >> c;

        if (c == 1) {
            cout << "vous avez choisi d'encoder" << endl;
            cout << endl;

            cout << "merci de rentrée le text : " << endl;
            cin >> text;
            cout << endl;
            cout << "text : " << text << endl;
            cout << "SHA256 : " << ha.CalculateSHA256(text) << endl;
            ha.~RsaGestion();

        }
        if (c == 2) {
            cout << "vous avez choisi de décoder" << endl;
            cout << endl;

            cout << "merci de rentrée le nom du fichier avec sont type (merci de mettre tout le chemin depuis C: ou D:) : " << endl;
            cin >> fich;
            cout << endl;
            cout << "le fichier : " << fich << endl;
            cout << "SHA256 : " << ha.CalculateFileSHA256(fich) << endl;
            ha.~RsaGestion();
            // */
    }
    if (x == 3) {
        cout << "pas encore developper" << endl;


    }
    if (x != 1 or x != 2 or x != 3) {
        cout << "merci de choisir l'option 1, 2 ou 3." << endl;
    }


    return 0;
}