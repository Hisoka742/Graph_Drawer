#include "graph.h"
#include "fruchterman_reingold.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(int argc, char* argv[]) {
    srand(time(0));

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    int num_vertices, num_edges;
    infile >> num_vertices >> num_edges;

    std::cout << "Read from file: " << num_vertices << " vertices, " << num_edges << " edges" << std::endl;

    if (num_vertices <= 0 || num_vertices > 500) {
        std::cerr << "Invalid number of vertices: " << num_vertices << std::endl;
        return 1;
    }

    if (num_edges < 0 || num_edges > num_vertices * (num_vertices - 1) / 2) {
        std::cerr << "Invalid number of edges: " << num_edges << std::endl;
        return 1;
    }

    std::vector<std::pair<int, int>> edges(num_edges);
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        infile >> u >> v;
        if (u < 0 || u >= num_vertices || v < 0 || v >= num_vertices || u == v) {
            std::cerr << "Invalid edge: " << u << " " << v << std::endl;
            return 1;
        }
        edges[i] = { u, v };
    }
    infile.close();

    std::vector<Point> positions = generate_positions(num_vertices);

    std::cout << "Generated initial positions for vertices" << std::endl;

    fruchterman_reingold(positions, edges);

    std::cout << "Applied Fruchterman-Reingold algorithm" << std::endl;

    generate_graph_image(edges, positions, "graph.bmp");

    std::cout << "Graph image generated and saved as graph.bmp" << std::endl;
    return 0;
}

