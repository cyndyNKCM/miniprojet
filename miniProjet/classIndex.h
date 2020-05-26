#ifndef CLASSINDEX_H
#define CLASSINDEX_H


#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
#include "classTriplet.h"
#include "classOccurrence.h"




using namespace std;


class index
{
private:

    vector<triplet> ind;

public:
    virtual /*vector<triplet>*/void indexer(vector<occurrence> stats,string road,multimap< pair<string,int> ,string>& dict,vector<triplet>& fich)=0;
};

class indexVect : public index
{
public:

    /*vector<triplet>*/ void indexer(vector<occurrence> stats,string road,multimap< pair<string,int> ,string>& dict,vector<triplet>& fich);


};


class indexMap : public index
{
public:

    /* multimap< pair<string,int> ,string>*/void indexer(vector<occurrence> stats,string road,multimap< pair<string,int> ,string>& dict,vector<triplet>& fich);


};

#endif // CLASSINDEX_H
