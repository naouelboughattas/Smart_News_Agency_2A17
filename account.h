#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class account
{
public:
    account();

    account(QString,QString,QString,QString,QString);
    QString get_username();
    QString get_password();


    bool ajouter();

private:
    QString username,password,nom,prenom,mail;
};

#endif // ACCOUNT_H
