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
    bool SignInOp(const QString& name, const QString& passward);
    bool SignUpOp(const QString& name, const QString& passward);
    bool SqlLookup(const QString& str);

private:
    QSqlQuery* query;
};

#endif // MYSQL_H
