#include "missions.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"

missions::missions()
{
id_mission=0;
libelle="";
description="";
confidentialite="";

}

missions::missions(int id_mission,QString libelle,QString description,QString confidentialite)
{
  this->id_mission=id_mission;
  this->libelle=libelle;
  this->description=description;
  this->confidentialite=confidentialite;


}

bool missions::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_mission);

query.prepare("INSERT INTO mission (id_mission,libelle,description,confidentialite) "
                    "VALUES (:id_mission, :libelle, :description,:confidentialite)");
query.bindValue(":id_mission", res);
query.bindValue(":libelle", libelle);
query.bindValue(":description", description);
query.bindValue(":confidentialite", confidentialite);

if(id_mission==  NULL || libelle.isEmpty() || description.isEmpty() || confidentialite.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * missions::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from mission");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_mission"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("confidentialite"));


    return model;
}
bool missions::modifier()
{
    QSqlQuery query ;
QString res= QString::number(id_mission);

  query.prepare("update mission set id_mission='"+res+"',libelle='"+libelle+"',description='"+description+"',confidentialite='"+confidentialite+"' where id_mission='"+res+"'");
                query.bindValue(":id_mission",res);
                query.bindValue(":libelle",libelle);
                query.bindValue(":description",description);
                query.bindValue(":confidentialite",confidentialite);




                if(id_mission==  NULL || libelle.isEmpty() || description.isEmpty() || confidentialite.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vid_missione!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

            return  query.exec();
}
bool missions::supprimer(int id_missiond)
{
QSqlQuery query;
QString res= QString::number(id_missiond);
query.prepare("Delete from mission where id_mission = :id_mission ");
query.bindValue(":id_mission", res);
return    query.exec();

if(id_mission==  NULL || libelle.isEmpty() || description.isEmpty() || confidentialite.isEmpty()  )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel * missions::rechercher(QString libelle)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from mission where libelle = '"+libelle+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_mission"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    if(libelle.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Rcherche"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
        return model;

}
QSqlQueryModel *missions:: tri_id_mission()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from mission order by libelle ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_mission"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("confidentialite"));



    return model;
}
