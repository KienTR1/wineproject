#include "mywine.h"
#include "ui_mywine.h"
#include "wine.h"
#include <QListWidgetItem>
#include "winedialog.h"
#include <QVector>

#include <QFile>
#include "QDateTime"
#include "QTextStream"
#include "QString"


Mywine::Mywine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mywine)
{
    ui->setupUi(this);

    m_winedialog = new WineDialog;
    f_winefind = new WinefindDialog;
}


void Mywine::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    m_winedialog->Show((Wine*) item, 1);
}

void Mywine::Addwine(Wine *wine){
    ui->listWidget->addItem((QListWidgetItem*) wine);
    pwine.push_back(wine);
}

void Mywine::Addwine(QString s){
    Wine* wine = new Wine(s);
    Addwine(wine);
}

void Mywine::Addwine(QString s, int id, QString nguongoc, QString hang, QString dungtich, int soluong, int gia){
    Wine *wine = new Wine(s,id,nguongoc,hang,dungtich,soluong,gia);
    Addwine(wine);

}

void Mywine::Removewine(Wine *wine){
    QFile file(("test.txt"));
    QTextStream out(&file);
    if(file.open(QIODevice::Append)){
        QString str = (QDateTime::currentDateTime()).toString();
        out << endl << "\r\nExport " << wine->getname() << " with all crates in " << str;
        file.close();
    }
    ui->listWidget->removeItemWidget((QListWidgetItem*) wine);
    for(int i = 0 ; i < pwine.size(); i++){
        if(pwine[i] == wine){
            pwine.remove(i);
            delete wine;
        }
    }
}

void Mywine::swap(Wine *a, Wine *b){
    Wine temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Mywine::Wipe(QVector<Wine *> pwine){
    for(int i = 0; i < pwine.size(); i++){
        ui->listWidget->removeItemWidget((QListWidgetItem*) ui->listWidget->currentItem());
    }
}

void Mywine::ArrangeDateandtime(QVector<Wine *> pwine){
    for(int i = 0; i < pwine.size() - 1; i++){
        for(int j = i + 1; j < pwine.size(); j++){
            if(pwine[i]->getyear() < pwine[j]->getyear()){
                swap(pwine[i] , pwine[j]);
            }
            else if (pwine[i]->getyear() == pwine[j]->getyear()){
                if(pwine[i]->getmonth() < pwine[j]->getmonth()){
                    swap(pwine[i] , pwine[j]);
                }
                else if(pwine[i]->getmonth() == pwine[j]->getmonth()){
                    if(pwine[i]->getday() < pwine[j]->getday()){
                        swap(pwine[i] , pwine[j]);
                    }
                    else if(pwine[i]->getday() == pwine[j]->getday()){
                        if(pwine[i]->gethour() < pwine[j]->gethour()){
                            swap(pwine[i] , pwine[j]);
                        }
                        else if(pwine[i]->gethour() == pwine[j]->gethour()){
                            if(pwine[i]->getminute() < pwine[j]->getminute()){
                                swap(pwine[i] , pwine[j]);
                            }
                            else if(pwine[i]->getminute() == pwine[j]->getminute()){
                                if(pwine[i]->getsecond() < pwine[j]->getsecond()){
                                    swap(pwine[i] , pwine[j]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Wipe(pwine);
    for(int i = 0; i < pwine.size(); i++){
        ui->listWidget->addItem((QListWidgetItem*) pwine[i]);
    }
}

void Mywine::Arrangenumber(QVector<Wine *> pwine){
     for(int i = 0; i < pwine.size(); i++){
         for(int j = i; j < pwine.size(); j++){
             if(pwine[i]->getnumber() < pwine[j]->getnumber()){
                 swap(pwine[i] , pwine[j]);
             }
         }
     }
     Wipe(pwine);
     for(int i = 0; i < pwine.size(); i++){
         ui->listWidget->addItem((QListWidgetItem*) pwine[i]);
     }
}

void Mywine::Arrangeprice(QVector<Wine *> pwine){
    for(int i = 0; i < pwine.size(); i++){
        for(int j = i; j < pwine.size(); j++){
            if(pwine[i]->getprice() < pwine[j]->getprice()){
                swap(pwine[i] , pwine[j]);
            }
        }
    }
    Wipe(pwine);
    for(int i = 0; i < pwine.size(); i++){
        ui->listWidget->addItem((QListWidgetItem*) pwine[i]);
    }
}

void Mywine::Mergeprice(QVector<Wine *> pwine){
        int n = 0;
        int flag = 1;
        for(int i = 0; i < pwine.size() && flag; i++){
            for(int j = i + 1; j < pwine.size() && flag; j++){
                if((pwine[i]->getname() == pwine[j]->getname()) && (pwine[i]->getid() == pwine[j]->getid()) && (pwine[i]->getcompany() == pwine[j]->getcompany())&& (pwine[i]->getcapacity() == pwine[j]->getcapacity()) && (pwine[i]->getorigin() == pwine[j]->getorigin()) && (pwine[i]->getprice() == pwine[j]->getprice())){
                        pwine[i]->setnumber((pwine[i]->getnumber()) + (pwine[j]->getnumber()));
                        n = j;
                        flag = 0;
                }
            }
        }
        Wipe(pwine);
        for(int i = 0; i < pwine.size(); i++){
            ui->listWidget->addItem((QListWidgetItem*) pwine[i]);
        }
        if(n != 0){
            Removewine((Wine*)pwine[n]);
        }
}

void Mywine::Totalprice(QVector<Wine *> pwine){
    int total = 0;
    for(int i = 0 ; i < pwine.size(); i++){
        total += pwine[i]->getprice();
    }
    ui->total->setText(QString::number(total));
}

void Mywine::Numberofwine(QVector<Wine *> pwine){
    int numberofwine = 0;
    for(int i = 0; i < pwine.size(); i++){
        numberofwine += pwine[i]->getnumber();
    }
    ui->numberofwine->setText(QString::number(numberofwine));
}

void Mywine::splitString(QString line){
    QString buff = "";
    int j = 0;
    QString nameload;
    int idload;
    QString companyload;
    QString originload;
    QString capacityload;
    int numberload;
    int priceload;
    QString dateload;
    QString timeload;
    for(int i = j ; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            nameload = buff;
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            idload = buff.toInt();
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            companyload = buff;
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            originload = buff;
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            capacityload = buff;
            buff = "";
            j = i+1;
            break;
        }
    }

    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            numberload = buff.toInt();
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            priceload = buff.toInt();
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            dateload = buff;
            buff = "";
            j = i+1;
            break;
        }
    }
    for(int i = j; i < line.size() ; i++){
        if(line[i] != ','){
            buff += line[i];
        }
        else if(line[i] == ','){
            timeload = buff;
            break;
        }
    }
    Wine *wineload = new Wine(nameload,idload,originload,companyload,capacityload,numberload,priceload);
    wineload->setdate(dateload);
    wineload->settime(timeload);
    ui->listWidget->addItem((QListWidgetItem*) wineload);
    pwine.push_back(wineload);
}

void Mywine::readHistory(QString filename){
    int n = 0;
    QFile file2(filename);
    QTextStream readhistory(&file2);
    if(file2.open(QIODevice::ReadOnly)){
        while(!readhistory.atEnd()){
            QString line = readhistory.readLine();
            splitString(line);
            n++;
        }
        file2.close();
    }

}

void Mywine::on_pushButton_clicked()
{
     Wine *wine2 = new Wine();
     m_winedialog->Show((Wine*) wine2, 2);
        Addwine(wine2);
}

void Mywine::on_pushButton_2_clicked()
{
    Removewine((Wine*)ui->listWidget->currentItem());
}


void Mywine::on_pushButton_3_clicked()
{
    Wine *find = new Wine();
    f_winefind->Show((Wine*) find, pwine);
}


void Mywine::on_pushButton_4_clicked()
{
    ArrangeDateandtime(pwine);
}

void Mywine::on_Arrangenumber_clicked()
{
    Arrangenumber(pwine);
}

void Mywine::on_Arrangeprice_clicked()
{
    Arrangeprice(pwine);
}

void Mywine::on_pushButton_5_clicked()
{
    Mergeprice(pwine);
}

void Mywine::on_pushButton_6_clicked()
{
    Numberofwine(pwine);
    Totalprice(pwine);
}

void Mywine::on_pushButton_7_clicked()
{
    QFile file1("history.txt");
    QTextStream writehistory(&file1);
    if(file1.open(QIODevice::WriteOnly)){
        writehistory <<pwine[0]->getname()<<","<<pwine[0]->getid()<<","<<pwine[0]->getcompany()<<","<<pwine[0]->getorigin()<<","<<pwine[0]->getcapacity()<<","<<pwine[0]->getnumber()<<","<<pwine[0]->getprice()<<","<<pwine[0]->getDate().toString()<<","<<pwine[0]->getTime().toString()<<",";
        for(int i = 1; i < pwine.size() ; i++){
            writehistory <<"\r\n"<<pwine[i]->getname()<<","<<pwine[i]->getid()<<","<<pwine[i]->getcompany()<<","<<pwine[i]->getorigin()<<","<<pwine[i]->getcapacity()<<","<<pwine[i]->getnumber()<<","<<pwine[i]->getprice()<<","<<pwine[i]->getDate().toString()<<","<<pwine[i]->getTime().toString()<<",";
        }
    }
    file1.close();
}

Mywine::~Mywine(){
    delete ui;
    delete m_winedialog;
    delete f_winefind;
    for(int i = 0; i < pwine.size(); i++){
        pwine.remove(i);
    }
}

void Mywine::on_pushButton_8_clicked()
{
    readHistory("history.txt");
}
