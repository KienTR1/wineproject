#include"wine.h"
#include "QDateTime"

Wine::Wine(){
    setname("");
    setid(0);
    setorigin("");
    setcompany("");
    setcapacity("");
    setnumber(0);
    setprice(0);
}

Wine::Wine(QString s,int id, QString nguongoc, QString hang, QString dungtich, int soluong, int gia){
    setname(s);
    setid(id);
    setorigin(nguongoc);
    setcompany(hang);
    setcapacity(dungtich);
    setnumber(soluong);
    setprice(gia);


}
Wine::Wine(QString s){
    setname(s);
}

QString Wine::getname() const
{
    return QListWidgetItem::text();
}

int Wine::getid() const
{
    return ID;
}

QString Wine::getorigin() const
{
    return Nguongoc;
}

QString Wine::getcompany() const
{
    return Hang;
}

QString Wine::getcapacity() const
{
    return Dungtich;
}

int Wine::getnumber() const
{
    return Soluong;
}

int Wine::getprice() const
{
    return Gia;
}

int Wine::getyear() const
{
    return date.year();
}

int Wine::getmonth() const
{
    return date.month();
}
int Wine::getday() const
{
    return date.day();
}
int Wine::gethour() const
{
    return time.hour();
}

int Wine::getminute() const
{
    return time.minute();
}

int Wine::getsecond() const
{
    return time.second();
}

QDate Wine::getDate() const
{
    return date;
}

QTime Wine::getTime() const
{
    return time;
}

void Wine::setname(QString s){
    QListWidgetItem::setText(s);
}

void Wine::setid(int id){
    ID = id;
}

void Wine::setcompany(QString hang){
    Hang = hang;
}

void Wine::setorigin(QString nguongoc)
{
    Nguongoc = nguongoc;
}

void Wine::setnumber(int soluong){
    Soluong = soluong;
}

void Wine::setcapacity(QString dungtich){
    Dungtich = dungtich;
}

void Wine::setprice(int gia){
    Gia = gia;
}

void Wine::setdate(QString Dt){
    date = QDate::fromString(Dt);
}

void Wine::settime(QString Tt){
    time = QTime::fromString(Tt);
}

void Wine::setdateandtime(QDateTime DT){
    date = DT.date();
    time = DT.time();
}


