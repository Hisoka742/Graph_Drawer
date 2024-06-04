## Graph Drawing Visualization
This project implements a graph drawing algorithm using the Fruchterman-Reingold force-directed layout algorithm. The program reads graph data from a file, computes the layout, and generates a BMP image representing the graph.


C++17 or higher
CMake 3.10 or higher

# Steps
# Clone the repository:

```sh
git clone https://github.com/Hisoka742/graph-drawing.git
cd graph-drawing
```
#Create a build directory and navigate into it:

```sh
mkdir build
cd build
Run CMake to generate build files:
```

```sh
cmake ..
Build the project:
```

```sh
cmake --build .
Usage
```
# Running the Program
The program expects an input file with the graph data. The format of the input file should be:

The first line contains two integers: the number of vertices and the number of edges.
Each subsequent line contains two integers representing an edge between two vertices.


```sh
./GraphDrawing graph1.txt
The input file graph1.txt should be formatted as follows:
```

```sh
5 4
0 1
1 2
2 3
3 4
```
This will generate an image named graph.bmp in the current directory.

# Input File Format
The first line contains two integers: the number of vertices and the number of edges.
Each subsequent line contains two integers representing an edge between two vertices.
Example:

```sh
5 4
0 1
1 2
2 3
3 4
```
# Features
# Force-directed layout: The Fruchterman-Reingold algorithm positions nodes in a visually appealing manner.
Minimum edge length: Ensures edges have a minimum length of 100 pixels.
BMP image generation: Produces a BMP image of the graph with nodes and edges drawn.
Numbered vertices: Each vertex is labeled with its corresponding number.
Testing
Included Test Graphs

# Code Overview
main.cpp: The main entry point of the program. Handles reading the input file, running the layout algorithm, and generating the image.
graph.h and graph.cpp: Functions and data structures related to the graph, including image generation and vertex position initialization.
fruchterman_reingold.h and fruchterman_reingold.cpp: Implementation of the Fruchterman-Reingold force-directed layout algorithm.
Example Output
Here is an example of the generated graph image (graph.bmp):


# Detailed Steps in the Program
Input Reading: Reads the number of vertices and edges from the input file and validates them.
- Edge Reading: Reads each edge and validates the vertices.
- Initial Position Generation: Generates random initial positions for each vertex.
- Fruchterman-Reingold Algorithm: Applies the force-directed layout algorithm to adjust vertex positions.
- Image Generation: Draws the graph with edges and vertices and saves it as a BMP file

```sh
Copy code
./GraphDrawing ../test_graphs/graph1.txt
./GraphDrawing ../test_graphs/graph2.txt
./GraphDrawing ../test_graphs/graph3.txt
Contributing
```

# Contributions are welcome! Please follow these steps:

- Fork the repository.
- Create a new branch (git checkout -b feature-branch).
- Make your changes.
- Commit your changes (git commit -m 'Add new feature').
- Push to the branch (git push origin feature-branch).
- Open a pull request.

