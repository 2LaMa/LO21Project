#ifndef AUTO_1D_H
#define AUTO_1D_H
#include "automate.h"
class Automate1D : public Automate
{
    std::vector<int> voisinage;
    static const int dimension = 1;
public:
    Automate1D(std::vector<int> voisinage, std::vector<unsigned int> regle):Automate(regle),voisinage(voisinage){}
    void appliquerTransition(const Etat& dep, Etat& dest) const final;
};
#endif // AUTO_1D_H
