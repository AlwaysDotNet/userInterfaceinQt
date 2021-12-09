#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QTextStream>
class QString;
class Food
{
private:
    QString name;//Название блюди
    QVector<QString>ingrident;//Продукты
    QString filePath;//Рисунок
    int durMinut;//В сколько время приготовится
    QString recept;

public:
    enum foodType{One,Two,Desert};//Типы первый второй и конечно десерт
private:
    foodType type;//Тип блюдо
    //Реализуем функцию который возмет строку тип блюдо и возврашет тип enum
    foodType StrToType(const QString&);
public:
    Food(const QString&,const int durmn,const QString&);//В конструктор передается только одно строка  Name
    ~Food();//Деструктор
    QString typeToStr()const;//Из тип enum в строку
    QString getName()const;
    QVector<QString>getIngridents()const;
    QString getImgPath()const;
    QString getDurMin()const;
    QString getRecept()const;
    foodType getType()const;

};

#endif // FOOD_H
