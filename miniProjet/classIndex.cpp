#include "classIndex.h"
#include "classOccurrence.h"
#include "classTriplet.h"

 void indexVect::indexer(vector<occurrence> stats,string road,multimap< pair<string,int> ,string>& dict,vector<triplet>& fich){

        //vector<triplet> fich;

        for(int i=0;i<stats.size();i++)
            {
                triplet ind(road,stats[i].getMot(),stats[i].getOccur());
                fich.push_back(ind);

            }
           //return fich;

    }

void indexMap::indexer(vector<occurrence> stats,string road,multimap< pair<string,int> ,string>& dict,vector<triplet>& fich){
        //multimap< pair<string,int> ,string> dict;

        for(int i=0;i<stats.size();i++)
            {
                pair<string,int> occ=make_pair(stats[i].getMot(),stats[i].getOccur());
                dict.insert({occ,road});
            }
            //return dict;

    }
