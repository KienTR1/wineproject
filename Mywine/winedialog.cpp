#include "winedialog.h"
#include "ui_winedialog.h"
#include "wine.h"
#include <QVector>
#include "QDateTime"
#include "QTextStream"
#include "QFile"

WineDialog::WineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WineDialog)
{
    ui->setupUi(this);
}


void WineDialog::Show(Wine* wine, int signal){
    ui->name->setText(wine->getname());
    ui->id->setText(QString::number(wine->getid()));
    ui->origin->setText(wine->getorigin());
    ui->company->setText(wine->getcompany());
    ui->capacity->setText(wine->getcapacity());
    ui->number->setText(QString::number(wine->getnumber()));
    ui->price->setText(QString::number(wine->getprice()));
    wine1 = wine;
    signal1 = signal;
    show();
}


void WineDialog::on_pushButton_clicked()
{
    int a = wine1->getnumber();
    wine1->setname(ui->name->text());
    wine1->setid((ui->id->text()).toInt());
    wine1->setorigin(ui->origin->text());
    wine1->setcompany(ui->company->text());
    wine1->setcapacity(ui->capacity->text());
    wine1->setnumber((ui->number->text()).toInt());
    wine1->setprice((ui->price->text()).toInt());
    wine1->setdateandtime(QDateTime::currentDateTime());
    QFile file(("test.txt"));
    QTextStream out(&file);
    if(file.open(QIODevice::Append)){
        QString str = (QDateTime::currentDateTime()).toString();
        if(signal1 == 1){
            if(a < wine1->getnumber()){
                out << endl << "\r\nImport " << wine1->getname() << " with " << wine1->getnumber() - a << " crates in " << str;
                file.close();
            }
            else if(a > wine1->getnumber()){
                out << endl << "\r\nExport " << wine1->getname() << " with " << a - wine1->getnumber() << " crates in " << str;
                file.close();
            }
        }
        else if(signal1 == 2){
            out << endl << "\r\nImport " << wine1->getname() << " with " << wine1->getnumber() << " crates in " << str;
            file.close();
        }
    }
    hide();
}

void WineDialog::on_pushButton_2_clicked()
{
    hide();
}

WineDialog::~WineDialog()
{
    delete ui;
}

