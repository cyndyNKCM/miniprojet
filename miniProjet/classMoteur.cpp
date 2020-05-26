#include "classMoteur.h"
#include "classAnalyseur.h"
#include "classTriplet.h"
#include "classLecteur.h"
#include "classIndex.h"
#include "classOrdonnanceur.h"


 moteur::moteur(lecteur* L,analyseur* A,index* I,ordonnanceur* O){

         monLecteur=L;
         monAnalyse=A;
         monIndex=I;
         monOrd=O;


    }

vector<string> moteur::extraireMots(string monCheminFichier)
    {
        vector<string> extraction=monLecteur->extrairemots(monCheminFichier);
        return extraction;


    }

vector<occurrence> moteur::AnalyserFichier(vector<string> mots){

        vector<occurrence> stats = monAnalyse->analyser(mots);

        return stats;
}

void moteur::IndexerFichier(vector<occurrence> monOcc,string cheminFichier,multimap< pair<string,int> ,string>& dico,vector<triplet>& monFich){

         monIndex->indexer(monOcc,cheminFichier,dico,monFich);


    }

vector<pair<string,int> > moteur::ordonnancerFichier(vector<vector<triplet> > ind,string cheminRequete){

        vector<pair<string,int> > Ordonn=monOrd->ordonnancer(ind,cheminRequete);

        return Ordonn;

    }
