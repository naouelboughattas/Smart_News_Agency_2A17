#include "equipement.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QtDebug>
#include <QMessageBox>
#include<QSqlError>

equipement::equipement()
{
id_Equipement=0;
description="";
marque="";
libelle="";
prix="";

}

equipement::equipement(int id_Equipement,QString libelle,QString description,QString marque,QDate date_acqui,QString prix)
{this->id_Equipement=id_Equipement;
this->description=description;
this->marque=marque;
this->libelle=libelle;
this->description=description;
this->date_acqui=date_acqui;
this->prix=prix;}


int equipement::getid_Equipement(){return id_Equipement;}
void equipement::setid_Equipement(int id){this->id_Equipement =id;}


QString equipement::getlibelle(){return libelle;}
void equipement::setlibelle(QString nom){this->libelle=nom;}
QString equipement::getdescription(){return description;}
void equipement::setdescription(QString adresse){this->description=adresse;}
QString equipement::getmarque(){return marque;}
void equipement::setmarque(QString marque) {this->marque=marque;}
QDate equipement::getdate_acqui(){return date_acqui;}
void equipement::setdate_acqui(QDate date_acqui) {this->date_acqui=date_acqui;}
QString equipement::getprix(){return prix;}
void equipement::setprix(QString prix) {this->prix=prix;}



bool equipement::ajouter_Equipement()
{
    QSqlQuery query;
    QString res=QString::number(id_Equipement);


    query.prepare("INSERT INTO Equipements (id_equipement,libelle,description,marque,date_acqui,prix) VALUES(:id_equipement,:libelle,:description,:marque,:date_acqui,:prix)");

    query.bindValue(":id_equipement",res);
    query.bindValue(":libelle",libelle);
    query.bindValue(":description",description);
    query.bindValue(":marque",marque);
    query.bindValue(":date_acqui",date_acqui);
    query.bindValue(":prix",prix);
    if(res==  NULL || marque.isEmpty() || libelle.isEmpty() ||  description.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return query.exec();
}

QSqlQueryModel * equipement::afficher_Equipement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from equipements");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_equipement"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_acqui"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

bool equipement::modifier_Equipement()
{
    QSqlQuery query ;


QString res1   = QString::number(id_Equipement);




  query.prepare("update equipements set prix=:prix,marque=:marque,libelle=:libelle,date_acqui=:date_acqui,description='"+description+"' where id_equipement=:id_equipement");
  query.bindValue(":id_equipement", res1);
                query.bindValue(":prix",prix);
                query.bindValue(":marque",marque);
                query.bindValue(":libelle",libelle);
                query.bindValue(":description",description);
                query.bindValue(":date_acqui",date_acqui);
                if( marque.isEmpty() || libelle.isEmpty() || description.isEmpty())
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }



 return  query.exec();
}


bool equipement::supprimer_Equipement(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from equipements where id_equipement = :id_equipement ");
query.bindValue(":id_equipement", res);
return    query.exec();


}

QSqlQueryModel* equipement::recherche_id(QString id_equipement)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipements WHERE id_equipement=:id_equipement ");
    query.bindValue(":id_equipement", id_equipement);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_equipement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_acqui"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    return model;
}


QSqlQueryModel* equipement::recherche_libelle(QString libelle)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipements WHERE libelle=:libelle ");
    query.bindValue(":libelle", libelle);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_equipement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_acqui"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

QSqlQueryModel* equipement::recherche_marque(QString marque)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipements WHERE MARQUE=:marque ");
    query.bindValue(":marque", marque);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_equipement"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_acqui"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));
    return model;
}
