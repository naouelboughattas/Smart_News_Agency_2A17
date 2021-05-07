#include "journaliste.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"
#include "connection.h"
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
model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("diplome"));

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

}

QSqlQueryModel * gesjournaliste::rechercher(QString nom )
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';

    query.prepare("select * from journaliste where nom like :nom order by nom");
    query.addBindValue(nom);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("diplome"));



        return model;

}
QSqlQueryModel *gesjournaliste:: tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from journaliste order by nom ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("diplome"));



    return model;
}
QSqlQueryModel *gesjournaliste:: tri_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from journaliste order by prenom ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("diplome"));



    return model;
}

int gesjournaliste::chercher(QString diplome){
QSqlQuery query;
    query.prepare("Select * from JOURNALISTE where diplome='"+diplome+"'");
     query.exec();
    int a=0;
    while(query.next())
    {a++;
    }return a; };


