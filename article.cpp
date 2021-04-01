#include "article.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"

Article::Article()
{
id_Article=0;
libelle_Article="";
description_Article="";
nbre_page=0;
priorite=0;
format="";

}

Article::Article(int id_Article,QString libelle_Article,QString description_Article,int nbre_page,int priorite,QString format)
{
  this->id_Article=id_Article;
  this->libelle_Article=libelle_Article;
  this->description_Article=description_Article;
  this->nbre_page=nbre_page;
  this->priorite=priorite;
  this->format=format;


}

bool Article::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_Article);
QString res1= QString::number(nbre_page);
QString res2= QString::number(priorite);

query.prepare("INSERT INTO article (id_Article,libelle_Article,description_Article,nbre_page,priorite,format) "
                    "VALUES (:id_Article, :libelle_Article, :description_Article,:nbre_page,:priorite,:format)");
query.bindValue(":id_Article", res);
query.bindValue(":libelle_Article", libelle_Article);
query.bindValue(":description_Article", description_Article);
query.bindValue(":nbre_page", res1);
query.bindValue(":priorite", res2);
query.bindValue(":format", format);

if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vid_Articlee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * Article::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from article");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Article"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_Article"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_Article"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbre_page"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("priorite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("format"));

    return model;
}
bool Article::modifier()
{
    QSqlQuery query ;
QString res= QString::number(id_Article);
QString res1= QString::number(nbre_page);
QString res2= QString::number(priorite);

  query.prepare("update article set id_Article='"+res+"',libelle_Article='"+libelle_Article+"',description_Article='"+description_Article+"',nbre_page='"+res1+"',priorite='"+res2+"' where id_Article='"+res+"'");
                query.bindValue(":id_Article",res);
                query.bindValue(":libelle_Article",libelle_Article);
                query.bindValue(":description_Article",description_Article);
                query.bindValue(":nbre_page",res1);
                query.bindValue(":priorite",res2);
                query.bindValue(":format",format);




                if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vid_Articlee!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

            return  query.exec();
}
bool Article::supprimer(int id_Article)
{
QSqlQuery query;
QString res= QString::number(id_Article);
query.prepare("Delete from article where id_Article = :id_Article ");
query.bindValue(":id_Article", res);
return    query.exec();

if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification"),
         QObject::tr("Erreur champ vid_Articlee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel * Article::rechercher(QString libelle_Article)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from article where libelle_Article = '"+libelle_Article+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Article"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_Article "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_Article"));
    if(libelle_Article.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Rcherche"),
             QObject::tr("Erreur champ vid_Articlee!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
        return model;

}
QSqlQueryModel *Article:: tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from article order by libelle_Article ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Article"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Article"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Article"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbre_page"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("priorite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("format"));



    return model;
}
