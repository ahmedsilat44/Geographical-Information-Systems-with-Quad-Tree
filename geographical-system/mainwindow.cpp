#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Quadtree.h"
#include <iostream>
#include "QMessageBox"




#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)

    ,quadtree(nullptr)

{
    ui->setupUi(this);
    Box boundary(Point(10, 10), 20, 20);

    quadtree = new Quadtree(boundary, 4);
    
    


    
    // Initialize the quadtree with a bounding box
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
    Q_EMIT pointInserted();

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
    std::cout << " INSERTED IN WIDGET" <<std::endl;
    Q_EMIT pointInserted();  // Emit the signal
    // populateTableWidget();


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

    if(selectedRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a point from the table.");
        return;
    }

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
    plt::figure_size(800, 600);
    plt::axis("scaled");
    plt::xlim(0, 20);
    plt::ylim(0, 20);
    plt::title("Quadtree Points Search");
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    std::vector<Point> points = quadtree->get_points();
    std::vector<double> x_vals, y_vals;

    // Plot the points
    for (auto& point : points) {
        x_vals.push_back(point.get_x());
        y_vals.push_back(point.get_y());
    }
    plt::scatter(x_vals, y_vals, 20.0, {{"color", "k"}});

    // Draw the search area as a rectangle
    double left_x = x - w;
    double right_x = x + w;
    double top_y = y - h;
    double bottom_y = y + h;
    // Draw the rectangle
    plt::plot({left_x,right_x, right_x, left_x, left_x},
              {top_y, top_y, bottom_y, bottom_y, top_y},
              {{"color", "r"}, {"linewidth", "2"}}); // Rectangle in red
    

    std::vector<Point> found_points = quadtree->square_query(search_area);
   

    std::vector<double> x_search, y_search;
    // keep track of nearest neighbor
    Point nearest_neighbor = found_points[0];
    double min_distance = 200; // Initialize with a large value

    for (int i = 0; i < found_points.size(); i++) {
        double distance = found_points[i].distance_from_center(p1);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_neighbor = found_points[i];
        }
        x_search.push_back(found_points[i].get_x());
        y_search.push_back(found_points[i].get_y());
    }
    
    plt::scatter(x_search, y_search, 20.0, {{"edgecolor", "r"}}); // Plot all points in black


    std::string subtitle = "Nearest Neighbor: (" + std::to_string(nearest_neighbor.get_x()) + ", " + std::to_string(nearest_neighbor.get_y()) + ")";
    
    QMessageBox::information(this, "Search Result", "Search area: (" + QString::number(left_x) + ", " + QString::number(top_y) + ") to (" + QString::number(right_x) + ", " + QString::number(bottom_y) + ")\nNearest Neighbor: (" + QString::number(nearest_neighbor.get_x()) + ", " + QString::number(nearest_neighbor.get_y()) + ")");
    
    plt::show(); // Show the plot

    

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
    Point p12(5, 5);
    quadtree->insert_point(p12);
    Point p13(8, 8);
    quadtree->insert_point(p13);
    Point p14(20, 7);
    quadtree->insert_point(p14);
    Point p15(17.17, 14.14);
        Point p16(1.11, 19.19);
        Point p17(18.81, 9.09);
        Point p18(14.14, 3.33);
        Point p19(3.33, 15.15);
        Point p20(6.06, 7.07);
        Point p21(9.99, 16.16);
        Point p22(11.22, 2.22);
        Point p23(7.89, 11.11);
        Point p24(19.5, 5.55);
        Point p25(2.22, 18.18);
        Point p26(2.5, 17.5);
        Point p27(3.5, 17.5);
        Point p28(3.5, 15.5);
        quadtree->insert_point(p15);
        quadtree->insert_point(p16);
        quadtree->insert_point(p17);
        quadtree->insert_point(p18);
        quadtree->insert_point(p19);
        quadtree->insert_point(p20);
        quadtree->insert_point(p21);
        quadtree->insert_point(p22);
        quadtree->insert_point(p23);
        quadtree->insert_point(p24);
        quadtree->insert_point(p25);
        quadtree->insert_point(p26);
        quadtree->insert_point(p27);
        quadtree->insert_point(p28);
    std::cout<<"points isnerted"<<std::endl;
    QMessageBox::information(this, "Points Inserted", "Pre defined points inserted successfully");
}


void Widget::on_searchButton_2_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if(selectedRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a point from the table.");
        return;
    }
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

    std::vector<double> x_vals, y_vals;
    

    // Prepare data for a circle.
    int n = 5000; // number of data points
    // double r = 10.0; // radius
    std::vector<double> x_(n), y_(n);

    for(int i = 0; i < n; ++i) {
        double t = 2 * M_PI * i / n;
        x_[i] = x+ w * cos(t);
        y_[i] = y+ w * sin(t);
    }

    // Plot the circle
    plt::figure_size(800, 600);
    plt::plot(x_, y_, "b-");
    plt::axis("scaled");
    plt::xlim(0, 20);
    plt::ylim(0, 20);
    plt::title("Quadtree Points Search");
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    std::vector<Point> points = quadtree->get_points();

    
    for (auto& point : points) {
        x_vals.push_back(point.get_x());
        y_vals.push_back(point.get_y());
    }
    plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});

    std::vector<Point> circle_found_points = quadtree->circle_query(search_area,p1);


// keep track of nearest neighbor
    Point nearest_neighbor = circle_found_points[0];
    double min_distance = 200; // Initialize with a large value
    

    std::vector<double> x_search, y_search;
    for (int i = 0; i < circle_found_points.size(); i++) {

        double distance = circle_found_points[i].distance_from_center(p1);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_neighbor = circle_found_points[i];
        }

        x_search.push_back(circle_found_points[i].get_x());
        y_search.push_back(circle_found_points[i].get_y());
    }
    
    plt::scatter(x_search, y_search, 10.0, {{"edgecolor", "r"}}); // Plot all points in black

    std::string subtitle = "Nearest Neighbor: (" + std::to_string(nearest_neighbor.get_x()) + ", " + std::to_string(nearest_neighbor.get_y()) + ")";
    
    QMessageBox::information(this, "Search Result", "Nearest Neighbor: (" + QString::number(nearest_neighbor.get_x()) + ", " + QString::number(nearest_neighbor.get_y()) + ")");


    plt::show(); // Show the plot   
}


void Widget::on_visualizeButton_clicked()
{
    plt::figure_size(800, 600);
    plt::axis("scaled");
    plt::xlim(0, 20);
    plt::ylim(0, 20);
    plt::title("Quadtree Points Insertion");
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    std::vector<Point> points = quadtree->get_points();
    std::vector<double> x_vals, y_vals;
    x_vals.push_back(points[0].get_x());
    y_vals.push_back(points[0].get_y());


    for (auto& point : points) {

        x_vals.push_back(point.get_x());
        y_vals.push_back(point.get_y());
        plt::xlim(0, 20);
        plt::ylim(0, 20);
        plt::xlabel("X-axis");
        plt::ylabel("Y-axis");
        plt::pause(0.4); // Pause for a short time to visualize the insertion

        plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});

    }

    quadtree->draw();// Draw the quadtree structure after each insertion


    plt::title("Quadtree Points");

    plt::show();
}

void Widget::on_deleteButton_clicked()
{
    // fecth the selected row from the table widget
    int selectedRow = ui->tableWidget->currentRow();
    if(selectedRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a point from the table.");
        return;
    }
    // its value in x and y coordinates
    double x = ui->tableWidget->item(selectedRow, 0)->text().toDouble();
    double y = ui->tableWidget->item(selectedRow, 1)->text().toDouble();
    // now delete this from the quadtree
    Point p1(x,y); //now it is
    quadtree->delete_point(p1);
    // clear the table widget and repopulate it
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0); // Clear existing rows
    //fill the table widget with the points from the quadtree
    std::vector<Point> points = quadtree->points; // Get the points from the quadtree
    ui->tableWidget->setRowCount(points.size());

    // Populate the table widget with the points
    for (int i = 0; i < points.size(); ++i) {
        QTableWidgetItem* xItem = new QTableWidgetItem(QString::number(points[i].get_x()));
        QTableWidgetItem* yItem = new QTableWidgetItem(QString::number(points[i].get_y()));
        ui->tableWidget->setItem(i, 0, xItem);
        ui->tableWidget->setItem(i, 1, yItem);
    }
    // show message box to show that the point is deleted
    QMessageBox::information(this, "Point Deleted", "Point (" + QString::number(x) + ", " + QString::number(y) + ") deleted successfully.");
}
