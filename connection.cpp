#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("emna1");//inserer nom de l'utilisateur
db.setPassword("emna");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
