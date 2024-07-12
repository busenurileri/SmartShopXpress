#ifndef CATEGORY_H
#define CATEGORY_H
#include "QString"


class Category
{
public:
    Category(QString,int);

    QString getName() const;
    void setName(const QString &newName);

    int getId() const;
    void setId(int newId);

private:
    QString name;
    int id;


};

#endif // CATEGORY_H
