#ifndef PRINTER_HPP
#define PRINTER_HPP

#include "../maze/grid_maze.hpp"
#include "../solution/grid_soln.hpp"
// #include "../maze/graph_maze.hpp"
#include "node_states.hpp"

#include <iostream>


class Printer {
   public:
    // Printer() { std::cout << "Printer initialized." << std::endl; }

    // // Function to print the graph based maze to the console
    // void print(const graph_maze& maze) const {
    //     // Implementation for printing the maze
    // }

    // Function to print the grid based maze to a console
    void print(const GridMaze& maze) const;

    // Function to print the solution to the console
    void print(const GridSoln& solution) const {
        // Implementation for printing the solution
    }

    // void save(const GraphMaze& maze, const std::string& filename) const {
    //     // Implementation for saving the maze to a file
    // }

    void save(const GridMaze& maze, const std::string& filename) const {
        // Implementation for saving the grid maze to a file
    }

    // void save(const Solution& solution, const std::string& filename) const {
    //     // Implementation for saving the solution to a file
    // }
};

#endif