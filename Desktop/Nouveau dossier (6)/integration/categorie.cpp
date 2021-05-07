#include "categorie.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"

Categorie::Categorie()
{
id_Categorie=0;
libelle_Categorie="";
description_Categorie="";
type_Categorie="";

}

Categorie::Categorie(int id_Categorie,QString libelle_Categorie,QString description_Categorie,QString type_Categorie)
{
  this->id_Categorie=id_Categorie;
  this->libelle_Categorie=libelle_Categorie;
  this->description_Categorie=description_Categorie;
  this->type_Categorie=type_Categorie;


}

bool Categorie::ajouter_c()
{
QSqlQuery query;
QString res= QString::number(id_Categorie);

query.prepare("INSERT INTO Categorie (id_Categorie,libelle_Categorie,description_Categorie,type_Categorie) "
                    "VALUES (:id_Categorie, :libelle_Categorie, :description_Categorie,:type_Categorie)");
query.bindValue(":id_Categorie", res);
query.bindValue(":libelle_Categorie", libelle_Categorie);
query.bindValue(":description_Categorie", description_Categorie);
query.bindValue(":type_Categorie", type_Categorie);

if(id_Categorie==  NULL || libelle_Categorie.isEmpty() || description_Categorie.isEmpty() || type_Categorie.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vid_Categoriee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * Categorie::afficher_c()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from Categorie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Categorie"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_Categorie"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_Categorie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_Categorie"));

    return model;
}
bool Categorie::modifier_c()
{
    QSqlQuery query ;
QString res= QString::number(id_Categorie);

  query.prepare("update Categorie set id_Categorie='"+res+"',libelle_Categorie='"+libelle_Categorie+"',description_Categorie='"+description_Categorie+"',type_Categorie='"+type_Categorie+"' where id_Categorie='"+res+"'");
                query.bindValue(":id_Categorie",res);
                query.bindValue(":libelle_Categorie",libelle_Categorie);
                query.bindValue(":description_Categorie",description_Categorie);
                query.bindValue(":type_Categorie",type_Categorie);




                if(id_Categorie==  NULL || libelle_Categorie.isEmpty() || description_Categorie.isEmpty() || type_Categorie.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vid_Categoriee!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

            return  query.exec();
}
bool Categorie::supprimer_c(int id_Categorie)
{
QSqlQuery query;
QString res= QString::number(id_Categorie);
query.prepare("Delete from Categorie where id_Categorie = :id_Categorie ");
query.bindValue(":id_Categorie", res);
return    query.exec();

if(id_Categorie==  NULL || libelle_Categorie.isEmpty() || description_Categorie.isEmpty() || type_Categorie.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification"),
         QObject::tr("Erreur champ vid_Categoriee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel * Categorie::rechercher_c(QString libelle_Categorie,int id_Categorie)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id_Categorie);
    if((libelle_Categorie.isEmpty()) && (id_Categorie==  NULL))
        {
            QMessageBox::critical(nullptr, QObject::tr("Rcherche"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
        }

    else if((not(libelle_Categorie.isEmpty())) && (id_Categorie==  NULL))
        model->setQuery("select * from Categorie where libelle_Categorie = '"+libelle_Categorie+"'");

    else if((libelle_Categorie.isEmpty()) && (id_Categorie!=  NULL))
        model->setQuery("select * from Categorie where id_Categorie = '"+res+"'");

    else model->setQuery("select * from Categorie where libelle_Categorie = '"+libelle_Categorie+"' and id_Categorie = '"+res+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Categorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_Categorie "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_Categorie"));
        return model;

}
QSqlQueryModel *Categorie:: tri_libelle_c()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from Categorie order by libelle_Categorie ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Categorie"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Categorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Categorie"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_Categorie"));



    return model;
}

QSqlQueryModel *Categorie:: tri_id_c()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from Categorie order by id_Categorie ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Categorie"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Categorie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Categorie"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_Categorie"));



    return model;
}
