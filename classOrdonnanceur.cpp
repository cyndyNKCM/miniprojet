#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>



using namespace std;


class triplet
{
private:
    string chemin;
    string mot;
    int occ;

public:
    triplet(string road,string expr,int stat)
    {
        chemin=road;
        mot=expr;
        occ=stat;
    }

    string getchemin() const
    {
        return chemin;
    }

    string getmot() const
    {
        return mot;
    }

    int getocc() const
    {
        return occ;
    }

};


vector<string> elimStopWords(string cheminstopWords,vector<string> req){

    vector<string> reqSansStopWords;
    bool isStopWord;

    for(int i=0;i<req.size();i++){
        ifstream fichStopWords(cheminstopWords.c_str());

        if(fichStopWords){
            string ligne;
            isStopWord = false;

            while(getline(fichStopWords,ligne)){
                if(strcmp(ligne.c_str(),req[i].c_str()) == 0)
                    isStopWord = true;
            }

            if(!isStopWord)
                reqSansStopWords.push_back(req[i]);
        }
        else
            cout<<"operation impossible"<<endl;
        }

    return reqSansStopWords;

}

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
    vector<pair<string,int> > ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete)
    {
        vector<pair<string,int> > vectFinal;

       lecteur demande;

        vector<string> req=demande.extrairemots(cheminRequete);

        vector<string> reqSansStopWords=elimStopWords("stopWords.txt",req);


        for(int j=0;j<tabIndex.size();j++){

            int score(0);
            string pathName;

            for(int i=0;i<reqSansStopWords.size();i++){



                for(int k=0;k<tabIndex[j].size();k++){

                    pathName = tabIndex[j][k].getchemin();

                    if(strcmp(reqSansStopWords[i].c_str(),(tabIndex[j][k].getchemin()).c_str()) == 0 )
                            score += (tabIndex[j][k]).getocc();

                        }



            }
            vectFinal.push_back(make_pair(pathName,score));

        }


for(int i=0;i<vectFinal.size()-1;i++)
{
    for(int j=i+1;j<vectFinal.size();j++)
    {

        if(vectFinal[i].second < vectFinal[j].second)
           {
               pair<string,int> tmp;
            tmp=vectFinal[j];
            vectFinal[j]=vectFinal[i];
            vectFinal[i]=tmp;


           }

    }
}

return vectFinal;


    }
       };


class ordonnanceurBinaire : public ordonnanceur
{
public:
    vector<pair<string,int> > ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete)
    {
        vector<pair<string,int> > vectFinal;

       lecteur demande;

        vector<string> req=demande.extrairemots(cheminRequete);

        vector<string> reqSansStopWords=elimStopWords("stopWords.txt",req);

        for(int j=0;j<tabIndex.size();j++){
            //bool trouve=false;
            int score(0);
            string pathName;

            for(int i=0;i<reqSansStopWords.size();i++)
            {int s(0);

                for(int k=0;k<tabIndex[j].size();k++)
                {

                    pathName = tabIndex[j][k].getchemin();
                    if(strcmp(reqSansStopWords[i].c_str(),((tabIndex[j])[k].getchemin()).c_str()) == 0 )
                    {
                           s=1;

                    };


                };

                score+=s;

            }
            vectFinal.push_back(make_pair(pathName,score));

        }


for(int i=0;i<vectFinal.size()-1;i++)
{
    for(int j=i+1;j<vectFinal.size();j++)
    {

        if(vectFinal[i].second < vectFinal[j].second)
           {
               pair<string,int> tmp;
            tmp=vectFinal[j];
            vectFinal[j]=vectFinal[i];
            vectFinal[i]=tmp;


           }

    }
}

return vectFinal;


    }
       };

