#ifndef FAVORITE_H
#define FAVORITE_H

#include <QDialog>
#include "firstscreen.h"
#include <QDebug>
#include "user.h"
#include <QListWidgetItem>
class User;

namespace Ui {
class Favorite;
}

class Favorite : public QDialog
{
    Q_OBJECT

public:
    explicit Favorite(QWidget *parent = nullptr);
    ~Favorite();
    void showFavorites();

private slots:
    void on_mainMenuButton_clicked();

    void on_deleteFavButton_clicked();

    void on_favListWidget_itemClicked(QListWidgetItem *item);

    void on_addCartButton_clicked();

private:
    Ui::Favorite *ui;
    QString selectedItemForFavorite;

};

#endif // FAVORITE_H
