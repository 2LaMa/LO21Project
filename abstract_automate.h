#ifndef AUTO_H
#define AUTO_H
class Automate {
  int dimension;
    Automate(int i):dimension(i){}
    virtual ~Automate(){}
    friend class AutomateManager;
public:
    void getDimension(){return dimension;}
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const =0;
};
#endif
