#ifndef GRAPH_MAZE_HPP
#define GRAPH_MAZE_HPP

#include "graph_node.hpp"

#include <string>

class GraphMaze {
    // size of the maze grid
    int rows, cols;

    // start of the maze
    GraphNode* startNode;

    // end of the maze
    GraphNode* endNode;

   public:
    // Constructor that initializes the maze with a grid size
    GraphMaze(const int rows, const int cols) {
        this->rows = rows;
        this->cols = cols;
    }

    // Constructor that reads a maze from a file
    GraphMaze(const std::string& filename) {}
};

#endif