#include "classLecteur.h"
#include "FonctionCode.h"

vector<string> lecteur::extrairemots(string chemin)
    {
        vector<string> texte;
        ifstream fichier(chemin.c_str());

        if(fichier){
           string mot;
           while(fichier>>mot){

               if(verifPonct(mot) == false)
                    texte.push_back(mot);
           }

        }
        else
            cout<<"operation impossible"<<endl;

            return texte;

    }
