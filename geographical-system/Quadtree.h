#ifndef QUADTREE_H
#define QUADTREE_H
#include "Box.h" 
#include <vector>

class Quadtree{
    private:
        Box boundary;
        int capacity;

        bool divided;
        Quadtree *nw = nullptr; 
        Quadtree *ne = nullptr; 
        Quadtree *sw = nullptr; 
        Quadtree *se = nullptr;
    
    public:
        Quadtree(Box boundary, int capacity = 4);
        bool insert_point(Point point);
        void divide();
        void print_Quadtree(int deapth = 0);
        std::vector<Point> square_query(Box range);
        std::vector<Point> circle_query(Box range, Point center);
        std::vector<Point> points;

        ~Quadtree();

};

#endif // QUADTREE_H
