#ifndef AUTOELEM_H
#define AUTOELEM_H
#include "auto_1d.h"
class AutomateElementaire : public Automate1D
{
    static std::vector<int> getVoisinage(){return {-1,0,1};}
    static std::vector<unsigned int> getRegleFromNum(short unsigned int num)
    {
            std::string str = NumToNumBit(num);
            std::vector<unsigned int> resultat(str.size());
            for(unsigned int i = 0; i < str.size(); i++) resultat[str.size()-1-i] = str[i]-'0';
            return resultat;
    }
public:
    AutomateElementaire(short unsigned int numero):Automate1D(AutomateElementaire::getVoisinage(),AutomateElementaire::getRegleFromNum(numero)){}
};
#endif // AUTOELEM_H
