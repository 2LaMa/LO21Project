#ifndef AUTO1D_H
#define AUTO1D_H
#include "abstract_automate.h"


class Automate1D : public Automate{
  unsigned short int numero;
  std::string numeroBit;
  Automate1D(unsigned short int num);
  Automate1D(const std::string& num);
  ~Automate1D(){}
  Automate1D(const Automate& a);
  Automate1D& operator=(const Automate& a);
public:
  unsigned short int getNumero() const { return numero; }
  const std::string& getNumeroBit() const { return numeroBit; }
  void appliquerTransition(const Etat& dep, Etat& dest) const;
}
short unsigned int NumBitToNum(const std::string& num);
std::string NumToNumBit(short unsigned int num);

#endif
