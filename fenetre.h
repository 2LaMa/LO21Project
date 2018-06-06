#ifndef FENETRE_H
#define FENETRE_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include<QLineEdit>


class fenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    public:
    fenetre();

    private:
    //QPushButton *b_quitter;
    QLabel* num1;
    QLabel* num2;
    QLineEdit* num;
    QLineEdit* numeroBit;



};
#endif // FENETRE_H
