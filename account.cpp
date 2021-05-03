#include "account.h"

account::account()
{
username="";
password="";
nom="";
prenom="";
mail="";

}
account::account(QString username,QString password,QString nom,QString prenom,QString mail)
{

    this->username=username;
    this->password=password;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;


}



QString account::get_username(){return  username;}

QString account::get_password(){return  password;}



bool account::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO login ( USERNAME, PASSWORD, NOM, PRENOM, MAIL) "
              "VALUES ( :username, :password, :nom, :prenom, :mail)");
query.bindValue(":username", username);
query.bindValue(":password", password);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":mail", mail);





return    query.exec();
}
