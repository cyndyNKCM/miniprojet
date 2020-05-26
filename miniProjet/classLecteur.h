#ifndef CLASSLECTEUR_H
#define CLASSLECTEUR_H

#include<cstring>
#include<fstream>
#include<iostream>
#include<vector>

using namespace std;
class lecteur
{
private:
    string fichier;
public:
    vector<string> extrairemots(string chemin);


};




#endif // CLASSLECTEUR_H
