#ifndef GRID_SOLN_HPP
#define GRID_SOLN_HPP

#include <utility>
#include <vector>

#include "../maze/grid_maze.hpp"

class GridSoln {
   public:
    GridSoln(GridMaze maze) {
        width = maze.getWidth();
        height = maze.getHeight();
        this->maze = &maze;
    }
    std::vector<std::vector<int>> grid;
    GridMaze* maze;

   private:
    int width;
    int height;
};

#endif