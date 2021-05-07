#include "article.h"
#include"qsqlquery.h"
#include "qdebug.h"
#include "qobject.h"
#include "qmessagebox.h"

Article::Article()
{
id_Article=0;
libelle_Article="";
description_Article="";
nbre_page=0;
priorite=0;
format="";

}

Article::Article(int id_Article,QString libelle_Article,QString description_Article,int nbre_page,int priorite,QString format)
{
  this->id_Article=id_Article;
  this->libelle_Article=libelle_Article;
  this->description_Article=description_Article;
  this->nbre_page=nbre_page;
  this->priorite=priorite;
  this->format=format;


}

bool Article::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_Article);
QString res1= QString::number(nbre_page);
QString res2= QString::number(priorite);

query.prepare("INSERT INTO article (id_Article,libelle_Article,description_Article,nbre_page,priorite,format) "
                    "VALUES (:id_Article, :libelle_Article, :description_Article,:nbre_page,:priorite,:format)");
query.bindValue(":id_Article", res);
query.bindValue(":libelle_Article", libelle_Article);
query.bindValue(":description_Article", description_Article);
query.bindValue(":nbre_page", res1);
query.bindValue(":priorite", res2);
query.bindValue(":format", format);

if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )

{
    QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
         QObject::tr("Erreur champ vid_Articlee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
return    query.exec();
}
QSqlQueryModel * Article::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT* from article");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Article"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_Article"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_Article"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbre_page"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("priorite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("format"));

    return model;
}
bool Article::modifier()
{
    QSqlQuery query ;
QString res= QString::number(id_Article);
QString res1= QString::number(nbre_page);
QString res2= QString::number(priorite);

  query.prepare("update article set id_Article='"+res+"',libelle_Article='"+libelle_Article+"',description_Article='"+description_Article+"',nbre_page='"+res1+"',priorite='"+res2+"',format='"+format+"' where id_Article='"+res+"'");
                query.bindValue(":id_Article",res);
                query.bindValue(":libelle_Article",libelle_Article);
                query.bindValue(":description_Article",description_Article);
                query.bindValue(":nbre_page",res1);
                query.bindValue(":priorite",res2);
                query.bindValue(":format",format);




                if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )
                {
                    QMessageBox::critical(nullptr, QObject::tr("Verification de modification"),
                         QObject::tr("Erreur champ vid_Articlee!.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
                    return false;
                }

            return  query.exec();
}
bool Article::supprimer(int id_Article)
{
QSqlQuery query;
QString res= QString::number(id_Article);
query.prepare("Delete from article where id_Article = :id_Article ");
query.bindValue(":id_Article", res);
return    query.exec();

if(id_Article==  NULL || libelle_Article.isEmpty() || description_Article.isEmpty() || nbre_page==  NULL || priorite==  NULL || format.isEmpty() )
{
    QMessageBox::critical(nullptr, QObject::tr("Verification"),
         QObject::tr("Erreur champ vid_Articlee!.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
}
}

QSqlQueryModel * Article::rechercher(QString libelle_Article)
{
            QSqlQueryModel * model= new QSqlQueryModel();
            QSqlQuery query;
            libelle_Article='%'+libelle_Article+'%';

            query.prepare("select * from article where libelle_Article like :libelle_Article order by libelle_Article");
            query.addBindValue(libelle_Article);
            query.exec();

            model->setQuery(query);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Article"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Article"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Article"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbre_page"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("priorite"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("format"));



                return model;

}
QSqlQueryModel *Article:: tri_libelle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from article order by libelle_Article ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Article"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Article"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Article"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbre_page"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("priorite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("format"));



    return model;
}

QSqlQueryModel *Article:: tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from article order by id_Article ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_Article"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("libelle_Article"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("description_Article"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nbre_page"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("priorite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("format"));



    return model;
}

void Article::statistique(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
   // QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
   // QCPBars *nuclear = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  //  regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
  //  nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
  //  regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("nbre_page");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
  //  nuclear->setName("Nuclear");
  //  nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  //  nuclear->setBrush(QColor(250, 170, 20));
   // regen->setName("Regenerative");
  //  regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  //  regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
  //  nuclear->moveAbove(fossil);
 //   regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT id_Article) FROM article where nbre_page between 0 and 100");
    query.exec();
    int i;
    while(query.next())
    {
        i=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_Article) FROM article where nbre_page between 100 and 1000");
    query.exec();
    int j;
    while(query.next())
    {
        j=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_Article) FROM article where nbre_page > 1000");
    query.exec();
    int k;
    while(query.next())
    {
        k=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "[ 0 pages ,100 pages  ]" << "[ 100 pages , 1000 pages ]"<<"Plus que 1000 pages" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Intervalle de nombres livres");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << i << j << k;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
