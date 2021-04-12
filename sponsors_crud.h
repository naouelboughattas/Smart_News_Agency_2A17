#ifndef SPONSORS_CRUD_H
#define SPONSORS_CRUD_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qstring.h"


class sponsors_crud
{
public:
    sponsors_crud();
    sponsors_crud(int,QString,QString,QString,QString);
    int getid_sponsor();
    QString getdomaine_sponsor();
    QString getnom_sponsor();
    QString getadresse_sponsor();
    QString gettype_sponsor();
    void setid_sponsor(int);
    void setdomaine_sponsor (QString);
    void setnom_sponsor (QString);
    void setadresse_sponsor (QString);
    void settype_sponsor(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_nom_sponsor();
    QSqlQueryModel * tri_type_sponsor();


private:
int id_sponsor;
QString domaine_sponsor,nom_sponsor,adresse_sponsor,type_sponsor;
};


#endif // SPONSORS_CRUD_H
