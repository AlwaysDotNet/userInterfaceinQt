#ifndef USER_H
#define USER_H

#include <QObject>

class User
{
  private:
    QString login;
    QString pass;
    QString name;
    QString sname;
    QString imgFile;
public:
    User();
    User(const User&);
    User(QStringList &ls);
    User &operator=(const User &);
    ~User();
    User(const QString &,const QString &p,const QString &name,const QString &sname,const QString &file);
    QString getLog()const;
    QString getPass()const;
    QString getName()const;
    QString getSName()const;
    QString getFile()const;
};

#endif // USER_H
