#ifndef WINEDIALOG_H
#define WINEDIALOG_H

#include <QDialog>
#include <wine.h>
#include <QVector>

namespace Ui {
class WineDialog;
}
class Wine;
class WineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WineDialog(QWidget *parent = 0);
    void Show(Wine *wine, int signal);
    ~WineDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WineDialog *ui;
    Wine* wine1;
    int signal1;
};

#endif // WINEDIALOG_H
