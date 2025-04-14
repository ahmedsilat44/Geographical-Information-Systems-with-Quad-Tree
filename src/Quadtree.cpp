#include "Quadtree.h"
#include <iostream>
#include <algorithm> // for std::find

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
    
    if (divided == true){ //if we have not divided yet, we can insert the point
        
        nw->insert_point(point);
        ne->insert_point(point);
        sw->insert_point(point);
        se->insert_point(point);
    }
    
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

std::vector<Point> Quadtree::square_query(Box range){
    std::vector<Point> found_points;

    
    if (this->boundary.intersects(range) == false)
        return found_points;

    for (Point point:points){
        if (range.contains_point(point))
            found_points.push_back(point);
    }

    // std::cout << found_points.size() << " points found in the search area:\n";

    
    if (this->divided){
        std::vector<Point> nw_points;
        std::vector<Point> ne_points;
        std::vector<Point> sw_points;
        std::vector<Point> se_points;
        
        if (this->nw != nullptr){
            std::vector<Point> nw_points=this->nw->square_query(range);
        }
        if (this->ne != nullptr){
            std::vector<Point> ne_points=this->ne->square_query(range);
        }
        if (this->sw != nullptr){
            std::vector<Point> sw_points=this->sw->square_query(range);
        }
        if (this->se != nullptr){
            std::vector<Point> se_points=this->se->square_query(range);
        }

        // std::cout << "searching in ne\n";
        // std::vector<Point> ne_points=this->ne->square_query(range);
        // std::cout << "searching in sw\n";
        // std::vector<Point> sw_points=this->sw->square_query(range);
        // std::cout << "searching in se\n";
        // std::vector<Point> se_points=this->se->square_query(range);
        found_points.insert(found_points.end(),nw_points.begin(),nw_points.end());
        
        found_points.insert(found_points.end(),ne_points.begin(),ne_points.end());
        found_points.insert(found_points.end(),sw_points.begin(),sw_points.end());
        found_points.insert(found_points.end(),se_points.begin(),se_points.end());

        
        std::cout << found_points.size() << " points found in the search area:\n";
    }

    return found_points;
}

std::vector<Point> Quadtree::circle_query(Box range, Point center){
    std::vector<Point> found_points;
    if (!this->boundary.intersects(range))
        return found_points;

    for (Point point:points){
        if (range.contains_point(point) & point.distance_from_center(center)<=range.get_width() & point != center)
            found_points.push_back(point);
    }
    
    if (this->divided){

        std::vector<Point> nw_points;
        std::vector<Point> ne_points;
        std::vector<Point> sw_points;
        std::vector<Point> se_points;





        // std::vector<Point> nw_points=this->nw->circle_query(range,center);
        // std::vector<Point> ne_points=this->ne->circle_query(range,center);
        // std::vector<Point> sw_points=this->sw->circle_query(range,center);
        // std::vector<Point> se_points=this->se->circle_query(range,center);

        if (this->nw != nullptr){
            std::vector<Point> nw_points=this->nw->circle_query(range,center);
        }
        if (this->ne != nullptr){
            std::vector<Point> ne_points=this->ne->circle_query(range,center);
        }
        if (this->sw != nullptr){
            std::vector<Point> sw_points=this->sw->circle_query(range,center);
        }
        if (this->se != nullptr){
            std::vector<Point> se_points=this->se->circle_query(range,center);
        }


        found_points.insert(found_points.end(),nw_points.begin(),nw_points.end());
        found_points.insert(found_points.end(),ne_points.begin(),ne_points.end());
        found_points.insert(found_points.end(),sw_points.begin(),sw_points.end());
        found_points.insert(found_points.end(),se_points.begin(),se_points.end());
    }

    return found_points;
}

bool Quadtree::delete_point(Point point){
    // then check if its divided. if true. we calculate which quadrant the point is in and call delete_point on that quadrant
    // then we check if the point is in the points vector. if it is, we remove it and return true. if not, we return false

    if (boundary.contains_point(point) != true){ //is the point in the range of out map
        return false;
    }

    if (divided) {
        if(nw->boundary.contains_point(point)){
            nw->delete_point(point);
        } 
        else if(ne->boundary.contains_point(point)){
            ne->delete_point(point);
        } 
        else if(sw->boundary.contains_point(point)){
            sw->delete_point(point);
        } 
        else if(se->boundary.contains_point(point)){
            se->delete_point(point);
        }
    }
    

    auto it = std::find(points.begin(), points.end(), point); // Check if the point is in the current node's points

    if (it != points.end()) {
        points.erase(it); // Remove the point from the vector
    }
    
    if (points.size() <= capacity && divided == true) {
        // If the number of points in this node is less than the capacity and it has been divided,
        // we can merge the quadrants back together (optional, depending on your implementation).
        delete nw;
        delete ne;
        delete sw;
        delete se;
        nw = nullptr;
        ne = nullptr;
        sw = nullptr;
        se = nullptr;
        divided = false; // Mark as not divided
    }
    return false; // Point not found


    
}


//auto it = std::find(points.begin(), points.end(), point);

