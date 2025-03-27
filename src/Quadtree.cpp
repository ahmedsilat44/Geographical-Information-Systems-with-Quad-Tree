#include "Quadtree.h"
#include <iostream>

Quadtree::Quadtree(Box boundary, int capacity): boundary(boundary), capacity(capacity) {

}

bool Quadtree::insert_point(Point point){
    if (boundary.contains_point(point) != true){ //is the point in the range of out map
        return false;
    }

    if (points.size() == capacity){ //has the num of points in a qaudrant reached its limit
        divide();
    }

    // if (divided != true){ 
    //     divide(); 
    // }

    points.push_back(point);
    // return true;
    
    if (divided == false){ //if we have not divided yet, we can insert the point
        return true;
    }
    nw->insert_point(point);
    ne->insert_point(point);
    sw->insert_point(point);
    se->insert_point(point);
    
    return false;
}


void Quadtree::divide(){
    Point boundary_center = boundary.get_center();
    double center_x = boundary_center.get_x();
    double center_y = boundary_center.get_y();
    double new_width = center_x / 2; 
    double new_height = center_y / 2; 

    Box temp_nw = Box(Point (center_x - new_width, center_y - new_height), new_width, new_height); 
    nw = new Quadtree(temp_nw);
    Box temp_ne = Box(Point(center_x + new_width, center_y - new_height), new_width, new_height); 
    ne = new Quadtree(temp_ne);
    Box temp_sw = Box (Point(center_x - new_width, center_y + new_height), new_width, new_height); 
    sw = new Quadtree(temp_sw);
    Box temp_se = Box(Point(center_x + new_width, center_y + new_height), new_width, new_height); 
    se = new Quadtree(temp_se);
    divided = true;

    // Insert existing points into the new quadrants
    for (const auto& point : points) {
        nw->insert_point(point);
        ne->insert_point(point);
        sw->insert_point(point);
        se->insert_point(point);
    }
}

// void Quadtree::print_Quadtree(int depth) {
//     // Indentation for visualization
//     for (int i = 0; i < depth; i++) std::cout << "  ";

//     // Print the current node's boundary
//     Point boundary_center = boundary.get_center();
//     std::cout << "Node Boundary: (" << boundary_center.get_x() << ", " << boundary_center.get_y() << ") "
//               << "Width: " << boundary.get_width() << ", Height: " << boundary.get_height() << "\n";

//     // Print points only if there are any
//     if (!points.empty()) {
//         for (int i = 0; i < depth; i++) std::cout << "  ";
//         std::cout << "Points: ";
//         for ( auto& p : points) {
//             std::cout << "(" << p.get_x() << ", " << p.get_y() << ") ";
//         }
//         std::cout << "\n";
//     }

//     // If subdivided, print subdivisions and recursively print children
//     if (divided) {
//         for (int i = 0; i < depth; i++) std::cout << "  ";
//         std::cout << "Subdivided:\n";

//         if (nw != nullptr) nw->print_Quadtree(depth + 1);
//         if (ne != nullptr) ne->print_Quadtree(depth + 1);
//         if (sw != nullptr) sw->print_Quadtree(depth + 1);
//         if (se != nullptr) se->print_Quadtree(depth + 1);
//     }
// }

void Quadtree::print_Quadtree(int depth) {
    std::cout << "Box: " << depth << " points: ";
    for(auto p: points){
        std::cout << "(" << p.get_x() << ", " << p.get_y() << ") ";
    }
    std::cout << std::endl;

    if (divided != false){
        if (nw != nullptr) {
            std::cout << "nw\n"; 
            nw->print_Quadtree(depth + 1);
        }
        if (ne != nullptr) {
            std::cout << "ne\n"; 
            ne->print_Quadtree(depth + 1);
        }
        if (sw != nullptr) {
            std::cout << "sw\n"; 
            sw->print_Quadtree(depth + 1);
        }
        if (se != nullptr) {
            std::cout << "se\n"; 
            se->print_Quadtree(depth + 1);
        }
    }


}

// void Quadtree::print_Quadtree(int depth) {
//     // Indentation for visualization
//     for (int i = 0; i < depth; i++) std::cout << "  ";

//     // Print the current node's boundary
//     Point boundary_center = boundary.get_center();
//     std::cout << "Node Boundary: (" << boundary_center.get_x() << ", " << boundary_center.get_y() << ") "
//               << "Width: " << boundary.get_width() << ", Height: " << boundary.get_height() << "\n";

//     // Print points only if there are any
//     if (!points.empty()) {
//         for (int i = 0; i < depth; i++) std::cout << "  ";
//         std::cout << "Points: ";
//         for ( auto& p : points) {
//             std::cout << "(" << p.get_x() << ", " << p.get_y() << ") ";
//         }
//         std::cout << "\n";
//     }

//     // If subdivided, print subdivisions and recursively print children
//     if (divided) {
//         for (int i = 0; i < depth; i++) std::cout << "  ";
//         std::cout << "Subdivided:\n";

//         if (nw != nullptr) nw->print_Quadtree(depth + 1);
//         if (ne != nullptr) ne->print_Quadtree(depth + 1);
//         if (sw != nullptr) sw->print_Quadtree(depth + 1);
//         if (se != nullptr) se->print_Quadtree(depth + 1);
//     }


    


// }


Quadtree::~Quadtree(){
    delete nw;
    delete ne;
    delete sw;
    delete se;
}
