#include "printer.hpp"

#include <iostream>
#include <vector>

#include "../maze/grid_maze.hpp"
#include "node_states.hpp"

void copyTemplateToPrinter(
    std::vector<std::vector<MazeCode>>& printable_maze,
    const std::vector<std::vector<MazeCode>>& template_maze,
    int row_offset,
    int col_offset) {
    for (int i = 0; i < template_maze.size(); ++i) {
        for (int j = 0; j < template_maze[i].size(); ++j) {
            printable_maze[row_offset + i][col_offset + j] +=
                template_maze[i][j];
        }
    }
}

#include "maze_code.hpp"

const std::map<std::string, MazeCode::MazeCodeValue>
    MazeCode::reverse_reftable = {
        {u8" ", MazeCode::None},      {u8"╵", MazeCode::Up},
        {u8"╶", MazeCode::Right},     {u8"╷", MazeCode::Down},
        {u8"╴", MazeCode::Left},      {u8"┌", MazeCode::Right_Down},
        {u8"┐", MazeCode::Left_Down}, {u8"└", MazeCode::Right_Up},
        {u8"┘", MazeCode::Left_Up},   {u8"─", MazeCode::Horizontal},
        {u8"│", MazeCode::Vertical},  {u8"┬", MazeCode::notUp},
        {u8"┴", MazeCode::notDown},   {u8"├", MazeCode::notLeft},
        {u8"┤", MazeCode::notRight},  {u8"┼", MazeCode::All}};

NodeState get_nodeState_from_set(std::set<int> connectedSides) {
    NodeState ns(NodeState::none);
    switch (connectedSides.size()) {
        case 0:
            ns = NodeState(NodeState::all);
            break;
        case 1:
            switch (*connectedSides.begin()) {
                case 0:
                    ns = NodeState(NodeState::notn);
                    break;
                case 1:
                    ns = NodeState(NodeState::note);
                    break;
                case 2:
                    ns = NodeState(NodeState::nots);
                    break;
                case 3:
                    ns = NodeState(NodeState::notw);
                    break;
            }
            break;
        case 2:
            if (connectedSides.find(0) != connectedSides.end()) {
                if (connectedSides.find(1) != connectedSides.end()) {
                    ns = NodeState(NodeState::sw);
                } else if (connectedSides.find(2) != connectedSides.end()) {
                    ns = NodeState(NodeState::ew);
                } else if (connectedSides.find(3) != connectedSides.end()) {
                    ns = NodeState(NodeState::se);
                }
            } else if (connectedSides.find(1) != connectedSides.end()) {
                if (connectedSides.find(2) != connectedSides.end()) {
                    ns = NodeState(NodeState::nw);
                } else if (connectedSides.find(3) != connectedSides.end()) {
                    ns = NodeState(NodeState::sn);
                }
            } else if (connectedSides.find(2) != connectedSides.end()) {
                if (connectedSides.find(3) != connectedSides.end()) {
                    ns = NodeState(NodeState::ne);
                }
            }
            break;
        case 3:
            if (connectedSides == std::set<int>({0, 1, 2})) {
                ns = NodeState(NodeState::w);
            } else if (connectedSides == std::set<int>({0, 1, 3})) {
                ns = NodeState(NodeState::s);
            } else if (connectedSides == std::set<int>({0, 2, 3})) {
                ns = NodeState(NodeState::e);
            } else if (connectedSides == std::set<int>({1, 2, 3})) {
                ns = NodeState(NodeState::n);
            }
            break;
        default:
            ns = NodeState(NodeState::none);
            break;
    }
    return ns;
}

void Printer::print(const GridMaze& maze) const {
    // std::cout << "Printing grid maze..." << std::endl;
    std::vector<std::vector<MazeCode>> printable_grid;
    printable_grid.resize(1 + (maze.getWidth()) * 2,
                          std::vector<MazeCode>(1 + (maze.getHeight() * 4),
                                                 MazeCode(MazeCode::None)));
    // std::cout << "Grid size is" << " " << maze.getWidth() << "x"
    //           << maze.getHeight() << std::endl;
    for (int r = 0; r < maze.getHeight(); r++) {
        for (int c = 0; c < maze.getWidth(); c++) {
            // std::cout << "maze cell " << r << "," << c << " has size "
            //           << maze.maze[r][c].size() << std::endl;
            NodeState ns(NodeState::none);
            ns = get_nodeState_from_set(maze.maze[r][c]);
            // std::cout << "Node state for cell " << r << "," << c << " is "
            //           << ns.stateValue << std::endl;
            std::vector<std::vector<std::string>> template_str =
                ns.template_from_state();
            std::vector<std::vector<MazeCode>> template_maze(
                template_str.size(),
                std::vector<MazeCode>(template_str[0].size(),
                                       MazeCode(MazeCode::None)));
            // std::cout << "Processing cell " << r << "," << c << std::endl;
            for (int i = 0; i < template_str.size(); ++i) {
                for (int j = 0; j < template_str[i].size(); ++j) {
                    // std::cout << "template_str[" << i << "][" << j
                    //           << "] = " << template_str[i][j] << std::endl;
                    template_maze[i][j] = MazeCode(
                        MazeCode::reverse_reftable.at(template_str[i][j]));
                }
            }
            // std::cout << "Copying template to printable grid at " << 2 * r
            //           << "," << 4 * c << std::endl;
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


void Printer::print(const GridSoln& solution) const {
    std::cout << "Printing solution..." << std::endl;
    for (const auto& row : solution.grid) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}