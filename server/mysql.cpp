#include "mysql.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

MySql::MySql()
{
}

void MySql::InitSql()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("0.0.0.0");
    db.setUserName("robotmaster");
    db.setPassword("123");
    db.setDatabaseName("/var/lib/mysql");
    if(!db.open())
    {
        qDebug()<<"Database connected failed!";
        QMessageBox::critical(0,QObject::tr("not open sql"), "error:", QMessageBox::Cancel);
        return;
    }

    CreateTable();
}

void MySql::CreateTable()
{
    query = new QSqlQuery();
    query->exec("SET NAMES 'Latin1'");
    query->exec("create table users(name varchar(30),passwd varchar(20))");

}

bool MySql::SignInOp(QString name, QString passward)
{
    QString str = QString("select * from users where name='%1' and passwd='%2'").arg(name).arg(passward);
    return SqlLookup(str);
}

bool MySql::SignUpOp(QString name, QString passward)
{
    QString str = QString("select * from users where name='%1'").arg(name);

    if (SqlLookup(str))
        return false;

    str = QString("insert into users value('%1','%2')").arg(name).arg(passward);
    return query->exec(str);

}

bool MySql::SqlLookup(QString str)
{
    query = new QSqlQuery();
    query->exec(str);
    query->last();

    return (query->at()+1);
}
