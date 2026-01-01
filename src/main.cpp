#include <string>

#include "maze/grid_maze.hpp"
#include "printer/maze_code.hpp"
#include "printer/printer.hpp"
#include "solution/grid_soln.hpp"

#include "maze/grid_maze_gen.hpp"
#include "solution/grid_soln_gen.hpp"

//! FOR WINDOWS SYSTEM UNCOMMENT
// #include <windows.h>

int main(int argc, char** argv) {
    //! FOR WINDOWS SYSTEM UNCOMMENT
    // SetConsoleOutputCP(CP_UTF8);

    if (argc < 2)std::cout << "Mention size of maze as argv"<<std::endl;
    std::cout << argv[1] << std::endl;

    std::cout << "Maze Code Example:" << std::endl;
    GridMaze maze = GridMaze(std::stoi(argv[1]),std::stoi(argv[1]));
    randDFSGeneration(maze);
    Printer printer;
    printer.print(maze);

    // std::cout << "Maze Solution Example:" << std::endl;
    // GridSoln soln(maze);
    // randomMouseSolnGen(soln);
    // printer.print(soln);
    return 0;
}