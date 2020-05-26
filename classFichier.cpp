#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>



using namespace std;



class Fichier
{
private:
    string chemin;

public:
    void lireFich(string chemin)
    {
        ifstream fich(chemin.c_str());
        if(fich)
        {
            //lire le fichier
        }
        else
            cout<<"operation impossible"<<endl;

    }

    void ecrireDansFich(string chemin,vector<triplet> ind)
    {
        ofstream fich;
        fich.open(chemin.c_str());
        if(fich){
                for(int i=0;i<ind.size();i++)
                    {

                        fich << "("<<"'"<<ind[i].getchemin() << "'" << " : " << ind[i].getmot() << " -> " << ind[i].getocc() << ")" << endl;


                    }
        }
        else
            cout<<"operation impossible"<<endl;

            fich.close();
    }
};

int main()
{
    return 0;
}
