#ifndef PRINTER_H
#define PRINTER_H

#include "../maze/grid_maze.h"
// #include "../maze/graph_maze.h"
#include "node_states.h"

#include <iostream>


class Printer {
   public:
    // Printer() { std::cout << "Printer initialized." << std::endl; }

    // // Function to print the graph based maze to the console
    // void print(const graph_maze& maze) const {
    //     // Implementation for printing the maze
    // }

    // Function to print the grid based maze to a console
    void print(const grid_maze& maze) const;

    // // Function to print the solution to the console
    // void print(const Solution& solution) const {
    //     // Implementation for printing the solution
    // }

    // void save(const graph_maze& maze, const std::string& filename) const {
    //     // Implementation for saving the maze to a file
    // }

    void save(const grid_maze& maze, const std::string& filename) const {
        // Implementation for saving the grid maze to a file
    }

    // void save(const Solution& solution, const std::string& filename) const {
    //     // Implementation for saving the solution to a file
    // }
};

#endif