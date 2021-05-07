#include "historiques.h"

historiques::historiques()
{
    mFilename="C:/Users/user/Desktop/Nouveau dossier (6)/integration/historique4.txt";
    mFilename1="C:/Users/user/Desktop/Nouveau dossier (6)/integration/historique5.txt";
mFilename2="C:/historique6.txt";
mFilename3="C:/historique7.txt";
}
QString historiques::read()
{
QFile mFile(mFilename);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
QString historiques::read1()
{
QFile mFile(mFilename1);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
QString historiques::read2()
{
QFile mFile(mFilename2);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
QString historiques::read3()
{
QFile mFile(mFilename3);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream in (&mFile);
QString text=mFile.readAll();
mFile.close();
return  text;
}
void historiques::write(QString text)
{
    QString aux=read();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}
void historiques::write1(QString text)
{
    QString aux=read1();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename1);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}
void historiques::write2(QString text)
{
    QString aux=read2();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename2);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}
void historiques::write3(QString text)
{
    QString aux=read3();

    QDateTime datetime = QDateTime::currentDateTime();
    QString date =datetime.toString();
    date+= " ";
    aux+=date;
QFile mFile(mFilename3);
if (!mFile.open(QFile::WriteOnly | QFile::Text))
{
    qDebug () <<"il ne peut pas";
}
QTextStream out (&mFile);


aux+=text;
out << aux << "\n";
mFile.flush();
mFile.close();

}
