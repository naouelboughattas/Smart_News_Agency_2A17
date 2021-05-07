#include "commande.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include <QEvent>
#include"qrcode.h"
commande::commande()
{
id_commande=0; date_commande=0 ;quantite_commande=0;
}

commande::commande(int id_commande,int date_commande,int quantite_commande)
{
this->id_commande=id_commande;
this->date_commande=date_commande;
this->quantite_commande=quantite_commande;
}


/*
int journaux::getid(){return id;}
QString journaux::getadresse_siege(){return adresse_siege ;}
QString journaux::getproprietaire_journal(){return proprietaire_journal ;}
QString journaux::getlibelle_journal(){return libelle_journal ;}
void journaux::setid(int id){this->id=id;}
void journaux::setadresse_siege(QString adresse_siege){this->adresse_siege=adresse_siege;}
void journaux::setproprietaire_journal(QString proprietaire_journal){this->proprietaire_journal=proprietaire_journal;}
void journaux::setlibelle_journal(QString libelle_journal){this->libelle_journal=libelle_journal;}
*/


bool commande::ajouterr()
{
QSqlQuery query;
QString res   = QString::number(id_commande);
QString ress   = QString::number(quantite_commande);
QString resss   = QString::number(date_commande);


query.prepare("INSERT INTO commande (id_commande,date_commande,quantite_commande) "
                    "VALUES (:id_commande,  :date_commande, :quantite_commande )");
query.bindValue(":id_commande", res);
query.bindValue(":date_commande", date_commande);
query.bindValue(":quantite_commande", quantite_commande);


return    query.exec();
}
QSqlQueryModel * commande::afficherr()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_commande"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_commande"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite_commande"));


    return model;
}
bool commande::modifierr()
{
    QSqlQuery query ;
QString res   = QString::number(id_commande);
QString ress   = QString::number(date_commande);
QString resss   = QString::number(quantite_commande);
  query.prepare("update commande set id_commande='"+res+"',date_commande='"+ress+"',quantite_commande='"+resss+"' where id_commande='"+res+"'");
                query.bindValue(":id_commande",res);
                query.bindValue(":date_commande",ress);
                query.bindValue(":quantite_commande",resss);



            return  query.exec();
}
bool commande::supprimerr(int id_commande)
{
QSqlQuery query;
QString res= QString::number(id_commande);
query.prepare("Delete from commande where id_commande = :id_commande ");
query.bindValue(":id_commande", res);
return    query.exec();


}

QSqlQueryModel *commande:: tri_id_commande()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from commande order by id_commande ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_commande"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_commande"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite_commande"));




    return model;
}
QSqlQueryModel * commande::rechercherr(int date_commande)
{
    QSqlQueryModel * model= new QSqlQueryModel();
QString res= QString::number(date_commande);
    model->setQuery("select * from commande where date_commande = '"+res+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_commande"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_commande"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite_commande"));


        return model;


}
