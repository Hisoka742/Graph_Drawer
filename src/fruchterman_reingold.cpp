#include "fruchterman_reingold.h"
#include "constants.h"
#include <cmath>
#include <algorithm>

void fruchterman_reingold(std::vector<Point>& positions, const std::vector<std::pair<int, int>>& edges) {
    const double k = sqrt((WIDTH * HEIGHT) / positions.size()); // Optimal distance between nodes

    for (int iter = 0; iter < 100; ++iter) {
        std::vector<Point> delta(positions.size(), { 0.0, 0.0 });

        for (size_t i = 0; i < positions.size(); ++i) {
            for (size_t j = 0; j < positions.size(); ++j) {
                if (i != j) {
                    double d = distance(positions[i], positions[j]);
                    double force = k * k / d;
                    delta[i].x += force * (positions[i].x - positions[j].x) / d;
                    delta[i].y += force * (positions[i].y - positions[j].y) / d;
                }
            }
        }

        for (const auto& edge : edges) {
            Point p1 = positions[edge.first];
            Point p2 = positions[edge.second];
            double d = distance(p1, p2);
            double force = d * d / k;
            delta[edge.first].x -= force * (p2.x - p1.x) / d;
            delta[edge.first].y -= force * (p2.y - p1.y) / d;
            delta[edge.second].x += force * (p2.x - p1.x) / d;
            delta[edge.second].y += force * (p2.y - p1.y) / d;
        }

        double t = (iter < 20) ? 10.0 * (1.0 - iter / 20.0) : 0.5;
        for (size_t i = 0; i < positions.size(); ++i) {
            double d = sqrt(delta[i].x * delta[i].x + delta[i].y * delta[i].y);
            if (d > 0) {
                double scale = std::min(d, t) / d;
                positions[i].x += delta[i].x * scale;
                positions[i].y += delta[i].y * scale;
            }
        }
    }
}
