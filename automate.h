#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <string>
#include <iostream>
#include <vector>
#include <math.h>


class AutomateException {
public:
    AutomateException(const std::string& message) :info(message) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


class Etat {
    unsigned int taille; //taille d'une ligne
    unsigned short int dimension;
    std::vector<unsigned int> valeur;
    unsigned int valMax;
public:
    Etat():taille(0), dimension(0),valeur(std::vector<unsigned int> (0)) ,valMax(0){}
    Etat(unsigned short int dim, unsigned int taille, unsigned int valMax):taille(taille),dimension(dim),valeur(std::vector<unsigned int>(pow(taille,dim))),valMax(valMax){}
    virtual ~Etat() {}
    unsigned int operator[](int index) const {return valeur[index];}
    void setCellule(unsigned int index, unsigned int val);
    void setCellule(unsigned int i, unsigned int j, unsigned int val);
    unsigned int getCellule(unsigned int) const;
    unsigned int getCellule(unsigned int i, unsigned int j) const;
    unsigned int getTaille() const { return taille; }
    unsigned int getAbscisse(unsigned int index) const {if(dimension == 1) throw AutomateException("getAbscisse sur un etat 1D"); return index/taille;}
    unsigned int getOrdonnee(unsigned int index) const {if(dimension == 1) throw AutomateException("getOrdonnee sur un etat 1D"); return index%taille;}
    unsigned short int getDim()const{return dimension;}
    unsigned int getValMax() const{return valMax;}
};

std::ostream& operator<<(std::ostream& f, const Etat& e);

class Automate {
protected:                              //+rapide
    std::vector<unsigned int> regle;
public:
    Automate(std::vector<unsigned int> regle_transition):regle(regle_transition){}
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const = 0;
};

unsigned int baseNtoBase10(std::vector<unsigned int> nb, unsigned int base);
std::vector<unsigned int> base10toBaseN(unsigned int nb, unsigned int base);
unsigned int indexTorique(int index, unsigned int tailleTab);


class Automate1D : public Automate
{
    std::vector<int> voisinage;
    static const int dimension = 1;
public:
    Automate1D(std::vector<int> voisinage, std::vector<unsigned int> regle):Automate(regle),voisinage(voisinage){}
    void appliquerTransition(const Etat& dep, Etat& dest) const final;
};


short unsigned int NumBitToNum(const std::string& num);
std::string NumToNumBit(short unsigned int num);

class Automate2D : public Automate
{
    std::vector<int> voisinage;
    static const int dimension = 2;
public:
    Automate2D(std::vector<int> voisinage, std::vector<unsigned int> regle):Automate(regle),voisinage(voisinage){}
    void appliquerTransition(const Etat& dep, Etat& dest) const final;
};

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

#endif
