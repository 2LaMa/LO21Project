
#include<automate.h>




#include<bas_droite.h>


void Etat::setCellule(unsigned int i, unsigned int val) {
    if (i >= valeur.size()) throw AutomateException("Erreur Cellule");
    valeur[i] = val;
}

unsigned int Etat::getCellule(unsigned int i) const {
    if (i >= valeur.size()) throw AutomateException("Erreur Cellule");
    return valeur[i];
}

void Etat::setCellule(unsigned int i, unsigned int j, unsigned int val)
{
    this->setCellule(j*taille+i,val);
}

unsigned int Etat::getCellule(unsigned int i, unsigned int j) const
{
    return this->getCellule(i*taille+j);
}

std::ostream& operator<<(std::ostream& f, const Etat& e) {
    if(e.getDim() == 1)
    {
        for (unsigned int i = 0; i < e.getTaille(); i++)
            f << e.getCellule(i) << " ";
    }
    else
    { for (unsigned int i = 0; i < e.getTaille(); i++)
        {for (unsigned int j = 0; j < e.getTaille(); j++)
            f << e.getCellule(i,j) << " ";
        f<<"\n";}
    }
    return f;
}


short unsigned int NumBitToNum(const std::string& num) {
    if (num.size() != 8) throw AutomateException("Numero d'automate indefini");
    int puissance = 1;
    short unsigned int numero = 0;
    for (int i = 7; i >= 0; i--) {
        if (num[i] == '1') numero += puissance;
        else if (num[i] != '0') throw AutomateException("Numero d'automate indefini");
        puissance *= 2;
    }
    return numero;
}

std::string NumToNumBit(short unsigned int num) {
    std::string numeroBit;
    if (num > 256) throw AutomateException("Numero d'automate indefini");
    unsigned short int p = 128;
    int i = 7;
    while (i >= 0) {
        if (num >= p) {
            numeroBit.push_back('1');
            num -= p;
        }
        else { numeroBit.push_back('0'); }
        i--;
        p = p / 2;
    }
    return numeroBit;
}

//AutomateElem::AutomateElem(unsigned short int num):numero(num),numeroBit(NumToNumBit(num)){}

//AutomateElem::AutomateElem(const std::string& num) :numero(NumBitToNum(num)),numeroBit(num) {}


unsigned int baseNtoBase10(std::vector<unsigned int> nb, unsigned int base)
{
    unsigned int resultat = 0;
    if(base == 0) throw AutomateException("base 0");
    for(unsigned int i = 0; i < nb.size(); i++)
    {
        resultat += nb[nb.size()-i-1]*pow(base,i);
    }
    return resultat;
}

std::vector<unsigned int> base10toBaseN(unsigned int nb, unsigned int base)
{
    std::vector<unsigned int> resultat;
    while(nb > 0)
    {
        resultat.insert(resultat.begin(),nb%base);
        nb = (unsigned int) nb/base;
    }
    return resultat;
}


unsigned int indexTorique(int index,unsigned int tailleTab)
{
    while(index < 0) index += tailleTab;
    return index%tailleTab;
}






//std::vector<unsigned int> getRegleFromNum(short unsigned int num)
