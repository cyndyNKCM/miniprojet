#include "classAnalyseur.h"
#include "FonctionCode.h"

analyseur::analyseur(vector<string> ch)
{
      for (int i=0; i<ch.size(); i++)
        texte.push_back(ch[i]);

};

string analyseur::getvalcase(int i)
{
      return texte[i];

};

int analyseur::getsize()
{
      return texte.size();

}

analyseurVect::analyseurVect(vector<string> ch): analyseur(ch)
    {

    }

vector<occurrence> analyseurVect::analyser(vector<string> texte){

         vector<occurrence> occ;
        for(int i=0;i<texte.size();i++)
        {
            occurrence expression(minuscule(getvalcase(i)),1);

            if(verif(minuscule(expression.getMot()),occ)==0) //si le mot existe d�j� dans le vecteur occ
                {

                    for(int j=i+1;j<texte.size();j++)
                        {

                            if(strcmp(minuscule(expression.getMot()).c_str(),minuscule(getvalcase(j)).c_str()) == 0) //si le mot existe dans une position j>i
                                expression.SetOccur();//on incr�mente le nombre d'occurrences
                        }

                        occ.push_back(expression);//on remplit le vecteur avec la variable expression
                }

        }

    return occ;
}

analyseurMap::analyseurMap(vector<string> ch): analyseur(ch)
    {

    }

vector<occurrence> analyseurMap::analyser(vector<string> texte){

         map<string,int> dict;
                                        //on parcoure le vecteur et la variable mot prend la i �me valeur du vecteur � analyser
        vector<occurrence> occ;                //nb est le nombre d'occurrence d'un mot ,il est par d�faut =1
        string mot;                              //si le mot n'existe pas d�j� dans la map on l'ajoute comme cl�
        int nb;                          //et sa donn�e est nb , sinon on parcoure le vecteur � analyser � partir de la position i+1
        for(int i=0;i<texte.size();i++)              //� chaque fois qu'on trouve le mot on incr�mente nb
        {   nb=1;
            mot=minuscule(getvalcase(i));

            if(verif(mot,dict)==0)
                {dict[mot]=nb;

                    for(int j=i+1;j<texte.size();j++)
                        {

                            if(strcmp(mot.c_str(),minuscule(texte[j]).c_str() )== 0)
                                nb=nb+1;
                        }

                        dict[mot]=nb;
                }


        }


for (map<string,int>::iterator it=dict.begin(); it!=dict.end(); ++it)
{
    occurrence a(it->first,dict[it->first]);                                //remplissage du vecteur occ � partir de la map
                                                                          //par des variables de type occurrence
    occ.push_back(a);
}


    return occ;
}
