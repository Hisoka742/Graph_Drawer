#include "FruchtermanReingold_.h"
#include "../math/Vector2D_.h"
#include <cmath>

double distance_(const Point2D_& p1, const Point2D_& p2) {
    return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY(), 2));
}

void fruchterman_reingold(std::vector<Point2D_>& positions, const Graph_& graph, int width, int height) {
    const double k = std::sqrt((width * height) / positions.size()); // Optimal distance between nodes

    // Perform several iterations to minimize energy
    for (int iter = 0; iter < 100; ++iter) {
        std::vector<Vector2D_> delta(positions.size(), Vector2D_());

        // Repulsive forces between all pairs of nodes
        for (size_t i = 0; i < positions.size(); ++i) {
            for (size_t j = 0; j < positions.size(); ++j) {
                if (i != j) {
                    double d = distance_(positions[i], positions[j]);
                    double force = k * k / d;
                    delta[i].setX(delta[i].getX() + force * (positions[i].getX() - positions[j].getX()) / d);
                    delta[i].setY(delta[i].getY() + force * (positions[i].getY() - positions[j].getY()) / d);
                }
            }
        }

        // Attractive forces along edges
        for (const auto& edge : graph.getEdges()) {
            Point2D_ p1 = positions[edge.first];
            Point2D_ p2 = positions[edge.second];
            double d = distance_(p1, p2);
            double force = d * d / k;
            delta[edge.first].setX(delta[edge.first].getX() - force * (p2.getX() - p1.getX()) / d);
            delta[edge.first].setY(delta[edge.first].getY() - force * (p2.getY() - p1.getY()) / d);
            delta[edge.second].setX(delta[edge.second].getX() + force * (p2.getX() - p1.getX()) / d);
            delta[edge.second].setY(delta[edge.second].getY() + force * (p2.getY() - p1.getY()) / d);
        }

        // Limit maximum displacement to temperature t and cool down
        double t = (iter < 20) ? 10.0 * (1.0 - iter / 20.0) : 0.5;
        for (size_t i = 0; i < positions.size(); ++i) {
            double d = delta[i].magnitude();
            if (d > 0) {
                double scale = std::min(d, t) / d;
                positions[i].move(delta[i].getX() * scale, delta[i].getY() * scale);
            }
        }
    }
}
