#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <cstdlib>

// Enum class representing the four cardinal directions
enum class Direction {
    North = 0,
    East = 1,
    South = 2,
    West = 3,
};

// Function to generate a random direction
// Returns an integer between 0 and 3, representing North, East, South, or West
int generateRandomDirection() {
    return rand() % 4;
}

#endif
