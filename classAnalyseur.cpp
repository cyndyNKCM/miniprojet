#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>


using namespace std;

class occurrence{
private:
    string mot;
    int occur;

public:
    occurrence(string car,int nb=1)
    {
        mot=car;
        occur=nb;
    }

    string getMot() const{
        return mot;
    }

    void setMot(string mot)
    {
        this->mot=mot;
    }

    int getOccur() const
    {
        return occur;
    }
    void SetOccur()
    { occur=occur+1;}

};


int verif(string expr,vector<occurrence> tab)
{
    int trouve=0;
    int i=0;
    int n=tab.size();
   while((trouve==0) && (i<n))
    {
        if(strcmp(expr.c_str(),(tab[i].getMot()).c_str()) == 0)
            trouve=1;
        else
            i++;
    }
    return trouve;
}

string minuscule(string ch)
{
    for(int k=0;k<ch.size();k++)
                ch[k]=tolower(ch[k]);

               return ch;


}

class analyseur{
private:
    vector<string> texte;

public:
  virtual vector<occurrence> analyser(vector<string> texte) = 0;
  analyseur(vector<string> ch)
  {
      for (int i=0; i<ch.size(); i++)
        texte.push_back(ch[i]);

    };
  string getvalcase(int i)
  {
      return texte[i];

    };
  int getsize()

  {
      return texte.size();

      }


};

class analyseurVect : public analyseur
{
public:
    analyseurVect(vector<string> ch): analyseur(ch)
    {

    }
   vector<occurrence> analyser(vector<string> texte){

         vector<occurrence> occ;
        for(int i=0;i<texte.size();i++)
        {
            occurrence expression(minuscule(getvalcase(i)),1);

            if(verif(minuscule(expression.getMot()),occ)==0) //si le mot existe déjà dans le vecteur occ
                {

                    for(int j=i+1;j<texte.size();j++)
                        {

                            if(strcmp(minuscule(expression.getMot()).c_str(),minuscule(getvalcase(j)).c_str()) == 0) //si le mot existe dans une position j>i
                                expression.SetOccur();//on incrémente le nombre d'occurrences
                        }

                        occ.push_back(expression);//on remplit le vecteur avec la variable expression
                }

        }

    return occ;
}

};


int verif(string expr,map<string,int> dict) //renvoie 1 si l'expression existe dans la map et 0 sinon
{
    int trouve=0;
    map<string,int>::iterator it=dict.begin();
   while((trouve==0) && (it!=dict.end()))
    {
        if(strcmp(expr.c_str(),(it->first).c_str()) == 0)
            trouve=1;
        else
            ++it;
    }
    return trouve;
}

class analyseurMap : public analyseur
{
public:
    analyseurMap(vector<string> ch): analyseur(ch)
    {

    }
     vector<occurrence> analyser(vector<string> texte){

         map<string,int> dict;
                                        //on parcoure le vecteur et la variable mot prend la i éme valeur du vecteur à analyser
        vector<occurrence> occ;                //nb est le nombre d'occurrence d'un mot ,il est par défaut =1
        string mot;                              //si le mot n'existe pas déjà dans la map on l'ajoute comme clé
        int nb;                          //et sa donnée est nb , sinon on parcoure le vecteur à analyser à partir de la position i+1
        for(int i=0;i<texte.size();i++)              //à chaque fois qu'on trouve le mot on incrémente nb
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
    occurrence a(it->first,dict[it->first]);                                //remplissage du vecteur occ à partir de la map
                                                                          //par des variables de type occurrence
    occ.push_back(a);
}


    return occ;
}
};




int main()
{
    return 0;
}
