#include "classOccurrence.h"

occurrence::occurrence(string car,int nb=1)
{
        mot=car;
        occur=nb;
}

string occurrence::getMot() const{
        return mot;
    }

void occurrence::setMot(string mot)
{
        this->mot=mot;
}

int occurrence::getOccur() const
{
        return occur;
}

void occurrence::SetOccur()
{
    occur=occur+1;
}

