#ifndef BAS_DROITE_H
#define BAS_DROITE_H
#include "auto_2d.h"
class En_Bas_A_Droite : public Automate2D{
    static std::vector<std::vector<int>> getVoisinage()
    {
        auto resultat = std::vector<std::vector<int>>(5,std::vector<int>(2));
        resultat[0]={0,-1};
        resultat[1]={-1,0};
        resultat[2]={0,0};
        resultat[3]={1,0};
        resultat[4]={0,1};
        return resultat;
    }
public:
    En_Bas_A_Droite():Automate2D(En_Bas_A_Droite::getVoisinage(),{0}){}
    void appliquerTransition(const Etat& dep, Etat& dest) const;

};
#endif // BAS_DROITE_H
