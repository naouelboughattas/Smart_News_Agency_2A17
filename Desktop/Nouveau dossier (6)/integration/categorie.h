#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "qstring.h"

class Categorie
{
public:
    Categorie();
    Categorie(int,QString,QString,QString);
    QString getid_Categorie();
    QString getlibelle_Categorie();
    QString getdescription_Categorie();
    QString gettype_Categorie();
    void setid_Categorie(int);
    void setlibelle_Categorie(QString);
    void setdescription_Categorie(QString);
    void settype_Categorie(QString);
    bool ajouter_c();
    QSqlQueryModel * afficher_c();
    bool modifier_c();
    bool supprimer_c(int);
    QSqlQueryModel * rechercher_c(QString,int);
    QSqlQueryModel * tri_id_c();
    QSqlQueryModel * tri_libelle_c();



private :
    QString libelle_Categorie,description_Categorie,type_Categorie;
    int id_Categorie;

};


#endif // CATEGORIE_H
