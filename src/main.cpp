#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include "Quadtree.h"

int main() {
    srand(time(0)); // Seed for random number generation

    // Define the boundary of the Quadtree (center at (0,0), width and height of 20)
    Box boundary(Point(10, 10), 20, 20);
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
    Point p12(5, 5);
    qt.insert_point(p12);
    Point p13(8, 8);
    qt.insert_point(p13);

    Point p14(20, 7);
    qt.insert_point(p14);
    // Print the Quadtree structure
    std::cout<< "\nQuadtree Structure:\n";
    qt.print_Quadtree();

    return 0;
}
