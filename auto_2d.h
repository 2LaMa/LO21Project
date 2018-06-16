#ifndef AUTO_2D_H
#define AUTO_2D_H
#include "automate.h"
class Automate2D : public Automate
{
protected:
    std::vector<std::vector<int> > voisinage;
    static const int dimension = 2;
public:
    Automate2D(std::vector<std::vector<int>> voisinage, std::vector<unsigned int> regle):Automate(regle),voisinage(voisinage){}
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const;


};
#endif // AUTO_2D_H
