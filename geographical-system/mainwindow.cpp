#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Quadtree.h"
#include <iostream>
#include "QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

    ,quadtree(nullptr)

{
    ui->setupUi(this);
    Box boundary(Point(10, 10), 20, 20);

    quadtree = new Quadtree(boundary, 4); // Initialize the quadtree with a bounding box
    connect(this, &Widget::pointInserted, this, &Widget::populateTableWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_insertButton_clicked()
{
    // change index of stackwidget to 2
    ui->stackedWidget->setCurrentIndex(2);
}


void Widget::on_tableButton_clicked()
{
    // change index of stackwidget to 1
    ui->stackedWidget->setCurrentIndex(1);
    emit pointInserted();

}




void Widget::on_backButton_2_clicked()
{
    // change index of stackwidget to 0
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_backButton_clicked()
{
    // change index of stackwidget to 0
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_pushButton_clicked()
{
    QString x_coordinate = ui->lineEdit->text(); //get x coordinate from line edit
    QString y_coordinate = ui->lineEdit_2->text(); //get y coordinate from line edit

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

    emit pointInserted();  // Emit the signal



    //clear the line edits
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    //show message box to show that the point is inserted
    QMessageBox::information(this, "Point Inserted", "Point (" + x_coordinate + ", " + y_coordinate + ") inserted successfully.");
}


void Widget::populateTableWidget(){
// Clear the table widget before populating it
// ui->tableWidget->clear();
ui->tableWidget->setRowCount(0); // Clear existing rows

// Set the column count and headers
ui->tableWidget->setColumnCount(2);
QStringList headers;
headers << "X Coordinate" << "Y Coordinate";
ui->tableWidget->setHorizontalHeaderLabels(headers);

std::vector<Point> points = quadtree->points; // Get the points from the quadtree

// Resize the table widget to fit the number of points
ui->tableWidget->setRowCount(points.size());

// Populate the table widget with the points
for (int i = 0; i < points.size(); ++i) {
    QTableWidgetItem* xItem = new QTableWidgetItem(QString::number(points[i].get_x()));
    QTableWidgetItem* yItem = new QTableWidgetItem(QString::number(points[i].get_y()));
    ui->tableWidget->setItem(i, 0, xItem);
    ui->tableWidget->setItem(i, 1, yItem);
}
}


void Widget::on_searchButton_clicked()
{
    // fetch the selected row from the table widget
    int selectedRow = ui->tableWidget->currentRow();
    // its value in x and y coordinates
    double x = ui->tableWidget->item(selectedRow, 0)->text().toDouble();
    double y = ui->tableWidget->item(selectedRow, 1)->text().toDouble();


    Point p1(x,y); //now it is

    //take input from lineEdit3 and convert to int

    QString width = ui->lineEdit_3->text(); //get width from line edit
    QString height = ui->lineEdit_3->text(); //get height from line edit
    //convert widht and height to int
    bool width_ok, height_ok;
    int w = width.toInt(&width_ok);
    int h = height.toInt(&height_ok);

    Box search_area(p1, w, h); // Define a search area (center at (10,10), width and height of 5)
    std::vector<Point> found_points = quadtree->square_query(search_area);
    for(int i=0;i<found_points.size();i++)
    {
        std::cout<<found_points[i].get_x()<<" "<<found_points[i].get_y()<<std::endl;
    }
}


void Widget::on_pushButton_2_clicked()
{
    Point p1(15.98, 8.21);
    quadtree->insert_point(p1);
    Point p2(412, 12.18);
    quadtree->insert_point(p2);
    Point p3(2.02, 5.36);
    quadtree->insert_point(p3);
    Point p4(14.6, 7.16);
    quadtree->insert_point(p4);
    Point p5(7.34, 2.47);
    quadtree->insert_point(p5);
    Point p6(12.25, 9.88);
    quadtree->insert_point(p6);
    Point p7(18.03, 19.27);
    quadtree->insert_point(p7);
    Point p8(5, 6.87);
    quadtree->insert_point(p8);
    Point p9(7.48, 11.42);
    quadtree->insert_point(p9);
    Point p10(17.51, 0.55);
    quadtree->insert_point(p10);

    Point p11(1, 1);
    quadtree->insert_point(p11);
    // quadtree->print_Quadtree();
    Point p12(5, 5);
    quadtree->insert_point(p12);
    // std::cout<< "\nHEHEHEHE\n";
    // quadtree->print_Quadtree();
    Point p13(8, 8);
    quadtree->insert_point(p13);
    Point p14(20, 7);
    quadtree->insert_point(p14);
    std::cout<<"points isnerted"<<std::endl;
}


void Widget::on_searchButton_2_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    // its value in x and y coordinates
    double x = ui->tableWidget->item(selectedRow, 0)->text().toDouble();
    double y = ui->tableWidget->item(selectedRow, 1)->text().toDouble();


    Point p1(x,y); //now it is

    //take input from lineEdit3 and convert to int

    QString width = ui->lineEdit_3->text(); //get width from line edit
    QString height = ui->lineEdit_3->text(); //get height from line edit
    //convert widht and height to int
    bool width_ok, height_ok;
    int w = width.toInt(&width_ok);
    int h = height.toInt(&height_ok);

    Box search_area(p1, w, h); // Define a search area (center at (10,10), width and height of 5)
    std::vector<Point> circle_found_points = quadtree->circle_query(search_area,p1);
    for(int i=0;i<circle_found_points.size();i++)
    {
        std::cout<<circle_found_points[i].get_x()<<" "<<circle_found_points[i].get_y()<<std::endl;
    }
}

