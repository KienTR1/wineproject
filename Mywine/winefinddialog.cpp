#include "winefinddialog.h"
#include "ui_winefinddialog.h"
#include "wine.h"
#include <winedialog.h>
#include <QMessageBox>
#include <QString>


WinefindDialog::WinefindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinefindDialog)
{
    ui->setupUi(this);
    t_winedialog = new WineDialog;
}



void WinefindDialog::Show(Wine* wine , QVector<Wine*> pwine){
    ui->namefind->setText(wine->getname());
    ui->idfind->setText(QString::number(wine->getid()));
    winefind = wine;
    for(int i = 0 ; i < pwine.size() ; i++){
        fwine.push_back(pwine[i]);
    }
    show();
}

void WinefindDialog::on_pushButton_clicked()
{
    winefind->setname(ui->namefind->text());
    winefind->setid((ui->idfind->text()).toInt());
    int count = 0;
    for(int i = 0; i < fwine.size(); i++){
        if((fwine[i]->getname() == winefind->getname()) || (fwine[i]->getid() == winefind->getid())){
            t_winedialog->Show((Wine*)fwine[i] , 1);
            count ++;
        }
    }
    if(count == 0){
        QMessageBox Box(QMessageBox::Critical, "Error" , "not found");
        Box.exec();
    }
}

void WinefindDialog::on_pushButton_2_clicked()
{
    hide();
}

WinefindDialog::~WinefindDialog()
{
    delete ui;
    delete winefind;
    delete t_winedialog;
    for(int i = 0 ; i < fwine.size(); i++){
        fwine.remove(i);
    }
}
