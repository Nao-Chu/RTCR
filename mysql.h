#ifndef MYSQL_H
#define MYSQL_H

#include <QString>
#include <QSqlQuery>

class MySql
{
public:
    MySql();
    void InitSql();
    void CreateTable();
    bool SignInOp(QString name, QString passward);
    bool SignUpOp(QString name, QString passward);
    bool SqlLookup(QString str);

private:
    QSqlQuery* query;
};

#endif // MYSQL_H
