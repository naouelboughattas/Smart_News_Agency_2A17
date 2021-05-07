#include "account.h"

account::account()
{
username="";
password="";
nom="";
prenom="";


}
account::account(QString username,QString password,QString nom,QString prenom)
{

    this->username=username;
    this->password=password;
    this->nom=nom;
    this->prenom=prenom;


}



QString account::get_username(){return  username;}

QString account::get_password(){return  password;}



bool account::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO login ( USERNAME, PASSWORD, NOM, PRENOM) "
              "VALUES ( :username, :password, :nom, :prenom)");
query.bindValue(":username", username);
query.bindValue(":password", password);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);





return    query.exec();
}

