#include<automate.h>
#include<random>
void generationAleatoire(Etat& etat){

    for (unsigned int i=0;i<etat.size();++i){
        etat.setCellule(i,rand()/0.5/RAND_MAX);
    }
}
void generationSimetrique(Etat& etat){

    for (unsigned int i=0;i<etat.size();++i){
        if(etat.getCellule(i)==1)
            etat.setCellule(etat.size()-1-i,1);
    }
}
