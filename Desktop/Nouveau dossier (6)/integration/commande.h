#ifndef COMMANDEH_H
#define COMMANDEH_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qstring.h"
#include <QString>
class commande
{
public:
    commande();
    commande(int,int,int);
    int getid_commande();
    QString getdate_commande();
    int getquantite_commande();
    void setid_commande(int);
    void setdate_commande(int);
    void setquantite_commande(int);
    bool ajouterr();
       QSqlQueryModel * afficherr();
       bool modifierr();
       bool supprimerr(int);
       QSqlQueryModel * rechercherr(int);
       QSqlQueryModel * tri_id_commande();
       void PDF();
private:
    int id_commande,quantite_commande,date_commande;

};










#endif // COMMANDEH_H
