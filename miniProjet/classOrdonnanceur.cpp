#include "classOrdonnanceur.h"
#include "classTriplet.h"
#include "FonctionCode.h"

vector<pair<string,int> > ordonnanceurOcc::ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete)
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

vector<pair<string,int> > ordonnanceurBinaire::ordonnancer(vector<vector<triplet> >tabIndex,string cheminRequete)
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

