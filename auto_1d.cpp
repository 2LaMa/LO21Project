#include<auto_1d.h>

void Automate1D::appliquerTransition(const Etat& dep, Etat& dest) const {
    if(&dep == &dest) throw AutomateException("AppliquerTransition1D : dep et dest egaux");
    if(dep.getDim() != 1) throw AutomateException("AppliquerTransition1D sur un etat2D");
    if (dep.getTaille() != dest.getTaille() || dep.getDim() != dest.getDim()) dest = dep;
    std::vector<unsigned int> conf(voisinage.size());
    for (unsigned int abscisse = 0; abscisse < dep.getTaille(); abscisse++) {
        for(unsigned int indexVoisin = 0; indexVoisin < voisinage.size(); indexVoisin++)
            conf[indexVoisin] = dep.getCellule(indexTorique(abscisse + voisinage[indexVoisin],dep.getTaille()));
        dest.setCellule(abscisse, regle[baseNtoBase10(conf,dep.getValMax()+1)]);
    }
}
