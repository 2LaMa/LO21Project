#ifndef BAS_DROITE_H
#define BAS_DROITE_H
#include "auto_2d.h"

/**
 * @brief The En_Bas_A_Droite class
 * Ce magnifique automate fonctionne comme suit.
 * Si la cellule est morte, et qu'au moins 1 cellule à gauche ou en haut est vivante,elle devient vivante
 * Si al cellule est vivante, elle meurt si au moins un de ses voisins en bas ou à droite meurt
 */
class En_Bas_A_Droite : public Automate2D{
    /**
     * @brief getVoisinage
     * Cette fonction, similaire à celle que l'on peut retrouver dans l'automate du jeu de la vie,
     * permet d'initialiser le voisinage du constructeur, c'est à dire la cellue,
     * et ses voisins directes en croix.
     * @return un vecteur contenant les dits voisins
     */
    static std::vector<std::vector<int>> getVoisinage()
    {
        auto resultat = std::vector<std::vector<int>>(5,std::vector<int>(2));
        resultat[0]={0,-1};
        resultat[1]={-1,0};
        resultat[2]={0,0};
        resultat[3]={1,0};
        resultat[4]={0,1};
        return resultat;
    }
public:
    /**
     * @brief En_Bas_A_Droite
     * Le constructeur de la classe, utilisant le programme getVoisinage()
     * pour linitialisation.
     * Le deuxieme atribut, n'étant pas utilisé (cet Automane n'a qu'un seul mode de fonctionnement)
     * on l'initialise à un vecteur contenant un zéro
     */
    En_Bas_A_Droite():Automate2D(En_Bas_A_Droite::getVoisinage(),{0}){}
    void appliquerTransition(const Etat& dep, Etat& dest) const;

};
#endif // BAS_DROITE_H
