#include <vector>
#include <set>
#include <iostream>

#include "grid_soln.hpp"
#include "../maze/grid_maze_gen.hpp"

void randomMouseSolnGen(GridSoln& soln) {
    std::pair<int, int> initCell = {0, 0};
    std::set<std::pair<int, int>> visited;
    visited.insert(initCell);

    // Initialize soln.grid to the correct size
    soln.grid = std::vector<std::vector<int>>(soln.maze->getHeight(), std::vector<int>(soln.maze->getWidth(), -1));

    while (!visited.empty()) {
        auto it = visited.begin();
        std::advance(it, rand() % visited.size());
        std::pair<int, int> current = *it;

        if (current == std::make_pair(soln.maze->getWidth() - 1, soln.maze->getHeight() - 1)) {
            std::cout << "Found a solution!" << std::endl;
            return;
        }

        auto neighbors = getUnvisitedNeighbors(current, visited, soln.maze->getHeight(), soln.maze->getWidth());
        for (const auto& neighbor : neighbors) {
            visited.insert(neighbor);

            // Determine direction from current to neighbor
            int dx = neighbor.first - current.first;
            int dy = neighbor.second - current.second;
            int dir = -1;
            if (dx == 0 && dy == -1) dir = 0; // North
            else if (dx == 1 && dy == 0) dir = 1; // East
            else if (dx == 0 && dy == 1) dir = 2; // South
            else if (dx == -1 && dy == 0) dir = 3; // West

            // Record direction in soln.grid
            if (dir != -1)
                soln.grid[current.second][current.first] = dir;
        }

        visited.erase(current);
    }

    std::cout << "No solution found." << std::endl;
}