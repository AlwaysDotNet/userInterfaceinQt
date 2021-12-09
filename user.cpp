#include "user.h"

User::User()
{

}

 User::User(const User &a)
{
    this->name=a.getName();
    this->sname=a.getSName();
    this->login=a.getLog();
    this->pass=a.getPass();
    this->imgFile=a.getFile();
}

 User::User(QStringList &ls)
{
 this->name=ls.first();
 ls.pop_front();
 sname=ls.first();
 ls.pop_front();
 this->imgFile=ls.first();
 ls.pop_front();
 this->login=ls.first();
 ls.pop_front();
 this->pass=ls.first();
}

User &User::operator=(const User &a)
{
    this->name=a.getName();
    this->sname=a.getSName();
    this->login=a.getLog();
    this->pass=a.getPass();
    this->imgFile=a.getFile();
    return (*this);
}

User::User(const QString &l, const QString &p,const QString &nm,const QString &sname,const QString& file)
{
    this->login=l;
    this->pass=p;
    this->name=nm;
    this->sname=sname;
    this->imgFile=file;
}
QString User::getFile()const
{
    return this->imgFile;
}
QString User::getLog()const
{
    return  this->login;
}
QString User::getName() const
{
    return this->name;
}
QString User::getSName() const
{
    return this->name;
}
QString User::getPass() const
{
    return this->pass;
}
User::~User()
{

}
