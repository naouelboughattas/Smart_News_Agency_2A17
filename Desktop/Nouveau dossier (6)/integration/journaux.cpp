#include "journaux.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
journaux::journaux()
{
id=0; libelle_journal="" ;proprietaire_journal="" ;adresse_siege="";
}

journaux::journaux(int id,QString adresse_siege,QString proprietaire_journal , QString  libelle_journal)
{
this->id=id;
this->adresse_siege=adresse_siege;
this->proprietaire_journal=proprietaire_journal;
this->libelle_journal=libelle_journal;
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


bool journaux::ajouter()
{
QSqlQuery query;
QString res   = QString::number(id);



query.prepare("INSERT INTO journaux (id,adresse_siege,proprietaire_journal,libelle_journal) "
                    "VALUES (:id,  :adresse_siege, :proprietaire_journal, :libelle_journal )");
query.bindValue(":id", res);
query.bindValue(":adresse_siege", adresse_siege);
query.bindValue(":proprietaire_journal", proprietaire_journal);
query.bindValue(":libelle_journal", libelle_journal);


return    query.exec();
}
QSqlQueryModel * journaux::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from journaux");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse_siege"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("proprietaire_journal"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("libelle_journal"));


    return model;
}
bool journaux::modifier()
{
    QSqlQuery query ;
QString res   = QString::number(id);

  query.prepare("update journaux set id='"+res+"',adresse_siege='"+adresse_siege+"',proprietaire_journal='"+proprietaire_journal+"',libelle_journal='"+libelle_journal+"' where id='"+res+"'");
                query.bindValue(":id",res);
                query.bindValue(":adresse_siege",adresse_siege);
                query.bindValue(":proprietaire_journal",proprietaire_journal);
                query.bindValue(":libelle_journal",libelle_journal);



            return  query.exec();
}
bool journaux::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from journaux where id = :id ");
query.bindValue(":id", res);
return    query.exec();


}

QSqlQueryModel *journaux:: tri_adresse_siege()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from journaux order by adresse_siege ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_siege"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("proprietaire_journal"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("libelle_journal"));




    return model;
}
QSqlQueryModel * journaux::rechercher(QString adresse_siege)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from journaux where adresse_siege = '"+adresse_siege+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_siege"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("proprietaire_journal"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("libelle_journal"));


        return model;


}
