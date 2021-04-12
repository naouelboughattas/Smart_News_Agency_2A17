#include "connection.h"
#include "QSqlDatabase"
connection::connection()
{

}

bool connection ::createConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2a");
    db.setUserName("esprit");
    db.setPassword("esprit");

    if (db.open())
        test=true;
    return test;
}
