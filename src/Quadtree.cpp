#include "Quadtree.h"
#include <iostream>
#include <algorithm> // for std::find
#include <cmath>
// #include "matplotlibcpp.h"

using namespace std;
// namespace plt = matplotlibcpp;

// create color array for color of lines based on depth
const std::vector<std::string> colors = {"g", "r", "b", "c", "m", "y", "g"}; // Add more colors as needed

std::vector<double> x_vals, y_vals;

Quadtree::Quadtree(Box boundary, int capacity, int depth): boundary(boundary), capacity(capacity), depth(depth) {
    divided = false;
}

bool Quadtree::insert_point(Point point){
    if (boundary.contains_point(point) != true){ //is the point in the range of out map
        return false;
    }

    
    points.push_back(point);
    x_vals.clear(); // Clear previous x values
    y_vals.clear(); // Clear previous y values
    
    for(auto& point : points){
        x_vals.push_back(point.get_x());
        y_vals.push_back(point.get_y());
    }
    
    // plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});
    // plt::pause(0.35); // Pause for a short time to visualize the insertion
    
    if (points.size() > capacity && divided == false){ //has the num of points in a qaudrant reached its limit
        // plt::title("Copy to sub-quadrants");
        divide();
        // plt::title("Quadtree Points Insertion");
    }else{

        
        
        
        
        // plt::show(); // Show the plot
        
        if (divided != true){ 
            
            
            
            // return true;
        }else{ //if we have not divided yet, we can insert the point
            if(point.get_x() < boundary.get_center().get_x() && point.get_y() < boundary.get_center().get_y()){
                nw->insert_point(point);
            }else if(point.get_x() > boundary.get_center().get_x() && point.get_y() < boundary.get_center().get_y()){
                ne->insert_point(point);
            }else if(point.get_x() < boundary.get_center().get_x() && point.get_y() > boundary.get_center().get_y()){
                sw->insert_point(point);
            }else if(point.get_x() > boundary.get_center().get_x() && point.get_y() > boundary.get_center().get_y()){
                se->insert_point(point);
            }
            
            // plt::title("Quadtree Points Insertion");
            // nw->insert_point(point);
            // ne->insert_point(point);
            // sw->insert_point(point);
            // se->insert_point(point);
        }
    }
    
    
    // drawpoint(); // Draw the quadtree structure after each insertion

    std::cout << "Inserted: (" << point.get_x() << ", " << point.get_y() << ")\n";
    
    

    
    return false;

    

}


void Quadtree::divide(){

    int limit = 20;
    // draw lines through center
    double center_x = boundary.get_center().get_x();
    double center_y = boundary.get_center().get_y();
    double width = boundary.get_width();
    double height = boundary.get_height();
    double west = center_x - width;
    double east = center_x + width;
    double north = center_y - height; //y increases in the down direction hence the "- height"
    double south = center_y + height;
    // Draw the boundary of the Quadtree node give color and zorder
    string color = colors[depth % colors.size()]; 
    
    // plt::title("Copy to sub-quadrants");

    std::cout<< "width: " << width << " height: " << height << std::endl;

    std::cout << "making horizontal line from "<< west << " to " << east << std::endl;
    // plt::plot({west, east}, {center_y, center_y}, {{"color",color},{"linewidth","1"}}); // Horizontal line

    
    std::cout << "making vertical line from "<< north << " to " << south << std::endl;

    // plt::plot({center_x, center_x}, {north, south}, {{"color",color},{"linewidth","1"}}); // Vertical line
    // plt::xlim(0, limit); // Set x-axis limits
    // plt::ylim(0, limit); // Set y-axis limits

    Point boundary_center = boundary.get_center();
    // double center_x = boundary_center.get_x();
    // double center_y = boundary_center.get_y();
    double new_width = width / 2; 
    double new_height = height / 2; 

    Box temp_nw = Box(Point (center_x - new_width, center_y - new_height), new_width, new_height); 
    nw = new Quadtree(temp_nw, 4 ,depth + 1);
    Box temp_ne = Box(Point(center_x + new_width, center_y - new_height), new_width, new_height); 
    ne = new Quadtree(temp_ne, 4 ,depth + 1);
    Box temp_sw = Box (Point(center_x - new_width, center_y + new_height), new_width, new_height); 
    sw = new Quadtree(temp_sw, 4 ,depth + 1);
    Box temp_se = Box(Point(center_x + new_width, center_y + new_height), new_width, new_height); 
    se = new Quadtree(temp_se, 4 ,depth + 1);
    divided = true;

    // Insert existing points into the new quadrants
    for (const auto& point : points) {
        if(nw->boundary.contains_point(point)) {
            nw->insert_point(point);
        } else if (ne->boundary.contains_point(point)) {
            ne->insert_point(point);
        } else if (sw->boundary.contains_point(point)) {
            sw->insert_point(point);
        } else if (se->boundary.contains_point(point)) {
            se->insert_point(point);
        }
        

        // nw->insert_point(point);
        // ne->insert_point(point);
        // sw->insert_point(point);
        // se->insert_point(point);
    }
    

    // if (nw != nullptr) {
    //     nw->draw();
    // }
    // if (ne != nullptr) {
    //     ne->draw();
    // }
    // if (sw != nullptr) {
    //     sw->draw();
    // }
    // if (se != nullptr) {
    //     se->draw();
    // }

    // this->draw(); // Draw the quadtree structure after each insertion
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


void Quadtree::drawpoint(){
    // std::vector<Point> points = this->get_points();
    // std::vector<double> x_vals, y_vals;

    
    
    // for (auto& point : points) {
    //     x_vals.push_back(point.get_x());
    //     y_vals.push_back(point.get_y());
    //     plt::xlim(0, 20);
    //     plt::ylim(0, 20);
    //     plt::title("Quadtree Points");
    //     plt::xlabel("X-axis");
    //     plt::ylabel("Y-axis");
    //     plt::scatter(x_vals, y_vals, 10.0, {{"color", "k"}});
    //     this->draw(); // Draw the quadtree structure after each insertion
    //     plt::pause(0.4); // Pause for a short time to visualize the insertion
        
    // }

}

void Quadtree::draw() {

   // draw lines through center
    double center_x = boundary.get_center().get_x();
    double center_y = boundary.get_center().get_y();
    double width = boundary.get_width();
    double height = boundary.get_height();
    double west = center_x - width;
    double east = center_x + width;
    double north = center_y - height; //y increases in the down direction hence the "- height"
    double south = center_y + height;
    // Draw the boundary of the Quadtree node give color and zorder
    string color = colors[depth % colors.size()]; 
    // plt::plot({west, east}, {center_y, center_y}, {{"color",color},{"linewidth","1"}}); // Horizontal line
    // plt::plot({center_x, center_x}, {north, south}, {{"color",color},{"linewidth","1"}}); // Vertical line
    // plt::pause(0.5); // Pause to allow the plot to update
    // plt::xlim(0, 20); // Set x-axis limits
    // plt::ylim(0, 20); // Set y-axis limits

    // plt::show(); // Show the plot

    if (divided) 
    {
        if (nw != nullptr) {
            nw->draw();
        }
        if (ne != nullptr) {
            ne->draw();
        }
        if (sw != nullptr) {
            sw->draw();
        }
        if (se != nullptr) {
            se->draw();
        }
    }

}

void Quadtree::show() {
    // Show the plot
    // // plt::plot();
}
