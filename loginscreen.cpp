#include "loginscreen.h"
#include "ui_loginscreen.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    setFixedSize(400,604);
    ui->mailLineEdit->setStyleSheet("color: #20571e; font-size: 11px;");
    ui->passwordLineEdit->setStyleSheet("color: #20571e; font-size: 11px;");

}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();
}


void LoginScreen::on_redirectSignupPushButton_clicked()
{
    this->hide();
    SignUpScreen signup;
    signup.setModal(true);
    signup.exec();
}


void LoginScreen::on_loginButton_clicked()
{
    QString enteredMail = ui->mailLineEdit->text();
    QString enteredPassword = ui->passwordLineEdit->text();
    for(int i=0;i<FirstScreen::usersVector.size();i++){
        if(FirstScreen::usersVector[i]->getEmail()==enteredMail && FirstScreen::usersVector[i]->getPassword()==enteredPassword){
            FirstScreen::user=FirstScreen::usersVector[i];
            this->hide();
            FirstScreen fScreen;
            fScreen.setModal(true);
            fScreen.exec();
        }
    }
}

