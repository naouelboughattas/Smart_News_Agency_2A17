#ifndef JOURNAUX_H
#define JOURNAUX_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qstring.h"
#include <QString>
class journaux
{
public:
    journaux();
    journaux(int,QString,QString,QString);
    int getid();
    QString getadresse_siege();
    QString getproprietaire_journal();
    QString getlibelle_journal();
    void setid(int);
    void setadresse_siege(QString);
    void setproprietaire_journal(QString);
    void setlibelle_journal(QString);
    bool ajouter();
       QSqlQueryModel * afficher();
       bool modifier();
       bool supprimer(int);
       QSqlQueryModel * rechercher(QString);
       QSqlQueryModel * tri_adresse_siege();
private:
    int id;
    QString adresse_siege,proprietaire_journal,libelle_journal;
};

#endif // JOURNAUX_H
