#ifndef MYWINE_H
#define MYWINE_H

#include <QWidget>
#include "QString"
#include "wine.h"
#include "winedialog.h"
#include <QVector>
#include "winefinddialog.h"


namespace Ui {
class Mywine;
}
class QListWidgetItem;
class WineDialog;
class WinefindDialog;

class Mywine : public QWidget
{
    Q_OBJECT

public:
    explicit Mywine(QWidget *parent = 0);
    void Addwine(Wine *wine);
    void Addwine(QString s);
    void Addwine(QString s, int id, QString nguongoc, QString hang, QString dungtich, int soluong,int gia);
    void Removewine(Wine *wine);

    void swap(Wine *a, Wine *b);
    void ArrangeDateandtime(QVector<Wine*> pwine);
    void Arrangenumber(QVector<Wine*> pwine);
    void Arrangeprice(QVector<Wine*> pwine);

    void Wipe(QVector<Wine *> pwine);
    void Mergeprice(QVector<Wine*> pwine);

    void Totalprice(QVector<Wine *> pwine);
    void Numberofwine(QVector<Wine *> pwine);

    void readHistory(QString filename);
    void splitString(QString line);

    ~Mywine();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Arrangenumber_clicked();

    void on_Arrangeprice_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Mywine *ui;
    WineDialog *m_winedialog;
    WinefindDialog *f_winefind;
    QVector<Wine*> pwine;
};

#endif // MYWINE_H
