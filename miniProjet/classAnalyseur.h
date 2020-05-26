#ifndef CLASSANALYSEUR_H
#define CLASSANALYSEUR_H


#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
#include "classOccurrence.h"


using namespace std;


class analyseur{
private:
    vector<string> texte;

public:
  virtual vector<occurrence> analyser(vector<string> texte) = 0;
  analyseur(vector<string> ch);
  string getvalcase(int i);
  int getsize();


};

class analyseurVect : public analyseur
{
public:
    analyseurVect(vector<string> ch);
   vector<occurrence> analyser(vector<string> texte);
};




class analyseurMap : public analyseur
{
public:
    analyseurMap(vector<string> ch);
    vector<occurrence> analyser(vector<string> texte);
};



#endif // CLASSANALYSEUR_H
