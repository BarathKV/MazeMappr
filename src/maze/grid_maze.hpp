#ifndef GRID_MAZE_HPP
#define GRID_MAZE_HPP

#include <set>
#include <vector>
#include <iostream>

class GridMaze {
   public:
    GridMaze(int width, int height) {
        this->width = width;
        this->height = height;
        maze.resize(height, std::vector<std::set<int>>(width));
        std::cout << "Maze created with dimensions: " << width << "x" << height << std::endl;
    }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    std::vector<std::vector<std::set<int>>> maze;

    void removeWall(std::pair<int, int> cell1, std::pair<int, int> cell2) {
        // Remove the wall between two cells
        if (cell1.first == cell2.first) {
            // Vertical wall
            if (cell1.second < cell2.second) {
                // Remove the wall where cell1 is left of cell2
                maze[cell1.first][cell1.second].insert(1);
                maze[cell2.first][cell2.second].insert(3);
            } else {
                // Remove the wall where cell1 is right of cell2
                maze[cell1.first][cell1.second].insert(3);
                maze[cell2.first][cell2.second].insert(1);
            }
        } else {
            // Horizontal wall
            if (cell1.first < cell2.first) {
                // Remove the wall where cell1 is above cell2
                maze[cell1.first][cell1.second].insert(2);
                maze[cell2.first][cell2.second].insert(0);
            } else {
                // Remove the wall where cell1 is below cell2
                maze[cell1.first][cell1.second].insert(0);
                maze[cell2.first][cell2.second].insert(2);
            }
        }
    }

   private:
    int width;
    int height;
};

#endif