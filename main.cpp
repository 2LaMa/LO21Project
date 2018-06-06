#include <QApplication>
#include <QPushButton>
 #include <QLabel>
#include <fenetre.h>
#include<autocell.h>
#include<automate.h>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    //QPushButton *quit = new QPushButton("quitter",&fenetre);
    //quit -> move(100,150);
    //AutoCell fenetre;

    //fenetre mafenetre;
    AutoCell mafenetre;
    mafenetre.show();
    return app.exec();
}
