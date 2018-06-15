#ifndef SIMU_H
#define SIMU_H
#include <fstream>
#include <vector>
#include "automate.h"

class Simulateur{
  Automate* automate;
  Etat* depart;
  unsigned int nbEtats;
  unsigned int rang;
  std::vector<Etat*> etats;
  Simulateur(const Simulateur& s);
  Simulateur& operator=(const Simulateur& s);
public:
  Simulateur(const Automate& a, unsigned int buffer);
  Simulateur(const Automate& a, const Etat& dep, unsigned int buffer);
  void setEtatDepart(const Etat& e);
  void run(unsigned int nbSteps); // génère les n prochains états
  void next(); // génère le prochain état
  const Etat& dernier() const;
  Automate getAutomate() const{return *automate;}
  Etat getEtatDepart()const{return etats[0];}
  unsigned int getNbEtats()const{return nbEtats;}
  void setNbEtats(unsigned int nb){nbEtats=nb;}
  void run(unsigned int nbSteps); // génère les n prochains états
  void next(); // génère le prochain état
  void reset(); // revenir à l'état de départ
 ~Simulateur();

  friend class Iterator;
  class Iterator{
    friend class Simulateur;
    Simulateur* sim;
    int i;
    Iterator(Simulateur* s) :sim(s), i(s->rang) {}
  public:
    Iterator(Simulateur* s, int dep) :sim(s), i(dep) {}
    Iterator():sim(nullptr),i(0) {}
    iterator& operator++() {
        i--;
        if (i == -1 && sim->rang >= sim->nbEtats) i = sim->nbEtats - 1;
            return *this;
        }
          Etat& operator*() const {
              return *sim->etats[i%sim->nbEtats];
          }
          bool operator!=(iterator it) const { return sim != it.sim || i != it.i; }
  };
  Iterator begin() {	return iterator(this); }
  Iterator end() { if (rang < nbMaxEtats) return iterator(this, -1); else return iterator(this, rang - nbEtats);  }
};
#endif
