#include "maze/grid_maze.hpp"
#include "printer/maze_code.hpp"
#include "printer/printer.hpp"
#include "solution/grid_soln.hpp"

#include "maze/grid_maze_gen.hpp"
#include "solution/grid_soln_gen.hpp"

#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Maze Code Example:" << std::endl;
    GridMaze maze = GridMaze(10,10);
    randDFSGeneration(maze);
    Printer printer;
    printer.print(maze);

    std::cout << "Maze Solution Example:" << std::endl;
    GridSoln soln(maze);
    randomMouseSolnGen(soln);
    printer.print(soln);
    return 0;
}