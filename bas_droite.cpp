#include <bas_droite.h>

void En_Bas_A_Droite::appliquerTransition(const Etat &dep, Etat &dest) const{
    unsigned int segment;
    unsigned int abscisseDest;
    unsigned int ordonneeDest;
    unsigned int sum;
    if(&dep == &dest) throw AutomateException("AppliquerTransition : dep et dest egaux");
    if (dep.getTaille() != dest.getTaille() || dep.getDim() != dest.getDim()) dest = dep;
    for (unsigned int abscisse = 0; abscisse < dep.size(); abscisse++) {


        segment = abscisse/dep.getTaille();
        abscisseDest = indexTorique(abscisse%dep.getTaille()+voisinage[2][0],dep.getTaille());
        ordonneeDest =  indexTorique(segment+voisinage[2][1], dep.getTaille());
        if( dep.getCellule(abscisseDest,ordonneeDest)==0){
            sum=0;
            for(unsigned int indexVoisin = 0; indexVoisin < 2; indexVoisin++)
            {

                segment = abscisse/dep.getTaille();
                abscisseDest = indexTorique(abscisse%dep.getTaille()+voisinage[indexVoisin][0],dep.getTaille());
                ordonneeDest =  indexTorique(segment+voisinage[indexVoisin][1], dep.getTaille());
                //indexDest = ordonneeDest*dep.getTaille()+abscisseDest;
                sum += dep.getCellule(abscisseDest,ordonneeDest);

            }

            if(sum!=0){

                dest.setCellule(indexTorique(segment+voisinage[2][1], dep.getTaille()),indexTorique(abscisse%dep.getTaille()+voisinage[2][0],dep.getTaille()),1 );
            }
        }else{
            sum=1;
            for(unsigned int indexVoisin = 3; indexVoisin < 5; indexVoisin++)
            {
                segment = abscisse/dep.getTaille();
                abscisseDest = indexTorique(abscisse%dep.getTaille()+voisinage[indexVoisin][0],dep.getTaille());
                ordonneeDest =  indexTorique(segment+voisinage[indexVoisin][1], dep.getTaille());
                //indexDest = ordonneeDest*dep.getTaille()+abscisseDest;
                sum *= dep.getCellule(abscisseDest,ordonneeDest);

            }
            dest.setCellule(indexTorique(segment+voisinage[2][1], dep.getTaille()),indexTorique(abscisse%dep.getTaille()+voisinage[2][0],dep.getTaille()),sum );
        }
    }
}
