#ifndef PRINTER_H
#define PRINTER_H

#include "../maze/grid_maze.h"
// #include "../maze/graph_maze.h"
#include "node_states.h"

#include <iostream>

void copyTemplateToPrinter(
    std::vector<std::vector<maze_code>>& printable_maze,
    const std::vector<std::vector<maze_code>>& template_maze,
    int row_offset,
    int col_offset) {
    for (int i = 0; i < template_maze.size(); ++i) {
        for (int j = 0; j < template_maze[i].size(); ++j) {
            printable_maze[row_offset + i][col_offset + j] +=
                template_maze[i][j];
        }
    }
}

class Printer {
   public:
    Printer() { std::cout << "Printer initialized." << std::endl; }

    // // Function to print the graph based maze to the console
    // void print(const graph_maze& maze) const {
    //     // Implementation for printing the maze
    // }

    // Function to print the grid based maze to a console
    void print(const grid_maze& maze) const {
        std::cout << "Printing grid maze..." << std::endl;
        std::vector<std::vector<maze_code>> printable_grid;
        printable_grid.resize(
            1 + (maze.getWidth()) * 2,
            std::vector<maze_code>(1 + (maze.getHeight() * 4),
                                   maze_code(maze_code::None)));
        std::cout << "Grid size is" << " " << maze.getWidth() << "x"
                  << maze.getHeight() << std::endl;
        for (int r = 0; r < maze.getHeight(); r++) {
            for (int c = 0; c < maze.getWidth(); c++) {
                std::cout << "maze cell " << r << "," << c << " has size "
                          << maze.maze[r][c].size() << std::endl;
                node_state ns(node_state::all);
                auto template_str = ns.template_from_state();
                std::vector<std::vector<maze_code>> template_maze(
                    template_str.size(),
                    std::vector<maze_code>(template_str[0].size(),
                                           maze_code(maze_code::None)));
                switch (maze.maze[r][c].size()) {
                    case 0:
                        std::cout << "Processing cell " << r << "," << c
                                  << std::endl;
                        for (int i = 0; i < template_str.size(); ++i) {
                            for (int j = 0; j < template_str[i].size(); ++j) {
                                // std::cout << "template_str[" << i << "][" << j << "] = " << template_str[i][j] << std::endl;
                                template_maze[i][j] =
                                    maze_code(maze_code::reverse_reftable.at(
                                        template_str[i][j]));
                            }
                        }
                        copyTemplateToPrinter(printable_grid, template_maze,
                                              2 * r, 4 * c);
                        break;
                }
            }
        }
        for (const auto& row : printable_grid) {
            for (const auto& code : row) {
                std::cout << code.toString();
            }
            std::cout << std::endl;
        }
        // Implementation for printing the grid maze
    }

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