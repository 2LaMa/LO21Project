#include<auto_2d.h>

void Automate2D::appliquerTransition(const Etat& dep, Etat& dest) const {
    unsigned int segment;
    unsigned int abscisseDest;
    unsigned int ordonneeDest;

    if(&dep == &dest) throw AutomateException("AppliquerTransition : dep et dest egaux");
    if (dep.getTaille() != dest.getTaille() || dep.getDim() != dest.getDim()) dest = dep;
    std::vector<unsigned int> conf(voisinage.size()); //stocke l'état du voisinage pour une cellule
    for (unsigned int abscisse = 0; abscisse < dep.size(); abscisse++) {
        for(unsigned int indexVoisin = 0; indexVoisin < voisinage.size(); indexVoisin++)
        {
            segment = abscisse/dep.getTaille();
            abscisseDest = indexTorique(abscisse%dep.getTaille()+voisinage[indexVoisin][0],dep.getTaille());
            ordonneeDest =  indexTorique(segment+voisinage[indexVoisin][1], dep.getTaille());
            //indexDest = ordonneeDest*dep.getTaille()+abscisseDest;
            conf[indexVoisin] = dep.getCellule(abscisseDest,ordonneeDest);
        }

        dest.setCellule(abscisse, regle[baseNtoBase10(conf,dep.getValMax()+1)]);
    }
}
