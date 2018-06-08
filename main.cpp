#include <QApplication>
#include <QPushButton>
 #include <QLabel>
#include <fenetre.h>
#include<autocell.h>
#include<automate.h>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Etat etat(1,20,1);
    etat.setCellule(10,1);
    AutomateElementaire a(170);
    Etat temp;
    for(int i = 0; i < 50; i++)
    {
        std::cout<<etat<<"\n";
        a.appliquerTransition(etat,temp);
        etat = temp;
    }
    AutoCell mafenetre;
    mafenetre.show();
    return app.exec();
}
