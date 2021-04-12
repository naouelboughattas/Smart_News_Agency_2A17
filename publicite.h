#ifndef PUBLICITE_H
#define PUBLICITE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qstring.h"

class publicite
{
public:
    publicite();
    publicite(int,int,QString,float,QString,QString);
    int getid_publicite();
    int getid_client();
    QString gettype_publicite();
    float gettarif_publicite();
    QString getdate_lancement();
    QString getduree_publicite();
    void setid_publicite(int);
    void setid_client(int);
    void settype_publicite (QString);
    void settarif_publicite (float);
    void setdate_lancement (QString);
    void setduree_publicite(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_type_publicite();
    QSqlQueryModel * tri_id_publicite();

private:
int id_publicite,id_client;
QString type_publicite,date_lancement,duree_publicite;
float tarif_publicite;
};


#endif // PUBLICITE_H


