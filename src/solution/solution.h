#ifndef SOLN_H
#define SOLN_H

#include "Path.h"

#include <string>

class Solution {
    // size of the maze grid
    int rows, cols;

    // start of the maze
    Path* startNode;

    // end of the maze
    Path* endNode;

   public:
    // Constructor that initializes the maze with a grid size
    Solution(const int rows, const int cols) {
        this->rows = rows;
        this->cols = cols;
    }
};

#endif