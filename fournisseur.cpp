#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>

Fournisseur::Fournisseur()
{
id_Fournisseur=0;
adresse_Fournisseur="";
matricule_fiscale="";
nom_Fournisseur="";


}

Fournisseur::Fournisseur(int id_Fournisseur,QString nom_Fournisseur,QString adresse_Fournisseur,QString matricule_fiscale)
{this->id_Fournisseur=id_Fournisseur;
this->adresse_Fournisseur=adresse_Fournisseur;
this->matricule_fiscale=matricule_fiscale;
this->nom_Fournisseur=nom_Fournisseur;}


int Fournisseur::getid_Fournisseur(){return id_Fournisseur;}
void Fournisseur::setid_Fournisseur(int id){this->id_Fournisseur =id;}


QString Fournisseur::getnom_Fournisseur(){return nom_Fournisseur;}
void Fournisseur::setnom_Fournisseur(QString nom){this->nom_Fournisseur=nom;}
QString Fournisseur::getadresse_Fournisseur(){return adresse_Fournisseur;}
void Fournisseur::setadresse_Fournisseur(QString adresse){this->adresse_Fournisseur=adresse;}
QString Fournisseur::getmatricule_fiscale(){return matricule_fiscale;}
void Fournisseur::setmatricule_fiscale(QString matricule) {this->matricule_fiscale=matricule;}


bool Fournisseur::ajouter_Fournisseur()
{
    QSqlQuery query;
    QString res=QString::number(id_Fournisseur);

    query.prepare("INSERT INTO fournisseurs (id_fournisseur,nom_fournisseur,adresse_fournisseur,matricule_fiscale) VALUES(:id_fournisseur,:nom_fournisseur,:adresse_fournisseur,:matricule_fiscale)");

    query.bindValue(":id_fournisseur",res);
    query.bindValue(":nom_fournisseur",nom_Fournisseur);
    query.bindValue(":adresse_fournisseur",adresse_Fournisseur);
    query.bindValue(":matricule_fiscale",matricule_fiscale);
    if(res==  NULL || nom_Fournisseur.isEmpty() || adresse_Fournisseur.isEmpty() || matricule_fiscale.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return query.exec();

    return query.exec();
}

QSqlQueryModel * Fournisseur::afficher_Fournisseur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from Fournisseurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Fournisseur"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Fournisseur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse_Fournisseur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule_fiscale"));


    return model;
}

bool Fournisseur::modifier_Fournisseur(int idd,QString nom_Fournisseur,QString adresse_Fournisseur,QString matricule_fiscale)
{
    QSqlQuery query ;
QString res1   = QString::number(idd);



  query.prepare("update fournisseurs set nom_fournisseur=:nom_Fournisseur,adresse_fournisseur=:adresse_Fournisseur,matricule_fiscale=:matricule_fiscale where id_fournisseur=:id_fournisseur");
                query.bindValue(":id_Fournisseur",res1);
                query.bindValue(":nom_Fournisseur",nom_Fournisseur);
                query.bindValue(":adresse_Fournisseur",adresse_Fournisseur);
                query.bindValue(":matricule_fiscale",matricule_fiscale);

                if(res1==  NULL || nom_Fournisseur.isEmpty() || adresse_Fournisseur.isEmpty() || matricule_fiscale.isEmpty())
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vide!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

 return  query.exec();
}

bool Fournisseur::supprimer_Fournisseur(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fournisseurs where id_fournisseur = :id_fournisseur ");
query.bindValue(":id_fournisseur", res);
return    query.exec();


}


QSqlQueryModel *Fournisseur::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from fournisseurs order by id_fournisseur ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_fournisseur"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule_fiscale"));




    return model;
}

QSqlQueryModel *Fournisseur::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from fournisseurs order by nom_fournisseur ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_fournisseur"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule_fiscale"));




    return model;
}


QSqlQueryModel *Fournisseur::trier_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from fournisseurs order by matricule_fiscale ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_fournisseur"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse_fournisseur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule_fiscale"));




    return model;
}

