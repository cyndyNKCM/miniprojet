#ifndef CLASSORDONNANCEUR_H
#define CLASSORDONNANCEUR_H


#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include "classLecteur.h"
#include "classTriplet.h"



using namespace std;


class ordonnanceur
{
private:
    vector<string> cheminFich;
    string cheminRequete;

public:

     virtual vector<pair<string,int> > ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete) = 0;
};


class ordonnanceurOcc : public ordonnanceur
{
public:
    vector<pair<string,int> > ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete);

};


class ordonnanceurBinaire : public ordonnanceur
{
public:
    vector<pair<string,int> > ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete);
};


#endif // CLASSORDONNANCEUR_H
