#include <QApplication>
#include <QPushButton>
 #include <QLabel>
//#include<autocell.h>
#include<automate.h>

int main(int argc, char* argv[]) {
    //QApplication app(argc, argv);
    /*Etat etat(1,20,1);
    etat.setCellule(10,1);
    AutomateElementaire a(170);
    Etat temp;
    for(int i = 0; i < 50; i++)
    {
        std::cout<<etat<<"\n";
        a.appliquerTransition(etat,temp);
        etat = temp;
    }*/
    Etat etat(2,10,1);
    etat.setCellule(1,0,1);
    etat.setCellule(2,1,1);
    etat.setCellule(0,2,1);
    etat.setCellule(1,2,1);
    etat.setCellule(2,2,1);
    JeuDeLaVie a;
    Etat temp;
    for(int i = 0; i < 50; i++)
    {
        std::cout<<etat<<"\n";
        a.appliquerTransition(etat,temp);
        etat = temp;
    }
    //AutoCell mafenetre;
    //mafenetre.show();
    return 1;// app.exec();
}
