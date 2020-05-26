#include <iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;
class lecteur
{
private:
    string fichier;
public:
    vector<string> extrairemots(string chemin);


};


bool verifPonct(string expr)
{
    int i(0);
    bool trouve=false;
    string ponctuation[6]={".",",",";",":","?","!"};

    while(i<6 && trouve == false)
    {
        if(strcmp(expr.c_str(),ponctuation[i].c_str()) == 0)
            trouve=true;
        else
            i++;
    }
    return trouve;

}

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

int main()
{

    return 0;
}
