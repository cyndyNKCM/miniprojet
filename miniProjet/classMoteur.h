#ifndef CLASSMOTEUR_H
#define CLASSMOTEUR_H


#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
#include "classAnalyseur.h"
#include "classTriplet.h"
#include "classLecteur.h"
#include "classIndex.h"
#include "classOrdonnanceur.h"





using namespace std;

class moteur
{
public:
    lecteur* monLecteur;
    analyseur* monAnalyse;
    index* monIndex;
    ordonnanceur* monOrd;


    moteur(lecteur* L,analyseur* A,index* I,ordonnanceur* O);
    vector<string> extraireMots(string monCheminFichier);
    vector<occurrence> AnalyserFichier(vector<string> mots);
    void IndexerFichier(vector<occurrence> monOcc,string cheminFichier,multimap< pair<string,int> ,string>& dico,vector<triplet>& monFich);
    vector<pair<string,int> > ordonnancerFichier(vector<vector<triplet> > ind,string cheminRequete);


};



#endif // CLASSMOTEUR_H
