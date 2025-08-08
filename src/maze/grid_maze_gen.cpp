#include <set>
#include <stack>
#include <utility>

#include <chrono>
#include <random>

#include "grid_maze.h"

std::vector<std::pair<int, int>> getUnvisitedNeighbors(std::pair<int, int> cell,
                                                       int n,
                                                       int m);

bool isInBounds(std::pair<int, int> cell, int n, int m) {
    return cell.first >= 0 && cell.first < n && cell.second >= 0 &&
           cell.second < m;
}

std::vector<std::pair<int, int>> getUnvisitedNeighbors(
    std::pair<int, int> cell,
    std::set<std::pair<int, int>>& visited,
    int n,
    int m) {
    std::vector<std::pair<int, int>> possibleNeighbors = {
        {cell.first - 1, cell.second},
        {cell.first + 1, cell.second},
        {cell.first, cell.second - 1},
        {cell.first, cell.second + 1}};

    std::vector<std::pair<int, int>> actualNeighbors;
    for (const auto& neighbor : possibleNeighbors) {
        // Ensure the neighbor is within bounds and not visited
        if (isInBounds(neighbor, n, m) &&
            visited.find(neighbor) == visited.end()) {
            actualNeighbors.push_back(neighbor);
        }
    }
    return actualNeighbors;
}

void randDFSGeneration(grid_maze& maze) {
    // Choose the initial cell
    std::set<int> initCell = maze.maze[0][0];
    std::set<std::pair<int, int>> visited;
    std::stack<std::pair<int, int>> stack;

    //push it to the stack
    stack.push({0, 0});

    // mark it as visited
    visited.insert({0,0});

    //While the stack is not empty
    while (!stack.empty()) {
        // Pop a cell from the stack and make it a current cell
        auto current = stack.top();
        stack.pop();

        // Get the neighbors
        auto neighbors = getUnvisitedNeighbors(
            current, visited, maze.getHeight(), maze.getWidth());

        // If the current cell has any neighbours which have not been visited
        if (!neighbors.empty()) {
            // Push the current cell to the stack
            stack.push(current);

            // Randomly choose one of the unvisited neighbours
            std::mt19937 rng(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, neighbors.size() - 1);
            int randomIndex = dist(rng);
            auto selectedNeighbor = neighbors.at(randomIndex);

            // Remove the wall between the current cell and the selected neighbor
            maze.removeWall(current, selectedNeighbor);

            // Mark the chosen cell as visited and push it to the stack
            visited.insert(selectedNeighbor);
            stack.push(selectedNeighbor);
        }
    }
}