#include "category.h"

Category::Category(QString name,int id)
{
    this-> name=name;
    this->id=id;

}

QString Category::getName() const
{
    return name;
}

void Category::setName(const QString &newName)
{
    name = newName;
}

int Category::getId() const
{
    return id;
}

void Category::setId(int newId)
{
    id = newId;
}
