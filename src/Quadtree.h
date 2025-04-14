#ifndef QUADTREE_H
#define QUADTREE_H
#include "Box.h" 
#include <vector>

class Quadtree{
    private:
        Box boundary;
        int depth = 0;
        int capacity;
        std::vector<Point> points;
        bool divided;
        Quadtree *nw = nullptr; 
        Quadtree *ne = nullptr; 
        Quadtree *sw = nullptr; 
        Quadtree *se = nullptr;
    
    public:
        Quadtree(Box boundary, int capacity = 4, int depth = 0);
        bool insert_point(Point point);
        bool delete_point(Point point);
        void divide();
        void print_Quadtree(int deapth = 0);
        std::vector<Point> square_query(Box range);
        std::vector<Point> circle_query(Box range, Point center);
        
        std::vector<Point> get_points() { return points; }
        void show();
        void draw();
        void drawpoint();


        ~Quadtree();

};

#endif // QUADTREE_H
