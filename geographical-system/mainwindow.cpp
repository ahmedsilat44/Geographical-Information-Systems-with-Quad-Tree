#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertpage.h"
# include "pointstable.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , insertpage(nullptr)
    , pointstable(nullptr)
{
    ui->setupUi(this);
    boundary = new Box (Point(10, 10), 20, 20);
    
    quadtree = new QuadTree(boundary, 4); // Initialize the quadtree with a bounding box
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_insertButton_clicked()
{
    if (!insertpage)
        insertpage = new insertPage(this, quadtree); // Pass the quadtree pointer to insertPage
    insertpage->show();
    this->hide();
}


void Widget::on_tableButton_clicked()
{
    if (!pointstable)
        pointstable = new pointsTable();
    pointstable->show();
    this->hide();
}



