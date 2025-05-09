#include "mainwindow.h"

#include <QApplication>
#pragma push_macro("slots")
#undef slots
#include "Python.h"
#pragma pop_macro("slots")




#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[])
{


    std::vector<double> x_vals, y_vals;
    // x_vals.push_back(points[0].get_x());
    // y_vals.push_back(points[0].get_y());

    
    QApplication a(argc, argv);
    Widget w;
    w.show();
    // std::vector<Point> points = quadtree->get_points();
    // x_vals.push_back(points[0].get_x());
    // y_vals.push_back(points[0].get_y());

    // plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});
    // // qt.draw();

    // plt::title("Quadtree Points");
    // plt::xlim(0, 20);
    // plt::ylim(0, 20);
    // plt::title("Quadtree Points Insertion");
    // plt::xlabel("X-axis");
    // plt::ylabel("Y-axis");
    // plt::show();
   
    // std::vector<Point> points = qt.get_points();


    return a.exec();
}
