#ifndef CLASSOCCURRENCE_H
#define CLASSOCCURRENCE_H


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
    occurrence(string car,int nb);
    string getMot() const;
    void setMot(string mot);
    int getOccur() const;
    void SetOccur();

};



#endif // CLASSOCCURRENCE_H
