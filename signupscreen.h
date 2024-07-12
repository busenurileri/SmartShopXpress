#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include "firstscreen.h"
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class SignUpScreen;
}

class SignUpScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpScreen(QWidget *parent = nullptr);
    ~SignUpScreen();

private slots:
    void on_savePushButton_clicked();

    void on_phoneNoLineEdit_textEdited(const QString &arg1);

    void on_mainMenuButton_clicked();

    void on_mailLineEdit_textEdited(const QString &arg1);

private:
    Ui::SignUpScreen *ui;
    static int idCounter;
};

#endif // SIGNUPSCREEN_H
