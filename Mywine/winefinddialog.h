#ifndef WINEFINDDIALOG_H
#define WINEFINDDIALOG_H

#include <QDialog>
#include <wine.h>
#include <mywine.h>
#include <winedialog.h>
#include <QVector>



namespace Ui {
class WinefindDialog;
}

class WineDialog;
class WinefindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinefindDialog(QWidget *parent = 0);
    void Show(Wine* wine , QVector<Wine*> pwine );
    ~WinefindDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WinefindDialog *ui;
    QVector<Wine*> fwine;
    Wine *winefind;
    WineDialog *t_winedialog;

};

#endif // WINEFINDDIALOG_H
