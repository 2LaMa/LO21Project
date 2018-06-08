#ifndef AUTO_H
#define AUTO_H
class Automate {
  int dimension;
  virtual ~Automate(){}
  friend class AutomateManager;
public:
    void getDimension(){return dimension;}
    virtual void appliquerTransition(const Etat& dep, Etat& dest) const =0;
protected:
  Automate(int i):dimension(i){}
};
#endif
