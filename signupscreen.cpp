#include "signupscreen.h"
#include "ui_signupscreen.h"

int SignUpScreen::idCounter=0;
SignUpScreen::SignUpScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpScreen)
{
    ui->setupUi(this);
    setFixedSize(400,604);
    ui->ageSpinBox->setSpecialValueText("--");
    ui->ageSpinBox->setRange(17, 150); //age range
    ui->phoneNoLineEdit->setMaxLength(10);//phone number length
}

SignUpScreen::~SignUpScreen()
{
    delete ui;
}

void SignUpScreen::on_savePushButton_clicked()
{
    QString enteredName= ui->nameLineEdit->text().simplified(); //remove leading and trailing whitespaces
    QString enteredSurname= ui->surnameLineEdit->text().simplified();
    QString enteredEmail = ui->mailLineEdit->text().trimmed(); // Remove leading and trailing whitespaces
    QString phoneNum=ui->phoneNoLineEdit->text();
    QString password=ui->passwordLineEdit->text();
    //define a regular expression pattern for allowed domains
    QRegularExpression allowedDomainsPattern("\\b\\S+@\\S+\\.com\\b"); //represents the expression in the style of smth@smth.com
    bool mailControl=true;


    for(int i=0;i<FirstScreen::usersVector.size();i++){
        if(FirstScreen::usersVector[i]->getEmail()==enteredEmail){
            //QMessageBox::warning(this,tr("Warning!"),tr("This mail belongs to an existing account!"));
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Warning!"));
            msgBox.setText(tr("This mail belongs to an existing account!"));
            msgBox.setStyleSheet("QMessageBox { background-color: #e0e0e0; }"); // Arkaplan rengini gri olarak ayarlar
            msgBox.exec();
            mailControl=false;
        }
    }

    // Check if the entered email matches the pattern and another controls
    if (mailControl && allowedDomainsPattern.match(enteredEmail).hasMatch() && ui->phoneNoLineEdit->maxLength()==phoneNum.size()) {
        if(!enteredName.isEmpty() && !enteredSurname.isEmpty() && ui->ageSpinBox->text()!="--" && ui->genderComboBox->currentText()!="--" && !ui->passwordLineEdit->text().isEmpty()){
            qDebug()<<"user olusturulacak";
            FirstScreen::user=new User(this);
            qDebug()<<"user olusutruldu";
            FirstScreen::user->setName(enteredName);
            FirstScreen::user->setSurname(enteredSurname);
            FirstScreen::user->setEmail(enteredEmail);
            FirstScreen::user->setPhoneNumber(phoneNum);
            FirstScreen::user->setPassword(password);
            FirstScreen::user->setGender(ui->genderComboBox->currentText()=="Female"?Female:Male);
            FirstScreen::user->setAge(ui->ageSpinBox->value());
            FirstScreen::user->setId(idCounter++);
            FirstScreen::usersVector.push_back(FirstScreen::user);
            if(FirstScreen::user->getWallet()==nullptr){
                qDebug()<<"wallet null";
            }
            this->hide();
            FirstScreen fScreen;
            fScreen.setModal(true);
            fScreen.exec();
        }
    }
}


void SignUpScreen::on_phoneNoLineEdit_textEdited(const QString &arg1)
{
    QString filteredText;
    for (const QChar& ch : arg1){
        if (ch.isDigit()){ //allows only digits to be entered
            filteredText += ch;
        }
    }
    ui->phoneNoLineEdit->setText(filteredText);
}


void SignUpScreen::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen fScreen;
    fScreen.setModal(true);
    fScreen.exec();
}


void SignUpScreen::on_mailLineEdit_textEdited(const QString &arg1)
{
    QString filteredText = arg1.simplified();
    filteredText.replace(" ", "");
    ui->mailLineEdit->setText(filteredText);
}

