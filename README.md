Graph Drawing Visualization
This project implements a graph drawing algorithm using the Fruchterman-Reingold force-directed layout algorithm. The program reads graph data from a file, computes the layout, and generates a BMP image representing the graph.

Features
Force-directed layout: The Fruchterman-Reingold algorithm is used to position nodes in a visually appealing manner.
Minimum edge length: Ensures that edges have a minimum length of 100 pixels to prevent nodes from clustering too closely.
BMP image generation: Produces a BMP image of the graph with nodes and edges drawn.
Getting Started
Prerequisites
C++17 or higher
CMake 3.10 or higher
Building the Project
Clone the repository:

sh
Copy code
git clone https://github.com/yourusername/graph-drawing.git
cd graph-drawing
Create a build directory and navigate into it:

sh
Copy code
mkdir build
cd build
Run CMake to generate build files:

sh
Copy code
cmake ..
Build the project:

sh
Copy code
cmake --build .
Running the Program
The program expects an input file with the graph data. The format of the input file should be:

The first line contains two integers: the number of vertices and the number of edges.
Each subsequent line contains two integers representing an edge between two vertices.
Example graph1.txt:

Copy code
5 4
0 1
1 2
2 3
3 4
To run the program:

sh
Copy code
./GraphDrawing graph1.txt
This will generate an image named graph.bmp in the current directory.

Code Overview
main.cpp: The main entry point of the program. Handles reading the input file, running the layout algorithm, and generating the image.
graph.h and graph.cpp: Functions and data structures related to the graph, including image generation and vertex position initialization.
fruchterman_reingold.h and fruchterman_reingold.cpp: Implementation of the Fruchterman-Reingold force-directed layout algorithm.
Example Output
Here is an example of the generated graph image (graph.bmp):


Detailed Steps in the Program
Input Reading: Reads the number of vertices and edges from the input file and validates them.
Edge Reading: Reads each edge and validates the vertices.
Initial Position Generation: Generates random initial positions for each vertex.
Fruchterman-Reingold Algorithm: Applies the force-directed layout algorithm to adjust vertex positions.
Image Generation: Draws the graph with edges and vertices and saves it as a BMP file
