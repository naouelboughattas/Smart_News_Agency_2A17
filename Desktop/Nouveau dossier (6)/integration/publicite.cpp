#include "publicite.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"
publicite::publicite()
{

id_publicite=0;
id_client=0;
type_publicite="";
tarif_publicite=0;
date_lancement="";
duree_publicite="";

}

publicite::publicite(int id_publicite,int id_client,QString type_publicite,float tarif_publicite,QString date_lancement,QString duree_publicite )
{
  this->id_publicite=id_publicite;
  this->id_client=id_client;
  this->type_publicite=type_publicite;
  this->tarif_publicite=tarif_publicite;
  this->date_lancement=date_lancement;
  this->duree_publicite=duree_publicite;


}

bool publicite::ajouter()
{
QSqlQuery query;
QString res   = QString::number(id_publicite);
QString ress  = QString::number(id_client);
QString resss = QString::number(tarif_publicite);


query.prepare("INSERT INTO publicite (id_publicite,id_client,type_publicite,tarif_publicite,date_lancement,duree_publicite) "
                    "VALUES (:id_publicite, :id_client, :type_publicite, :tarif_publicite, :date_lancement, :duree_publicite)");
query.bindValue(":id_publicite", res);
query.bindValue(":id_client", ress);
query.bindValue(":type_publicite", type_publicite);
query.bindValue(":tarif_publicite", resss);
query.bindValue(":date_lancement", date_lancement);
query.bindValue(":duree_publicite", duree_publicite);
if(id_publicite==  0 ||  id_client==  0  || type_publicite.isEmpty() || tarif_publicite==  0 || date_lancement.isEmpty() || duree_publicite.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * publicite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from publicite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_publicite"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_publicite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("tarif_publicite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_lancement"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree_publicite"));

    return model;
}
bool publicite::modifier()
{
    QSqlQuery query ;
QString res   = QString::number(id_publicite);
QString ress  = QString::number(id_client);
QString resss = QString::number(tarif_publicite);

  query.prepare("update publicite set id_publicite='"+res+"',id_client='"+ress+"',type_publicite='"+type_publicite+"',tarif_publicite='"+resss+"',date_lancement='"+date_lancement+"',duree_publicite='"+duree_publicite+"' where id_publicite='"+res+"'");
                query.bindValue(":id_publicite",res);
                query.bindValue(":id_client",ress);
                query.bindValue(":type_publicite",type_publicite);
                query.bindValue(":tarif_publicite",resss);
                query.bindValue(":date_lancement",date_lancement);
                query.bindValue(":duree_publicite",duree_publicite);
                if(id_publicite==  0 ||  id_client==  0  || type_publicite.isEmpty() || tarif_publicite==  0 || date_lancement.isEmpty() || duree_publicite.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
            return  query.exec();
}
bool publicite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from publicite where id_publicite = :id_publicite ");
query.bindValue(":id_publicite", res);
return    query.exec();


}

QSqlQueryModel *publicite:: tri_type_publicite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from publicite order by type_publicite ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_publicite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_client"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_publicite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tarif_publicite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_lancement"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("duree_publicite"));



    return model;
}
QSqlQueryModel *publicite:: tri_id_publicite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from publicite order by id_publicite ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_publicite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_client"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_publicite"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tarif_publicite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_lancement"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("duree_publicite"));



    return model;
}
QSqlQueryModel * publicite::rechercher(QString type_publicite)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from publicite where type_publicite = '"+type_publicite+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_publicite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_publicite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("tarif_publicite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_lancement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree_publicite"));
    QMessageBox::critical(nullptr, QObject::tr("Verification de recherche"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

        return model;

}
