#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QLCDNumber>
class AutoCell : public QWidget{
Q_OBJECT
    QSpinBox* num; // numéro
    QLineEdit* numeroBit[8]; // un QLineEdit par bit
    QLabel* numl;
    QLabel* numeroBitl[8];
    QVBoxLayout* numc;
    QVBoxLayout* bitc[8];
    QHBoxLayout* numeroc;
    QIntValidator* zeroOneValidator;
    // Question 2
    QTableWidget* depart;
    unsigned int dimension = 25;
    QVBoxLayout* couche;
    // Question 3
    QTableWidget* etats;
    QPushButton* simulation;
    QPushButton* quitter;

    QPushButton* b_quitter;
    QLCDNumber *m_lcd;


public:
    explicit AutoCell(QWidget* parent = nullptr);
private slots:
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(const QModelIndex& index);
    void launchSimulation();
};

#endif // AUTOCELL_H
