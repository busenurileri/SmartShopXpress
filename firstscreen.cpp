#include "firstscreen.h"
#include "ui_firstscreen.h"
#include "user.h"

//User2 FirstScreen::user= User2();
User* FirstScreen::user = nullptr;  // Initialize the static pointer
std::vector<User*> FirstScreen::usersVector;

FirstScreen::FirstScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstScreen)
{
    ui->setupUi(this);
    setFixedSize(400,604);

    //campaign images have been created and their height and width were set to fixed values
    QLabel *label1 = new QLabel;
    QPixmap pixmap1(":/img/img0/campaign.png");
    label1->setPixmap(pixmap1.scaledToHeight(190, Qt::SmoothTransformation));
    label1->setPixmap(pixmap1.scaledToWidth(350, Qt::SmoothTransformation));

    QLabel *label2 = new QLabel;
    QPixmap pixmap2(":/img/img0/campaign2.png");
    label2->setPixmap(pixmap2.scaledToHeight(190, Qt::SmoothTransformation));
    label2->setPixmap(pixmap2.scaledToWidth(350, Qt::SmoothTransformation));

    QLabel *label3 = new QLabel;
    QPixmap pixmap3(":/img/img0/campaign3.png");
    label3->setPixmap(pixmap3.scaledToHeight(190, Qt::SmoothTransformation));
    label3->setPixmap(pixmap3.scaledToWidth(350, Qt::SmoothTransformation));

    //labels are added to stackedWidget
    ui->stackedWidget->addWidget(label1);
    ui->stackedWidget->addWidget(label2);
    ui->stackedWidget->addWidget(label3);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FirstScreen::changeImage); //when the timer times out, the changeImage function is called
    timer->start(2000);


}


FirstScreen::~FirstScreen()
{
 //   delete user;  // Delete the dynamically allocated User instance
    if (user != nullptr)
    {
        delete user;  // Delete the dynamically allocated User instance
        user = nullptr;  // Set the pointer to nullptr after deletion
    }
    delete ui;
}

// provides the changing of campaign images on the screen
void FirstScreen::changeImage()
{
    int currentIndex = ui->stackedWidget->currentIndex(); //current index of the currently visible item is obtained
    int nextIndex = (currentIndex + 1) % ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(nextIndex); //the currently visible item in the widget is replaced with the next item
}

void FirstScreen::on_cartButton_clicked()
{
    if(user!=nullptr){
        this->hide();
        CartScreen cart;
        cart.setModal(true);
        cart.exec();
    }
    else{
        QMessageBox::warning(this,tr("Warning!"),tr("Please log in to the account!"));
    }

}


void FirstScreen::on_addressButton_clicked()
{
    if(user!=nullptr){
        this->hide();
        Addresscreen address;
        address.setModal(true);
        address.exec();
    }
    else{
        QMessageBox::warning(this,tr("Warning!"),tr("Please log in to the account!"));
    }

}


void FirstScreen::on_budgetButton_clicked()
{
    if(user!=nullptr){
        this->hide();
        Wallet wallet;
        wallet.showCurrentBalance();
        wallet.setModal(true);
        wallet.exec();
    }
    else{
        QMessageBox::warning(this,tr("Warning!"),tr("Please log in to the account!"));
    }
}


void FirstScreen::on_favoriteButton_clicked()
{
    if(user!=nullptr){
        this->hide();
        Favorite favorite;
        favorite.showFavorites();
        favorite.setModal(true);
        favorite.exec();
    }
    else{
        QMessageBox::warning(this,tr("Warning!"),tr("Please log in to the account!"));
    }
}


void FirstScreen::on_accountButton_clicked()
{
    this->hide();
    if(user == nullptr){
        LoginScreen login;
        login.setModal(true);
        login.exec();
    }
    else{
        User u;
        u.showInfo(user);
        u.setModal(true);
        u.exec();
    }

}


void FirstScreen::on_category1PushButton_clicked()
{
    BuySomethingScreen buySomething;
    this->hide();
    buySomething.setModal(true);
    buySomething.setFruitsProduct();
    buySomething.exec();

}


void FirstScreen::on_category2PushButton_clicked()
{
    BuySomethingScreen buySomething;
    this->hide();
    buySomething.setModal(true);
    buySomething.setVegetablesProduct();
    buySomething.exec();

}

