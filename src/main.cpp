#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include "Quadtree.h"

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;



int main() {
    srand(time(0)); // Seed for random number generation
    int limit = 20;
    Point centre (10, 10); // Center of the Quadtree
    // Define the boundary of the Quadtree (center at (0,0), width and height of 20)
    Box boundary(centre, limit, limit);
    Quadtree qt(boundary, 4); // Max capacity of 4 points per node

    // Insert 10 random points into the Quadtree
    std::cout << "Inserting points:\n";
    // for (int i = 0; i < 10; i++) {
    //     double x = (rand() % 2000) / 100.0;  // Random x in range [0, 20]
    //     double y = (rand() % 2000) / 100.0;  // Random y in range [0, 20]
        
    //     Point p(x, y);
    //     qt.insert_point(p);

    //     std::cout << "Inserted: (" << x << ", " << y << ")\n";
    // }
    // plt::xlim(0, limit);
    // plt::ylim(0, limit);
    // plt::title("Quadtree Points Insertion");
    // plt::xlabel("X-axis");
    // plt::ylabel("Y-axis");

    Point p1(15.98, 8.21);
    qt.insert_point(p1);
    Point p2(4.12, 12.18);
    qt.insert_point(p2);
    Point p3(2.02, 5.36);
    qt.insert_point(p3);
    Point p4(14.6, 7.16);
    qt.insert_point(p4);
    Point p5(7.34, 2.47);
    qt.insert_point(p5);
    Point p6(12.25, 9.88);
    qt.insert_point(p6);
    Point p7(18.03, 19.27);
    qt.insert_point(p7);
    Point p8(5, 6.87);
    qt.insert_point(p8);
    Point p9(7.48, 11.42);
    qt.insert_point(p9);
    Point p10(17.51, 0.55);
    qt.insert_point(p10);

    Point p11(1, 1);
    qt.insert_point(p11);
    // qt.print_Quadtree();
    Point p12(5, 5);
    qt.insert_point(p12);
    // std::cout<< "\nHEHEHEHE\n";
    // qt.print_Quadtree();
    Point p13(8, 8);
    qt.insert_point(p13);

    Point p14(19.9, 7);
    qt.insert_point(p14);
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
    // qt.insert_point(p15);
    // qt.insert_point(p16);
    // qt.insert_point(p17);
    // qt.insert_point(p18);
    // qt.insert_point(p19);
    // qt.insert_point(p20);
    // qt.insert_point(p21);
    // qt.insert_point(p22);
    // qt.insert_point(p23);
    // qt.insert_point(p24);
    // qt.insert_point(p25);
    // qt.insert_point(p26);
    // qt.insert_point(p27);
    // qt.insert_point(p28);

    // Print the Quadtree structure
    // std::cout<< "\nQuadtree Structure:\n";
    // qt.print_Quadtree();

    // Extract points from the Quadtree for plotting
    std::vector<Point> points = qt.get_points();
    std::vector<double> x_vals, y_vals;
    x_vals.push_back(points[0].get_x());
    y_vals.push_back(points[0].get_y());
    
    // plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});
    
    // for (auto& point : points) {
    //     x_vals.push_back(point.get_x());
    //     y_vals.push_back(point.get_y());
    //     plt::xlim(0, 20);
    //     plt::ylim(0, 20);
    //     plt::xlabel("X-axis");
    //     plt::ylabel("Y-axis");
    //     plt::pause(0.4); // Pause for a short time to visualize the insertion
    
    // }
    
    // Plot the points
    // plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});
    // qt.draw();
    
    
    
    // call draw for each quadtree that is divided
    
    // plt::title("Quadtree Points");
    
    // plt::show();

    return 0;
}
