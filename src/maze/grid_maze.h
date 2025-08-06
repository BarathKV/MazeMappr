#ifndef GRID_MAZE_H
#define GRID_MAZE_H

#include <set>
#include <vector>

class grid_maze {
   public:
    // Constructor
    grid_maze(int width, int height) {
        this->width = width;
        this->height = height;
        maze.resize(height, std::vector<std::set<int>>(width));
    }

    int getWidth() const { return width; }

    int getHeight() const { return height; }
    std::vector<std::vector<std::set<int>>> maze;

   private:
    int width;
    int height;
};

#endif