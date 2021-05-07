#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>

class equipement
{
public:
    equipement();
    equipement(int,QString,QString,QString,QDate,QString);
    int getid_Equipement();
    void setid_Equipement(int);
    QString getlibelle();
    void setlibelle(QString);
    QString getdescription();
    void setdescription(QString);
    QString getmarque();
    void setmarque(QString);
    QDate getdate_acqui();
    void setdate_acqui(QDate);
    QString getprix();
    void setprix(QString);
    bool ajouter_Equipement();
        bool modifier_Equipement();
    QSqlQueryModel * afficher_Equipement();
    bool supprimer_Equipement(int);
    QSqlQueryModel* recherche_id(QString );
    QSqlQueryModel* recherche_libelle(QString );
    QSqlQueryModel* recherche_marque(QString );


private:
    int id_Equipement;
    QString libelle;
    QString description;
    QString marque;
    QDate date_acqui;
    QString prix;
};

#endif // EQUIPEMENT_H
