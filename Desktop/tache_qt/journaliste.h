#ifndef JOURNALISTE_H
#define JOURNALISTE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "qstring.h"
class gesjournaliste{
public:
    gesjournaliste();
    gesjournaliste(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getfonction();
    QString getdiplome();

    void setid(int);
    void setnom (QString);
    void setprenom (QString);
    void setfonction (QString);
    void setdiplome (QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * tri_prenom();
    int  chercher (QString);
private:
    int id ;
    QString nom,prenom,fonction,diplome;
};

#endif // JOURNALISTE_2_H
