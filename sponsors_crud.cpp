#include "sponsors_crud.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"
sponsors_crud::sponsors_crud()
{

id_sponsor=0;
domaine_sponsor="";
nom_sponsor="";
adresse_sponsor="";
type_sponsor="";

}

sponsors_crud::sponsors_crud(int id_sponsor,QString domaine_sponsor,QString nom_sponsor,QString adresse_sponsor,QString type_sponsor )
{
  this->id_sponsor=id_sponsor;
  this->domaine_sponsor=domaine_sponsor;
  this->nom_sponsor=nom_sponsor;
  this->adresse_sponsor=adresse_sponsor;
  this->type_sponsor=type_sponsor;


}

bool sponsors_crud::ajouter()
{
QSqlQuery query;
QString res   = QString::number(id_sponsor);


query.prepare("INSERT INTO sponsors (id_sponsor,domaine_sponsor,nom_sponsor,adresse_sponsor,type_sponsor) "
                    "VALUES (:id_sponsor, :domaine_sponsor, :nom_sponsor, :adresse_sponsor, :type_sponsor)");
query.bindValue(":id_sponsor", res);
query.bindValue(":domaine_sponsor",domaine_sponsor);
query.bindValue(":nom_sponsor", nom_sponsor);
query.bindValue(":adresse_sponsor", adresse_sponsor);
query.bindValue(":type_sponsor", type_sponsor);
if(id_sponsor==  0 ||  domaine_sponsor.isEmpty()  || nom_sponsor.isEmpty() || adresse_sponsor.isEmpty() || type_sponsor.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}

return    query.exec();
}
QSqlQueryModel * sponsors_crud::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from sponsors");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_sponsor"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("domaine_sponsor"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_sponsor"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_sponsor"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_sponsor"));


    return model;
}
bool sponsors_crud::modifier()
{
    QSqlQuery query ;
QString res   = QString::number(id_sponsor);

  query.prepare("update sponsors set id_sponsor='"+res+"',domaine_sponsor='"+domaine_sponsor+"',nom_sponsor='"+nom_sponsor+"',adresse_sponsor='"+adresse_sponsor+"',type_sponsor='"+type_sponsor+"' where id_sponsor='"+res+"'");
                query.bindValue(":id_sponsor",res);
                query.bindValue(":domaine_sponsor",domaine_sponsor);
                query.bindValue(":nom_sponsor",nom_sponsor);
                query.bindValue(":adresse_sponsor",adresse_sponsor);
                query.bindValue(":type_sponsor",type_sponsor);


                if(id_sponsor==  0 ||  domaine_sponsor.isEmpty()  || nom_sponsor.isEmpty() || adresse_sponsor.isEmpty() || type_sponsor.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }
            return  query.exec();
}
bool sponsors_crud::supprimer(int id1)
{
QSqlQuery query;
QString res= QString::number(id1);
query.prepare("Delete from sponsors where id_sponsor = :id_sponsor ");
query.bindValue(":id_sponsor", res);
return    query.exec();

if(id_sponsor==  0  )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification de suppression"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel *sponsors_crud:: tri_nom_sponsor()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from sponsors order by nom_sponsor ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_sponsor"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("domaine_sponsor"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_sponsor"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse_sponsor"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_sponsor"));



    return model;
}
QSqlQueryModel *sponsors_crud:: tri_type_sponsor()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from sponsors order by type_sponsor ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_sponsor"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("domaine_sponsor"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_sponsor"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse_sponsor"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_sponsor"));



    return model;
}
QSqlQueryModel * sponsors_crud::rechercher(QString nom_sponsor)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from sponsors where nom_sponsor = '"+nom_sponsor+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_sponsor"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("domaine_sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_sponsor"));
    if( nom_sponsor.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification de recherche"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

    }


        return model;

}

