#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include<QSqlError>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QValidator>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QIntValidator>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include "Sponsoring.h"
#include<QSqlQueryModel>

#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QIntValidator>
#include<QValidator>
#include<QSqlQueryModel>
#include<QSqlError>
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include<QPrinter>
#include "presentateur.h"
#include<QTimer>
#include<QTableWidget>
#include<QtWidgets>
#include <QTimer>
#include <QSqlQuery>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPrintDialog>
#include<QSlider>
#include <QtDebug>
#include <QObject>
#include<QChartView>
#include<QChart>
#include<QPrintDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlError>
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include<QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtPrintSupport/QPrinterInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QDebug>
#include <QPrintDialog>
#include <QChartView>
#include <QGraphicsView>
#include <QtCharts>
#include <QTabWidget>
//#include "qrcodegen.hpp"
#include <QLabel>
#include <QMovie>
#include<QMessageBox>
#include <QRegExpValidator>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QLineEdit>
#include <QTimer>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QPainter>
#include <QPdfWriter>
#include <QDir>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include<QMessageBox>
#include <QRegExpValidator>
#include <QPainter>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QLineEdit>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QTimer>
#include <QDateTime>
#include<QDate>
#include "presentateur.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
            ui->setupUi(this);
            ui->le_duree->setValidator( new QIntValidator(15, 999, this));
            ui->le_nom->setInputMask("aaaaaaaaaaaaaaaaaaaa");
            ui->le_nomsupp->setInputMask("aaaaaaaaaaaaaaaaaaaa");
            ui->tab_emi->setModel(E.afficher());
            ui->stat->addWidget(E.stat_type(), 0, 0);
 //sara
             ui->tab_sponsoring->setModel(s.afficher());
             //rihem
             ui->tab_P->setModel(p.afficher());
             QTimer *timer=new QTimer(this);
             connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
             timer->start();


             QDate dateTime=QDate::currentDate();
             QString datetimetext=dateTime.toString();
             ui->datetime->setText(datetimetext);

              //ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
                 ui->le_age->setValidator(new QIntValidator(0,99,this));
              ui->le_tel->setValidator(new QIntValidator(0,99999999,this));
               ui->tab_P->setModel(p.afficher());
               p.stat_age()->setParent(ui->stat_2);
             //rihem
             /*  foreach(const QSerialPortInfo &serial_info,QSerialPortInfo::availablePorts() ){


                   qDebug()<<"PUERTO /"<<serial_info.portName();
                   qDebug()<<"cendr id /"<<serial_info.vendorIdentifier();
                   qDebug()<<"prouct id id /"<<serial_info.productIdentifier();

               }

               int ret=A.connect_arduino(); // lancer la connexion à arduino
                       switch(ret){
                       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                           break;
                       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                          break;
                       case(-1):qDebug() << "arduino is not available";
                       }
                        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                        //le slot update_label suite à la reception du signal readyRead (reception des données).

*/


}

MainWindow::~MainWindow()
{
    delete ui;
}



// login (username + pass)
void MainWindow::on_logb_clicked()
{
    QStackedWidget stackedWidget;
                        connect(ui->stackedWidget, SIGNAL(clicked()), this, SLOT(viewData));
                              QString username=ui->lineEdit_name->text();
                                QString password = ui->lineEdit_pass->text();
                                if(username == "mehdi" && password == "mehdi")
                                { QMessageBox::information(this, "Login", "Username and password is correct, Welcome mahdi");
                                ui->stackedWidget->setCurrentIndex(2);
                                }


                                if(username == "sara" && password == "sara")
                                { QMessageBox::information(this, "Login", "Username and password is correct, Welcome Sara");
                                ui->stackedWidget->setCurrentIndex(4);
                                }
                                if(username == "rihem" && password == "rihem")
                                { QMessageBox::information(this, "Login", "Username and password is correct, Welcome rihem");
                                ui->stackedWidget->setCurrentIndex(3);
                                }
                                if(username == "taher" && password == "taher")
                                { QMessageBox::information(this, "Login", "Username and password is correct, Welcome taher");
                                ui->stackedWidget->setCurrentIndex(5);
                                }
                               ui->lineEdit_name->clear();
                               ui->lineEdit_pass->clear();
}
//gestion emission
void MainWindow::on_pb_ajouter_clicked()
{
    int duree=ui->le_duree->text().toInt();
        QString nom=ui->le_nom->text();
        QString type=ui->le_type->currentText();
       // QString horaire=ui->le_horaire->text();
        QString horaire = ui->le_horaire->date().toString("dd/MM/yyyy");
        Emission e(duree,nom,type,horaire);
        bool test=e.ajouter();
        QMessageBox msgBox;

          if(test)
          {
              ui->tab_emi->setModel(E.afficher());
               msgBox.setText("ajout avec succes.");
                ui->le_duree->clear();
                ui->le_nom->clear();
               // ui->le_type->clear();
                ui->stat->addWidget(E.updatestat_type(), 0, 0);
                ui->le_horaire->clear();
          }

        else
            msgBox.setText("Echec d'ajout");
            msgBox.exec();

   }


void MainWindow::on_pb_supp_clicked()
{
    Emission e1;
        e1.setnom(ui->le_nomsupp->text());
        bool test=e1.supprimer(e1.getnom());
        QMessageBox msgBox;
        if(test)
        {
            ui->tab_emi->setModel(E.afficher());
            msgBox.setText("Suppression avec succes.");
            ui->stat->addWidget(E.updatestat_type(), 0, 0);
            ui->le_duree->clear();
            ui->le_nom->clear();
            //ui->le_type->clear();
            ui->le_horaire->clear();
            ui->le_nomsupp->clear();
        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();

}
/*void MainWindow::on_tab_emi_activated(const QModelIndex &index)
{
 QString val=ui->tab_emi->model()->data(index).toString();
 QSqlQuery qry;
 qry.prepare("select * from EMISSION where nom='"+val+"'");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->le_nom->setText(qry.value(0).toString());
   //ui->le_horaire->setDate(qry.value(1).toString());
   ui->le_horaire->setDate(QDate::fromString(qry.value(3).toString(),"dd.MM.yyyy"));
  // ui->le_horaire->setText(qry.value(1).toString());
   ui->le_type->setCurrentText(qry.value(2).toString());
   ui->le_duree->setText(qry.value(3).toString());

  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}*/
//gestion emission
void MainWindow::on_bt_modif_clicked()
{
    QString nom=ui->le_nom->text();
            QString type=ui->le_type->currentText();
            QString horaire=ui->le_horaire->text();
            int duree=ui->le_duree->text().toInt();
            QString res = QString::number(duree);
            QSqlQuery quer;
            quer.prepare("update EMISSION set duree='"+res+"' ,nom='"+nom+"', type='"+type+"', horaire='"+horaire+"' where nom='"+nom+"'");
              if(quer.exec())
              {

                  ui->tab_emi->setModel(E.afficher());
                  ui->stat->addWidget(E.updatestat_type(), 0, 0);
               QMessageBox::information(nullptr,QObject::tr("OK"),
                                        QObject::tr("modification effectué \n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
              }
              else
                  QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                        QObject::tr("modification non effectué \n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
}


//gestion emission
void MainWindow::on_rech_textChanged(const QString &arg1)
{
    QString search=arg1;
    ui->tab_emi->setModel(E.Rechercher(search));
}
//gestion emission
void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    Emission e;
        QString type="";

        if(ui->radioButton->isChecked())
            type="ASC";
        else if(ui->radioButton_2->isChecked())
            type="DESC";

        if(arg1 != "Choisir")
            ui->tab_emi->setModel(e.Trier(type,arg1));

        else  ui->tab_emi->setModel(e.afficher());

}
//gestion emission
void MainWindow::on_radioButton_clicked()
{
    Emission e;
       QString type="";


       if(ui->radioButton->isChecked())
           type="ASC";
       else if(ui->radioButton_2->isChecked())
           type="DESC";

       if(ui->comboBox->currentText() != "Choisir")
           ui->tab_emi->setModel(e.Trier(type,ui->comboBox->currentText()));

       else  ui->tab_emi->setModel(e.afficher());
}
//gestion emission
void MainWindow::on_radioButton_2_clicked()
{
    Emission e;
        QString type="";

        if(ui->radioButton->isChecked())
            type="ASC";
        else if(ui->radioButton_2->isChecked())
            type="DESC";

        if(ui->comboBox->currentText() != "Choisir")
            ui->tab_emi->setModel(e.Trier(type,ui->comboBox->currentText()));


        else  ui->tab_emi->setModel(e.afficher());
}
//gestion emission
void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
          QTextStream out(&strStream);

       const int rowCount = ui->tab_emi->model()->rowCount();
       const int columnCount = ui->tab_emi->model()->columnCount();
       out <<  "<html>\n"
               "<head>\n"
       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
       <<  QString("<title>%1</title>\n").arg("strTitle")
       <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

      //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Liste Des Emissions  </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
       if (!ui->tab_emi->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->tab_emi->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

                                               // data table
               for (int row = 0; row < rowCount; row++) {
                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                  for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_emi->isColumnHidden(column)) {
         QString data = ui->tab_emi->model()->data(ui->tab_emi->model()->index(row, column)).toString().simplified();
         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                       }
                                                   }
                          out << "</tr>\n";
                                               }
                                out <<  "</table> </center>\n"
                                        "</body>\n"
                                      "</html>\n";
          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(fileName);

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}
//gestion emission
void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    QString dates = date.toString("dd/MM/yyyy");
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery Query;
        Query.prepare("select nom from EMISSION where HORAIRE=:h");
        Query.bindValue(":h",dates);
        Query.exec();

         model->setQuery(Query);
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("Emission"));
         ui->tableView->setModel(model);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sponsoring
void MainWindow::on_ajouter_2_clicked()
{   int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString domaine=ui->domaine->text();
    int duree=ui->duree->text().toInt();
    int budget=ui->budget->text().toInt();
    Sponsoring s(id,nom,domaine,duree,budget);
    bool test=s.ajouter();
    QMessageBox msgBox;
         if(test)
         {    ui->tab_sponsoring->setModel(s.afficher());
              msgBox.setText("ajout avec succes.");
         }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
}

void MainWindow::on_supprimer_3_clicked()
{         Sponsoring s1;
          s1.setid(ui->id_2->text().toInt());
          bool test=s1.supprimer(s1.getid());
          QMessageBox msgBox;
          if(test) 
          {    ui->tab_sponsoring->setModel(s1.afficher());
               msgBox.setText("Suppression avec succes.");
          }
          else
              msgBox.setText("Echec de suppression");
              msgBox.exec();
}

void MainWindow::on_modif_clicked()
{
    Sponsoring s;
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString domaine=ui->domaine->text();
    int duree=ui->duree->text().toInt();
    int budget=ui->budget->text().toInt();
    QString res1 = QString::number(id);
    QString res2 = QString::number(duree);
    QString res3 = QString::number(budget);
    QSqlQuery quer;
    quer.prepare("update SPONSORING set id='"+res1+"' ,nom='"+nom+"', domaine='"+domaine+"', duree='"+res2+"' , budget='"+res3+"' where nom='"+nom+"'");
    if(quer.exec())
              {    ui->tab_sponsoring->setModel(s.afficher());
                   QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("modification effectué \n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
              }
              else
                  QMessageBox::critical(nullptr,QObject::tr("not OK"),
                  QObject::tr("modification non effectué \n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_rech_2_textChanged(const QString &arg1)
{   QString search=arg1;
           ui->tab_sponsoring->setModel(s.Rechercher(search));
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{    Sponsoring s;
        QString nom="";
        if(ui->radioButton->isChecked())
            nom="ASC";
        else if(ui->radioButton_2->isChecked())
            nom="DESC";
        if(arg1 != "Choisir")
            ui->tab_sponsoring->setModel(s.Trier(nom,arg1));
        else  ui->tab_sponsoring->setModel(s.afficher());
}

void MainWindow::on_radioButton_3_clicked()
{    Sponsoring s;
        QString nom="";
        if(ui->radioButton->isChecked())
            nom="ASC";
        else if(ui->radioButton_2->isChecked())
            nom="DESC";
        if(ui->comboBox->currentText() != "Choisir")
            ui->tab_sponsoring->setModel(s.Trier(nom,ui->comboBox->currentText()));
        else  ui->tab_sponsoring->setModel(s.afficher());
}

void MainWindow::on_radioButton_4_clicked()
{        QString nom="";
        if(ui->radioButton->isChecked())
            nom="ASC";
        else if(ui->radioButton_2->isChecked())
            nom="DESC";
        if(ui->comboBox->currentText() != "Choisir")
            ui->tab_sponsoring->setModel(s.Trier(nom,ui->comboBox->currentText()));
        else  ui->tab_sponsoring->setModel(s.afficher());
}

void MainWindow::on_camera_clicked()
{
    c= new camera();
       c->show();
}
//fin sponsoring
////////////////////////////////////////////////////////////
/// /////////////////////////////////////////

//rihem

void MainWindow::showTime()
{
  QTime time=QTime::currentTime ();
  QString time_text=time.toString("hh : mm :ss");
  ui->timeoclock->setText(time_text);
}

 void MainWindow::on_pb_ajouter_2_clicked()
{

    if(controlSaisie())
    {QString cinP=ui->le_cin->text() ;
       int age=ui->le_age->text().toInt() ;
       int num_tel=ui->le_tel->text().toInt() ;
       QString nom=ui->le_nom_2->text() ;
       QString prenom=ui->le_prenom->text() ;
       /*ui->tab_P->setModel(p.afficher()) ;*/

    presentateur p(cinP,age,num_tel,nom,prenom);

       bool test=p.ajouter(); //etablir la connexion
       QMessageBox msgBOX;
    if(test)
      {

        QMessageBox::information(nullptr, QObject::tr("Ok"),

                     QObject::tr("Ajout effectue.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_P->setModel(p.afficher()) ;
       p.stat_age()->setParent(ui->stat_2);
}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Okay") ,
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit .") , QMessageBox::Cancel) ;
}
else

        { QMessageBox::critical(nullptr, QObject::tr("not ok"),

                                    QObject::tr("veuiller remplir tous les champs correctement.\n"

                                                "Click cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pb_supprimer_clicked()
{

presentateur p ;

       // int cinP=ui->cinsup->text().toInt() ;
        p.setcinP(ui->cinsup->text()) ;
        bool test=p.supprimer(p.getcinP()) ;
        QMessageBox msgBox ;
        if(test)
           { msgBox.setText("suppression avec succes") ;
             ui->tab_P->setModel(p.afficher()) ;
        p.stat_age()->setParent(ui->stat_2);}

                    else

                msgBox.setText("impossible de supprimer");
                msgBox.exec() ;
   //refresh maj
}




bool MainWindow::controlSaisie(){



    if (

           ! (ui->le_nom_2->text().contains(QRegExp("^[A-Za-z]+$"))) ||

           ! (ui->le_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||
           // ! (ui->le_cin->text().contains(QRegExp("^[0-9]"))) ||

            ui->le_cin->text().isEmpty() ||

            ui->le_cin->text() =="" ||

            ui->le_age->text().isEmpty() ||

            ui->le_age->text().toInt() == 0 ||
            ui->le_tel->text().isEmpty() ||

            ui->le_tel->text().toInt() == 0 )

        return 0;

    else

        return 1;

}

void MainWindow::on_ok_clicked()
{
    QString cinP=ui->rechercher->text();

             ui->tab_P->setModel(p.rechercher(cinP));
    }
void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
    QString value=ui->rechercher->text();

             ui->tab_P->setModel(p.rechercher_prenom(arg1));



}
void MainWindow::on_comboBox_3_highlighted(const QString &arg1)
{
    presentateur p;
    QString type="";

    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(arg1 != "Choisir")
        ui->tab_P->setModel(p.Trier(type,arg1));

    else  ui->tab_P->setModel(p.afficher());

}
void MainWindow::on_up_clicked()
{
    presentateur p;
    QString type="";


    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(ui->comboBox_3->currentText() != "Choisir")
        ui->tab_P->setModel(p.Trier(type,ui->comboBox_3->currentText()));

    else  ui->tab_P->setModel(p.afficher());
}
void MainWindow::on_down_clicked()
{
    presentateur p;
    QString type="";

    if(ui->up->isChecked())
        type="ASC";
    else if(ui->down->isChecked())
        type="DESC";

    if(ui->comboBox_3->currentText() != "Choisir")
        ui->tab_P->setModel(p.Trier(type,ui->comboBox_3->currentText()));


    else  ui->tab_P->setModel(p.afficher());
}

void MainWindow::on_tab_P_activated(const QModelIndex &index)
{
 QString select=ui->tab_P->model()->data(index).toString();
 QSqlQuery qry;

  qry.prepare("select * from PRESENTATEURS where  NOM LIKE '"+select+"%'  ");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->le_cin->setText(qry.value(0).toString());
   ui->le_nom_2->setText(qry.value(1).toString());
   ui->le_prenom->setText(qry.value(2).toString());
   ui->le_age->setText(qry.value(3).toString());
   ui->le_tel->setText(qry.value(4).toString());


  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}
void MainWindow::on_modifier_clicked()
{

        QString cinP=ui->le_cin->text();
        QString nom=ui->le_nom_2->text();
        QString prenom=ui->le_prenom->text();
        int age=ui->le_age->text().toInt();
         int num_tel=ui->le_tel->text().toInt();


        QString res2 = QString::number(age);

        QString res3 = QString::number(num_tel);

        QSqlQuery quer;
        quer.prepare("update PRESENTATEURS set CINP='"+cinP+"' ,NOM='"+nom+"',PRENOM='"+prenom+"',AGE='"+res2+"', NUM_TEL='"+res3+"' where  NOM='"+nom+"'");
          if(quer.exec())
          {

              ui->tab_P->setModel(p.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("modification effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
          }
          else
              QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                    QObject::tr("modification non effectué \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_pdf_clicked()
{

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A3);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM PRESENTATEURS ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE PRESENTATEURS  <br></h1>\n <br> <table>  <tr>  <th>CINP </th> <th>NOM </th> <th>PRENOM </th> <th>AGE </th> <th>NUM_TEL </th> </tr>" ;


        while ( q.next()) {


            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td>" +q.value(1).toString() +"</td> <td>" +q.value(2).toString() +"</td><td>" +q.value(3).toString() +"</td> <td>" +q.value(4).toString() +"</td><td>" +q.value(5).toString() +"</td><td>"  "</td></td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }



QMediaPlayer *player;
void MainWindow::on_pushButtons_clicked()
{
    player= new QMediaPlayer;
                player->setMedia(QUrl("C:/Users/rihem/Desktop/damrli hyety/musiqaa.wav"));
                   player->play();
                   qDebug()<<player->errorString();
}

void MainWindow::on_pushButton_p_clicked()
{
    player->stop();
}


void MainWindow::on_sliderV_sliderMoved(int position)
{


    player->setVolume(position);

}
void MainWindow::update_label()
{
 data="";

while((A.getdata().size()<5))
{
    QString key;
data=A.read_from_arduino();
qDebug() << data;
break;

}
if(!data.isEmpty())
{qDebug() << data;

//qDebug()<<data.toLongLong();
}
if(data!="")
{

//qDebug()<<data.toLongLong();
qDebug()<<"Prenom:"<<A.cherchercode(data);
if(A.cherchercode(data)!="")
{
  A.write_to_arduino("**Authorised acces**");//presentateur existe
}

else if(A.cherchercode(data)=="")
A.write_to_arduino("**Acces denied**");//presentateur n'existe pas


}
 data="";
}





/*void MainWindow::on_pb_qrcode_clicked()
{
    using namespace qrcodegen;

           ///////////////// FETCH DATA FROM DATABASE ////////////////////////
           QTableView tab_equipement;
           QSqlQueryModel * Mod=new  QSqlQueryModel();
           QString value=ui->le_cin->text();


                QSqlQuery qry;




                qry.prepare("select * from equi where reference='"+value+"'");
                qry.exec();
                Mod->setQuery(qry);
                tab_equipement.setModel(Mod);


               ///////////////// SAVING DATA ///////////
               QString reference = tab_equipement.model()->data(tab_equipement.model()->index(0, 0)).toString().simplified();
               QString libelle= tab_equipement.model()->data(tab_equipement.model()->index(0, 1)).toString().simplified();
               QString emplacement = tab_equipement.model()->data(tab_equipement.model()->index(0, 2)).toString().simplified();
               QString type = tab_equipement.model()->data(tab_equipement.model()->index(0, 3)).toString().simplified();


           QString text = reference+"\n"+libelle+"\n"+emplacement+"\n"+type+"\n";
             // Create the QR Code object
             QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );

             qint32 sz = qr.getSize();
             QImage im(sz,sz, QImage::Format_RGB32);
               QRgb black = qRgb( 191,112,105 );
               QRgb white = qRgb(255,255,255);
             for (int y = 0; y < sz; y++)
               for (int x = 0; x < sz; x++)
                 im.setPixel(x,y,qr.getModule(x, y) ? black : white );//setpixelmap tafichilek qr code
             ui->qrcode->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
}
*/
//rihem

/*void MainWindow::on_pushButtons_clicked()
{

}*/



void MainWindow::on_menu1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_menu2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_menu3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_menu4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButton_E_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonsS_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonin_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_menu_taher_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_ajouteremp_clicked()
{
    int CIN=ui->CIN->text().toInt();
    QString Nom=ui->Nomemp->text();
    QString Prenom=ui->Prenomemp->text();
    QString Adresse=ui->Adresseemp->text();
    QString Adressemail=ui->Adresse_mailemp->text();
    QString Date_naissance =ui->Datedenaissanceemp->text();

    invites tmpinvites(CIN, Nom, Prenom, Adresse, Adressemail, Date_naissance);

    bool test=tmpinvites.ajouter();
    if(test){
        ui->affichageemp->setModel(tmpinvites.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier ->setIcon(QIcon(""));
        notifier->show();
        notifier->showMessage("invite AJOUTER " ,"\n",QSystemTrayIcon::Information,10000);

    }
    else
            {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
        notifier ->setIcon(QIcon(""));
        notifier->show();
        notifier->showMessage("invite non AJOUTER " ,"\n",QSystemTrayIcon::Critical,10000);
    }
}


void MainWindow::on_rechercheemp_clicked()
{
    QString id =ui->id_rechercheemp->text();
    ui->affichageemp->setModel(tmpinvites.recherche(id));

}


void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer *player=new QMediaPlayer;
    QVideoWidget *VW=new QVideoWidget;
    player->setVideoOutput(VW);
    player->setMedia(QUrl::fromLocalFile("C:/cpt.mpg"));
    VW->setGeometry(100,100,300,400);
    VW->show();
    player->play();
}


void MainWindow::on_pushButton_clicked()
{
    invites I;
              QSqlQueryModel * model=new QSqlQueryModel();
                model=I.Find_Activite();

              QString textData= "CIN ; nom ; prénom ; adresse ; adresse_mail ; date_de_naissance \n";
              int rows=model->rowCount();
              int columns=model->columnCount();
              for (int i = 0; i < rows; i++)
              {
                  for (int j = 0; j < columns; j++)
                  {
                      textData += model->data(model->index(i,j)).toString();
                      textData +=" ; ";
                  }
                  textData += "\n";
              }
              QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
              if (!fileName.isEmpty())
                  if (QFileInfo(fileName).suffix().isEmpty())
                      fileName.append(".csv");
              QFile csvfile(fileName);
              if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
              {
                  QTextStream out(&csvfile);
                  out<<textData;
              }
              csvfile.close();
}


void MainWindow::on_imprimer_emp_clicked()
{
    QPrinter rd;
            QPrintDialog d(&rd,this);
            d.setWindowTitle("Print Liste Employés");
            d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
            if (d.exec() != QDialog::Accepted)
                return ;
}


void MainWindow::on_pdf_em_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A3);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM invites ");
    q.exec();
    QString pdf="<br> <h1  style='color:red'>LISTE invites  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th> PRENOM </th><th> ADRESSE </th> <th>EMAIL </th><th>DATE DE NAISSANCE </th></tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td>" +q.value(1).toString() +"</td> <td>" +q.value(2).toString() +"</td><td>" +q.value(3).toString() +"</td> <td>" +q.value(4).toString() +"</td><td>" +q.value(5).toString() +"</td><td>" +q.value(6).toString() +"</td><td>"  ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}


void MainWindow::on_tri_emp_clicked()
{
     ui->affichageemp->setModel(tmpinvites.trier());
}


void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("3"); //envoyer 3 à arduino

}


void MainWindow::on_pushButton_5_clicked()
{
    A.write_to_arduino("4"); //envoyer 4 à arduino

}



