#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "constants.h"

struct Point {
    double x;
    double y;
};

double distance(const Point& p1, const Point& p2);
std::vector<Point> generate_positions(int num_vertices);
void generate_graph_image(const std::vector<std::pair<int, int>>& edges, const std::vector<Point>& positions, const char* filename);

#endif // GRAPH_H
