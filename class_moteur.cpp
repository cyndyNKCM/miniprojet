#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>





using namespace std;

class moteur
{
public:
    lecteur* monLecteur;
    analyseur* monAnalyse;
    index* monIndex;
    ordonnanceur* monOrd;
    bool choix;

    moteur(lecteur* L,analyseur* A,index* I,ordonnanceur* O){

         monLecteur=L;
         monAnalyse=A;
         monIndex=I;
         monOrd=O;
         choix=false;

    }

    vector<string> extraireMots(string monCheminFichier)
    {
        vector<string> extraction=monLecteur->extrairemots(monCheminFichier);
        return extraction;


    }



    vector<occurrence> AnalyserFichier(vector<string> mots){
         //analyseur* monAnalyse= new analyseur(mots);

        vector<occurrence> stats = monAnalyse->analyser(mots);

        return stats;
    }

    /*vector<triplet>*/void IndexerFichier(vector<occurrence> stats,string cheminFichier){
        //index* monIndex=new index;
        //vector<triplet> ind;
         monIndex->indexer(stats,cheminFichier);
        //return ind;

    }

   vector<pair<string,int> > ordonnancerFichier(vector<vector<pair<string,int> ,string> > ind,string cheminRequete){
       vector<pair<string,int> > Ordonn;
       /* if(!choix)
            {

                ordonnanceurOcc ptr;
               monOrd=&ptr;
             Ordonn=monOrd->ordonnancer(ind,cheminRequete);
            }


        else
        {

             ordonnanceurBinaire ptr;
            monOrd=&ptr;
                Ordonn=monOrd->ordonnancer(ind,cheminRequete);
        }*/
        //ordonnanceur *monOrd=new ordonnanceur;
        Ordonn=monOrd->ordonnancer(ind,cheminRequete);

return Ordonn;

    }



};


int main() {
    lecteur* fichier;
    analyseur* analyse;
    index* ind;
    ordonnanceur* ord;

    moteur m(fichier,analyse,ind,ord);

    //vector<string> chemin;



    vector<string> text1=elimStopWords("stopWords.txt",m.extraireMots("test.txt"));
    //vector<occurrence> stats1=m.AnalyserFichier(text1);
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

    int monChoix(0);

    do{
    cout<<"saisir 0 pour analyseurVect ou 1 pour analyseurMap : ";
    cin>>monChoix;

    }while(!(monChoix == 0 || monChoix == 1));

//analyseur* anal;

    switch(monChoix)
    {
    case 0:
        {
            analyse=new analyseurVect(text1);
            m.monAnalyse=analyse;
            vector<occurrence> stats1=m.AnalyserFichier(text1);
            for(int i=0;i<stats1.size();i++)
                cout<<stats1[i].getMot()<<","<<stats1[i].getOccur()<<endl;
        }

    case 1:
        {
            analyse=new analyseurMap(text1);
            m.monAnalyse=analyse;
            vector<occurrence> stats1=m.AnalyserFichier(text1);
            for(int i=0;i<stats1.size();i++)
                cout<<stats1[i].getMot()<<","<<stats1[i].getOccur()<<endl;
        }

    }



    //if(monChoix == 1)
       // m.choix=true;


   /* vector<pair<string,int> > tri=m.ordonnancerFichier(rech,"tester.txt");

    for(vector<pair<string,int> >::iterator it=tri.begin(); it!=tri.end(); ++it)
        cout<<"("<<it->first<<" , "<<"score : "<<it->second<<")"<<endl;*/



    return 0;
}


