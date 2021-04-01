#ifndef ARTICLE_H
#define ARTICLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "qstring.h"

class Article
{
public:
    Article();
    Article(int,QString,QString,int,int,QString);
    QString getid_Article();
    QString getlibelle_Article();
    QString getdescription_Article();
    int getnbre_page();
    int getpriorite();
    QString getformat();
    void setid_Article(int);
    void setlibelle_Article(QString);
    void setdescription_Article(QString);
    void setnbre_page(int);
    void setpriorite(int);
    void setformat(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_id();



private :
    QString libelle_Article,description_Article,format;
    int id_Article,nbre_page,priorite;

};

#endif // ARTICLE_H
