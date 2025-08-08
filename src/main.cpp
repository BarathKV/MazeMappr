#include "maze/grid_maze.h"
#include "printer/maze_code.h"
#include "printer/printer.h"

#include "maze/grid_maze_gen.h"

int main() {
    std::cout << "Maze Code Example:" << std::endl;
    grid_maze maze = grid_maze(10,10);
    // maze.maze[0][0].insert(1);
    // maze.maze[0][1].insert(3);
    // maze.maze[1][0].insert(0);
    // maze.maze[0][0].insert(2);
    randDFSGeneration(maze);
    Printer printer;
    printer.print(maze);
    return 0;
}