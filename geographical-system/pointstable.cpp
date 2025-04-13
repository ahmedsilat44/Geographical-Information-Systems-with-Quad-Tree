#include "pointstable.h"
#include "ui_pointstable.h"
# include "mainwindow.h"

pointsTable::pointsTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pointsTable)
    ,mainwindow(nullptr)
{
    ui->setupUi(this);
}

pointsTable::~pointsTable()
{
    delete ui;
}

void pointsTable::on_backButton_clicked()
{
    if (!mainwindow)
        mainwindow = new Widget();
    mainwindow->show();
    this->hide();
}


