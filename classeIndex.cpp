#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>




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


class index
{
private:

    vector<triplet> ind;

public:
    virtual /*vector<triplet>*/void indexer(vector<occurrence> stats,string road)=0;   //le pb se trouve ici
};

class indexVect : public index
{
public:

    /*vector<triplet>*/ void indexer(vector<occurrence> stats,string road){

        vector<triplet> fich;

        for(int i=0;i<stats.size();i++)
            {
                triplet ind(road,stats[i].getMot(),stats[i].getOccur());
                fich.push_back(ind);

            }
           //return fich;

    }
};


class indexMap : public index
{
public:

    /* multimap< pair<string,int> ,string>*/void indexer(vector<occurrence> stats,string road){
        multimap< pair<string,int> ,string> dict;

        for(int i=0;i<stats.size();i++)
            {
                pair<string,int> occ=make_pair(stats[i].getMot(),stats[i].getOccur());
                dict.insert({occ,road});
            }
            //return dict;

    }
};
