#ifndef GRAPH_MAZE_H
#define GRAPH_MAZE_H

#include "graph_node.h"

#include <string>

class graph_maze {
    // size of the maze grid
    int rows, cols;

    // start of the maze
    graph_node* startNode;

    // end of the maze
    graph_node* endNode;

   public:
    // Constructor that initializes the maze with a grid size
    graph_maze(const int rows, const int cols) {
        this->rows = rows;
        this->cols = cols;
    }

    // Constructor that reads a maze from a file
    graph_maze(const std::string& filename) {}
};

#endif