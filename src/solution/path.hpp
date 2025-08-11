#ifndef PATH_HPP
#define PATH_HPP

#include <map>
#include "direction.hpp"

class Path {
    // store x and y coord
    int x, y;

   public:
    // Constructor for Node with x and y co-ords
    Path(const int x, const int y) {
        this->x = x;
        this->y = y;
        this->next = nullptr;
    }

    Path(const int x, const int y, Path* next) {
        this->x = x;
        this->y = y;
        this->next = next;
    }

    // next co ordinate in the path
    Path* next;

    // func to connect this and other node
    void connect(Path* other) {};

    // func to disconnect this and other node
    void disconnect(Path* other) {};
};

#endif