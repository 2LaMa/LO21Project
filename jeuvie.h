#ifndef JEUVIE_H
#define JEUVIE_H
#include "auto_2d.h"
class JeuDeLaVie : public Automate2D
{
    static std::vector<std::vector<int>> getVoisinage()
    {
        auto resultat = std::vector<std::vector<int>>(9,std::vector<int>(2));
        resultat[0]={-1,-1};
        resultat[1]={0,-1};
        resultat[2]={1,-1};
        resultat[3]={-1,0};
        resultat[4]={0,0};
        resultat[5]={1,0};
        resultat[6]={-1,1};
        resultat[7]={0,1};
        resultat[8]={1,1};
        return resultat;
    }

    static std::vector<unsigned int> regleTrans()
    {
        unsigned int sum =0;
        auto regle = std::vector<unsigned int>(512);
        std::vector<unsigned int> etatVoisinage;
        for(unsigned int nb = 0; nb < 512; nb++)
        {
            etatVoisinage = base10toBaseN(nb,2);
            while(etatVoisinage.size() < 9)
            {
                etatVoisinage.insert(etatVoisinage.begin(),0);
            }
            sum =0;
            for(auto i=0; i<9; ++i)
            {
               if(etatVoisinage[i]==1 && i != 4)sum++;
            }
            regle[nb]=0;
            if ( sum == 2)regle[nb] = etatVoisinage[4];
            if (sum ==3)regle[nb] = 1;
        }
        return regle;
    }
public:
    JeuDeLaVie():Automate2D(JeuDeLaVie::getVoisinage(), JeuDeLaVie::regleTrans()){}


};
#endif // JEUVIE_H
