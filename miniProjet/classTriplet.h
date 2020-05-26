#ifndef CLASSTRIPLET_H
#define CLASSTRIPLET_H


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
    triplet(string road,string expr,int stat);
    string getchemin() const;
    string getmot() const;
    int getocc() const;
};


#endif // CLASSTRIPLET_H
