#ifndef ADDRESSCREEN_H
#define ADDRESSCREEN_H

#include <QDialog>

#include "address.h"
#include "firstscreen.h"

namespace Ui {
class Addresscreen;
}

class Addresscreen : public QDialog
{
    Q_OBJECT

public:
    explicit Addresscreen(QWidget *parent = nullptr);
    ~Addresscreen();

private slots:
    void on_mainMenuButton_clicked();

    void on_enterAddressNameLineEdit_editingFinished();

    void on_enterAddressCityLineEdit_editingFinished();

    void on_enterAddressStreetLineEdit_editingFinished();

    void on_enterAddressBuildingLineEdit_editingFinished();

    void on_enterAddressDoorNumLineEdit_editingFinished();

    void on_addAddressPushButton_clicked();

private:
    Ui::Addresscreen *ui;
    Address address;// o an girilen adresi tutmak için
};

#endif // ADDRESSCREEN_H
