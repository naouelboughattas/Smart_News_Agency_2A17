#ifndef MISSIONS_H
#define MISSIONS_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qstring.h"

class missions{
public:
    missions();
    missions(int,QString,QString,QString);
    int getid_mission();
    QString getlibelle();
    QString getdescription();
    QString getconfidentialite();

    void setid_mission(int);
    void setlibelle (QString);
    void setdescription (QString);
    void setconfidentialite (QString);
    void setdiplome (QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_id_mission();

private:
    int id_mission ;
    QString libelle,description,confidentialite;
};
#endif // MISSIONS_H
