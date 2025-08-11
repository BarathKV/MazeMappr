#ifndef GRID_MAZE_GEN_HPP
#define GRID_MAZE_GEN_HPP

#include "grid_maze.hpp"

void randDFSGeneration(GridMaze& maze);

std::vector<std::pair<int, int>> getUnvisitedNeighbors(
    std::pair<int, int> cell,
    std::set<std::pair<int, int>>& visited,
    int n,
    int m);
                                    
bool isInBounds(std::pair<int, int> cell, int n, int m);

#endif