#ifndef HISTORIQUES_H
#define HISTORIQUES_H
#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
#include <QDateTime>
class historiques
{
public:
    historiques();
    void write(QString);
    QString read();
    void write1(QString);
    QString read1();
    QString read2();
    void write2(QString);
    QString read3();
    void write3(QString);
private:
  QString mFilename;
  QString mFilename1;
  QString mFilename2;
  QString mFilename3;
};

#endif // HISTORIQUES_H
