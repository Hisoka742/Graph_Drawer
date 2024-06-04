#include "graph.h"
#include "draw.h"
#include "bmp.h"
#include <algorithm>
#include <cstdlib>

std::vector<Point> generate_positions(int num_vertices) {
    std::vector<Point> positions(num_vertices);
    for (auto& pos : positions) {
        pos.x = rand() % WIDTH;
        pos.y = rand() % HEIGHT;
    }
    return positions;
}

void generate_graph_image(const std::vector<std::pair<int, int>>& edges, const std::vector<Point>& positions, const char* filename) {
    unsigned char* image = new unsigned char[WIDTH * HEIGHT * 3];
    std::fill(image, image + WIDTH * HEIGHT * 3, 255);  // Fill with white color

    for (const auto& edge : edges) {
        int x1 = static_cast<int>(positions[edge.first].x);
        int y1 = static_cast<int>(positions[edge.first].y);
        int x2 = static_cast<int>(positions[edge.second].x);
        int y2 = static_cast<int>(positions[edge.second].y);
        if (distance(positions[edge.first], positions[edge.second]) >= MIN_EDGE_LENGTH) {
            draw_line(image, WIDTH, HEIGHT, x1, y1, x2, y2, 0, 0, 0);  // Black color
        }  
    }

    for (size_t i = 0; i < positions.size(); ++i) {
        int x = static_cast<int>(positions[i].x);
        int y = static_cast<int>(positions[i].y);
        draw_circle(image, WIDTH, HEIGHT, x, y, NODE_RADIUS, 0, 0, 0);  // Black color
        draw_text(image, WIDTH, HEIGHT, x, y, std::to_string(i), 0, 0, 0); // Draw vertex number
    }

    saveBMP(filename, image, WIDTH, HEIGHT);
    delete[] image;
}

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
