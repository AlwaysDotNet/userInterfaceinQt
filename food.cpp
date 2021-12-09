#include "food.h"

Food::foodType Food::StrToType(const QString &s)
{
    if(s.compare("Первый",Qt::CaseInsensitive))
    {
        return foodType::One;
    }
    else if(s.compare("Второй",Qt::CaseInsensitive))
    {
        return foodType::One;
    }
    else
        return foodType::Desert;
}

Food::Food(const QString &name,const int durmn,const QString&typ)
{
  //У нас должно хранится 3 файлы файл рисунка файл продукты файл рецепта
//Все они должны начинатся с Name+"xx".txt
 //Каталог images хранить рисунки католог ings продукты и каталог recepts рецепты
 this->filePath=QDir::currentPath()+"\\images\\"+name;//Рисунок
 this->name=name;
 this->durMinut=durmn;
 this->type=this->StrToType(typ);

QFile flRec(QDir::currentPath()+"\\recepts\\"+name+".txt");//Откроем файл
QFile flIng(QDir::currentPath()+"\\ings\\"+name+".txt");
try {
    if(!flRec.exists())
        throw("Ошибка при открытия файла");
}  catch (const QString s)

{
   qCritical()<<s;
   qDebug()<<"Error file";
}

flRec.open(QIODevice::ReadOnly|QIODevice::Text);
flIng.open(QIODevice::ReadOnly|QIODevice::Text);
QTextStream s1(&flRec);
QTextStream s2(&flIng);
while(!s2.atEnd())
{
    this->ingrident.push_back(s2.readLine());//На каждом строке по одному ингридиент
}
this->recept=s1.readAll();
this->recept=this->recept.remove('\n');
flRec.close();
flIng.close();
}

QString Food::typeToStr() const
{
    switch(this->type)
    {
    case Food::foodType::One:
        return "Первый";
    case Food::foodType::Two:
            return "Второй";
    case Food::foodType::Desert:
        return "Десерть";
    }
    return "Непонятно";
}

QString Food::getName() const
{
    return this->name;
}
QString Food::getDurMin() const
{
    return QString::number(this->durMinut);
}
QVector<QString> Food::getIngridents() const
{
    return this->ingrident;
}
QString Food::getImgPath() const
{
    return filePath;
}
QString Food::getRecept() const
{
    return this->recept;
}

Food::foodType Food::getType() const
{
    return this->type;
}
Food::~Food()
{

}
