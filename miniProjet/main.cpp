#include <iostream>
#include "classLecteur.h"
#include "FonctionCode.h"
#include "classMoteur.h"
#include "classOccurrence.h"
#include "classOrdonnanceur.h"
#include "classTriplet.h"
#include"classAnalyseur.h"
#include "classIndex.h"

using namespace std;


int main() {
    lecteur* fichier;
    analyseur* analyse;
    index* ind;
    ordonnanceur* ord;

    moteur m(fichier,analyse,ind,ord);

    //vector<string> chemin;



    vector<string> text1=elimStopWords("stopWords.txt",m.extraireMots("test.txt"));

    //vector<triplet> indexfichier1=m.IndexerFichier(stats1,"test.txt");

/*
    vector<string> text2=elimStopWords("stopWords.txt",m.extraireMots("ajout1.txt"));
    vector<occurrence> stats2=m.AnalyserFichier(text2);
    vector<triplet> indexfichier2=m.IndexerFichier(stats2,"ajout1.txt");

    vector<string> text3=elimStopWords("stopWords.txt",m.extraireMots("ajout2.txt"));
    vector<occurrence> stats3=m.AnalyserFichier(text3);
    vector<triplet> indexfichier3=m.IndexerFichier(stats3,"ajout2.txt");

    vector<string> text4=elimStopWords("stopWords.txt",m.extraireMots("ajout3.txt"));
    vector<occurrence> stats4=m.AnalyserFichier(text4);
    vector<triplet> indexfichier4=m.IndexerFichier(stats4,"ajout3.txt");

    vector<string> text5=elimStopWords("stopWords.txt",m.extraireMots("ajout4.txt"));
    vector<occurrence> stats5=m.AnalyserFichier(text5);
    vector<triplet> indexfichier5=m.IndexerFichier(stats5,"ajout4.txt");
*/



    //vector<vector<triplet> > rech;
    //rech.push_back(indexfichier1);
   /* rech.push_back(indexfichier2);
    rech.push_back(indexfichier3);
    rech.push_back(indexfichier4);
    rech.push_back(indexfichier5);
*/


    cout<<endl;
    cout<<"********************************************************REQUETE***************************************************"<<endl;


    cout<<"entrez votre requete : ";
    string requete;
    getline(cin,requete);



    string const cheminn("tester.txt");
    ofstream fichRequete(cheminn.c_str());

    if(fichRequete){

        fichRequete<<requete<<endl;
    }
    else
        cout<<"operation impossible"<<endl;

    cout<<endl;

    int monChoix1(0);
    vector<occurrence> stats1;

    do{
    cout<<"saisir 0 pour analyseurVect ou 1 pour analyseurMap : ";
    cin>>monChoix1;

    }while(!(monChoix1 == 0 || monChoix1 == 1));

    switch(monChoix1)
    {
    case 0:
        {
            analyse=new analyseurVect(text1);
            m.monAnalyse=analyse;
            /*vector<occurrence> */stats1=m.AnalyserFichier(text1);
            /*for(int i=0;i<stats1.size();i++)
                cout<<stats1[i].getMot()<<","<<stats1[i].getOccur()<<endl;*/
        }

    case 1:
        {
            analyse=new analyseurMap(text1);
            m.monAnalyse=analyse;
            /*vector<occurrence> */stats1=m.AnalyserFichier(text1);
           /* for(int i=0;i<stats1.size();i++)
                cout<<stats1[i].getMot()<<","<<stats1[i].getOccur()<<endl;*/
        }

    }

     cout<<endl;

int monChoix2(0);
multimap< pair<string,int> ,string> dictionnaire;
vector<triplet> monFICH;
    do{
    cout<<"saisir 0 pour indexVect ou 1 pour indexMap : ";
    cin>>monChoix2;

    }while(!(monChoix2 == 0 || monChoix2 == 1));


    switch(monChoix2)
    {
    case 0:
        {
            ind=new indexVect;
            m.monIndex=ind;
            m.IndexerFichier(stats1,"test.txt",dictionnaire,monFICH);
            for(int i=0;i<monFICH.size();i++)
                cout<<"("<<monFICH[i].getmot()<<","<<monFICH[i].getocc()<<monFICH[i].getocc()<<")"<<endl;
        }

    case 1:
        {
           ind=new indexMap;
            m.monIndex=ind;
            m.IndexerFichier(stats1,"test.txt",dictionnaire,monFICH);
            for(multimap< pair<string,int> ,string>::iterator it=dictionnaire.begin(); it!=dictionnaire.end(); ++it)
                cout<<"("<<(it->first).first<<" , "<<(it->first).second<<","<<it->second<<")"<<endl;

        }

    }
/*
 cout<<endl;

 int monChoix3(0);

    do{
    cout<<"saisir 0 pour OrdonnanceurOcc ou 1 pour OrdonnanceurBinaire : ";
    cin>>monChoix3;

    }while(!(monChoix3 == 0 || monChoix3 == 1));


    switch(monChoix3)
    {
    case 0:
        {
            ord=new ordonnanceurOcc;
            m.monOrd=ord;
            m.ordonnancerFichier()
            for(int i=0;i<monFICH.size();i++)
                cout<<"("<<monFICH[i].getmot()<<","<<monFICH[i].getocc()<<monFICH[i].getocc()<<")"<<endl;
        }

    case 1:
        {
           ind=new indexMap;
            m.monIndex=ind;
            m.IndexerFichier(stats1,"test.txt",dictionnaire,monFICH);
            for(multimap< pair<string,int> ,string>::iterator it=dictionnaire.begin(); it!=dictionnaire.end(); ++it)
                cout<<"("<<(it->first).first<<" , "<<(it->first).second<<","<<it->second<<")"<<endl;

        }

    }

*/

    return 0;
}




