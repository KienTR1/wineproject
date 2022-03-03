#ifndef WINE
#define WINE

#include"QString"
#include "QListWidgetItem"
#include "QDateTime"
class Wine : public QListWidgetItem
{
private:
    int ID;
    QString Nguongoc;
    QString Hang;
    QString Dungtich;
    int Soluong;
    int Gia;
    QDate date;
    QTime time;

public:
    Wine();
    Wine(QString s);
    Wine(QString s, int id, QString nguongoc, QString hang, QString dungtich, int soluong, int gia);

    void setname(QString s);
    void setid(int id);
    void setorigin(QString nguongoc);
    void setcompany(QString hang);
    void setcapacity(QString dungtich);
    void setnumber(int soluong);
    void setprice(int gia);
    void setdateandtime(QDateTime DT);
    void setdate(QString Dt);
    void settime(QString Tt);

    QString getname() const;
    int getid() const;
    QString getorigin() const;
    QString getcompany() const;
    QString getcapacity() const;
    int getnumber() const;
    int getprice() const;

    int getyear() const;
    int getmonth() const;
    int getday() const;
    int gethour() const;
    int getminute() const;
    int getsecond() const;
    QDate getDate() const;
    QTime getTime() const;


    ~Wine(){}
};

#endif // WINE

