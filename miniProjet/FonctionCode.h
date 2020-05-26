#ifndef FONCTIONCODE_H_INCLUDED
#define FONCTIONCODE_H_INCLUDED

#include<cstring>
#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include "classOccurrence.h"

using namespace std;

bool verifPonct(string expr);
int verif(string expr,vector<occurrence> tab);
string minuscule(string ch);
int verif(string expr,map<string,int> dict); //renvoie 1 si l'expression existe dans la map et 0 sinon
vector<string> elimStopWords(string cheminstopWords,vector<string> req);


#endif // FONCTIONCODE_H_INCLUDED
