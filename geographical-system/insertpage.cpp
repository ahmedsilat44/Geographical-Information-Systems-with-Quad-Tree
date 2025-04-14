#include "insertpage.h"
#include "ui_insertpage.h"
# include "mainwindow.h"

insertPage::insertPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::insertPage)
    ,mainwindow(nullptr)
    ,quadtree(qt)
{
    ui->setupUi(this);
}

insertPage::~insertPage()
{
    delete ui;
}

void insertPage::on_backButton_clicked()
{
    if (!mainwindow)
        mainwindow = new Widget();
    mainwindow->show();
    this->hide();
}

void insertPage::on_enterButton_clicked()
{
    Qstring x_coordinate = ui->lineEdit->text();
    Qstring y_coordinate = ui->lineEdit2->text();

    //convert to double and check if the enter values are not empty
    if (x_coordinate.isEmpty() || y_coordinate.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter valid coordinates.");
        return;
    }
    bool x_ok, y_ok;
    double x = x_coordinate.toDouble(&x_ok);
    double y = y_coordinate.toDouble(&y_ok);
    if (!x_ok || !y_ok) {
        QMessageBox::warning(this, "Input Error", "Please enter valid coordinates.");
        return;
    }
    //call quadtree insert and in it directly pass point
    quadtree->insert_point(Point(x, y));
    
}
