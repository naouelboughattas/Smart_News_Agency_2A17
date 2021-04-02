#include "journaliste.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"

gesjournaliste::gesjournaliste()
{
id=0;
nom="";
prenom="";
fonction="";
diplome="";

}

gesjournaliste::gesjournaliste(int id,QString nom,QString prenom,QString fonction,QString diplome)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->fonction=fonction;
  this->diplome=diplome;


}

bool gesjournaliste::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);

query.prepare("INSERT INTO journaliste (id,nom,prenom,fonction,diplome) "
                    "VALUES (:id, :nom, :prenom,:fonction,:diplome)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":fonction", fonction);
query.bindValue(":diplome", diplome);

if(id==  NULL || nom.isEmpty() || prenom.isEmpty() || fonction.isEmpty() || diplome.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * gesjournaliste::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from journaliste");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

    return model;
}
bool gesjournaliste::modifier()
{
    QSqlQuery query ;
QString res= QString::number(id);

  query.prepare("update journaliste set id='"+res+"',nom='"+nom+"',prenom='"+prenom+"',fonction='"+fonction+"',diplome='"+diplome+"' where id='"+res+"'");
                query.bindValue(":id",res);
                query.bindValue(":nom",nom);
                query.bindValue(":prenom",prenom);
                query.bindValue(":fonction",fonction);
                query.bindValue(":diplome",diplome);




                if(id==  NULL || nom.isEmpty() || prenom.isEmpty() || fonction.isEmpty() || diplome.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

            return  query.exec();
}
bool gesjournaliste::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from journaliste where ID = :id ");
query.bindValue(":id", res);
return    query.exec();

if(id==  NULL || nom.isEmpty() || prenom.isEmpty() || fonction.isEmpty() || diplome.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification"),
         QObject::tr("Erreur champ vide!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel * gesjournaliste::rechercher(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from journaliste where NOM = '"+nom+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    if(nom.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Rcherche"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
        return model;

}
QSqlQueryModel *gesjournaliste:: tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from journaliste order by nom ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("fonction"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("diplome"));



    return model;
}
