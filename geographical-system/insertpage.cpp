#include "insertpage.h"
#include "ui_insertpage.h"
# include "mainwindow.h"

insertPage::insertPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::insertPage)
    ,mainwindow(nullptr)
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

