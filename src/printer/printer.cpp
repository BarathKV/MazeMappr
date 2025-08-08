#include "printer.h"

// #include <grid_maze.h>
// #include <soln_code.h>

#include <iostream>
#include <vector>

#include "../maze/grid_maze.h"
#include "node_states.h"

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

#include "maze_code.h"

const std::map<std::string, maze_code::maze_code_value>
    maze_code::reverse_reftable = {
        {u8" ", maze_code::None},      {u8"╵", maze_code::Up},
        {u8"╶", maze_code::Right},     {u8"╷", maze_code::Down},
        {u8"╴", maze_code::Left},      {u8"┌", maze_code::Right_Down},
        {u8"┐", maze_code::Left_Down}, {u8"└", maze_code::Right_Up},
        {u8"┘", maze_code::Left_Up},   {u8"─", maze_code::Horizontal},
        {u8"│", maze_code::Vertical},  {u8"┬", maze_code::notUp},
        {u8"┴", maze_code::notDown},   {u8"├", maze_code::notLeft},
        {u8"┤", maze_code::notRight},  {u8"┼", maze_code::All}};

node_state get_nodeState_from_set(std::set<int> connectedSides) {
    node_state ns(node_state::none);
    switch (connectedSides.size()) {
        case 0:
            ns = node_state(node_state::all);
            break;
        case 1:
            switch (*connectedSides.begin()) {
                case 0:
                    ns = node_state(node_state::notn);
                    break;
                case 1:
                    ns = node_state(node_state::note);
                    break;
                case 2:
                    ns = node_state(node_state::nots);
                    break;
                case 3:
                    ns = node_state(node_state::notw);
                    break;
            }
            break;
        case 2:
            if (connectedSides.find(0) != connectedSides.end()) {
                if (connectedSides.find(1) != connectedSides.end()) {
                    ns = node_state(node_state::sw);
                } else if (connectedSides.find(2) != connectedSides.end()) {
                    ns = node_state(node_state::ew);
                } else if (connectedSides.find(3) != connectedSides.end()) {
                    ns = node_state(node_state::se);
                }
            } else if (connectedSides.find(1) != connectedSides.end()) {
                if (connectedSides.find(2) != connectedSides.end()) {
                    ns = node_state(node_state::nw);
                } else if (connectedSides.find(3) != connectedSides.end()) {
                    ns = node_state(node_state::sn);
                }
            } else if (connectedSides.find(2) != connectedSides.end()) {
                if (connectedSides.find(3) != connectedSides.end()) {
                    ns = node_state(node_state::ne);
                }
            }
            break;
        case 3:
            if (connectedSides == std::set<int>({0, 1, 2})) {
                ns = node_state(node_state::w);
            } else if (connectedSides == std::set<int>({0, 1, 3})) {
                ns = node_state(node_state::s);
            } else if (connectedSides == std::set<int>({0, 2, 3})) {
                ns = node_state(node_state::e);
            } else if (connectedSides == std::set<int>({1, 2, 3})) {
                ns = node_state(node_state::n);
            }
            break;
        default:
            ns = node_state(node_state::none);
            break;
    }
    return ns;
}

void Printer::print(const grid_maze& maze) const {
    std::cout << "Printing grid maze..." << std::endl;
    std::vector<std::vector<maze_code>> printable_grid;
    printable_grid.resize(1 + (maze.getWidth()) * 2,
                          std::vector<maze_code>(1 + (maze.getHeight() * 4),
                                                 maze_code(maze_code::None)));
    std::cout << "Grid size is" << " " << maze.getWidth() << "x"
              << maze.getHeight() << std::endl;
    for (int r = 0; r < maze.getHeight(); r++) {
        for (int c = 0; c < maze.getWidth(); c++) {
            std::cout << "maze cell " << r << "," << c << " has size "
                      << maze.maze[r][c].size() << std::endl;
            node_state ns(node_state::none);
            ns = get_nodeState_from_set(maze.maze[r][c]);
            std::vector<std::vector<std::string>> template_str =
                ns.template_from_state();
            std::vector<std::vector<maze_code>> template_maze(
                template_str.size(),
                std::vector<maze_code>(template_str[0].size(),
                                       maze_code(maze_code::None)));
            std::cout << "Processing cell " << r << "," << c << std::endl;
            for (int i = 0; i < template_str.size(); ++i) {
                for (int j = 0; j < template_str[i].size(); ++j) {
                    // std::cout << "template_str[" << i << "][" << j <<
                    // "] = " << template_str[i][j] << std::endl;
                    template_maze[i][j] = maze_code(
                        maze_code::reverse_reftable.at(template_str[i][j]));
                }
            }
            copyTemplateToPrinter(printable_grid, template_maze, 2 * r, 4 * c);
        }
    }
    for (const auto& row : printable_grid) {
        for (const auto& code : row) {
            std::cout << code.toString();
        }
        std::cout << std::endl;
    }
}