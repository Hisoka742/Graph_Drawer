# Graph Drawing Visualization

This project implements a graph drawing algorithm using the Fruchterman-Reingold force-directed layout algorithm. The program reads graph data from a file, computes the layout, and generates a BMP image representing the graph.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Installation

### Prerequisites

- C++17 or higher
- CMake 3.10 or higher

### Steps

1. **Clone the repository**:
    ```sh
    git clone https://github.com/yourusername/graph-drawing.git
    cd graph-drawing
    ```

2. **Create a build directory and navigate into it**:
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to generate build files**:
    ```sh
    cmake ..
    ```

4. **Build the project**:
    ```sh
    cmake --build .
    ```

## Usage

To run the program, use the following command:

```sh
./GraphDrawing graph1.txt

