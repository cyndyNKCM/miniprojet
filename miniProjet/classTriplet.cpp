#include "classTriplet.h"

triplet::triplet(string road,string expr,int stat)
    {
        chemin=road;
        mot=expr;
        occ=stat;
    }

string triplet::getchemin() const
    {
        return chemin;
    }

string triplet::getmot() const
    {
        return mot;
    }

int triplet::getocc() const
    {
        return occ;
    }
