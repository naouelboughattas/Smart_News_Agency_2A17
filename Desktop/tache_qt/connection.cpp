#include "connection.h"
#include "QSqlDatabase"
connection::connection()
{

}

bool connection ::createConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2aa");
    db.setUserName("esprit");
    db.setPassword("esprit");

    if (db.open())
        test=true;
    return test;
}
