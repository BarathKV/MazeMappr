#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <map>
#include <direction.h>

class graph_node {
    // store x and y coord
    int x, y;

   public:
    // Constructor for graph_node with x and y co-ords
    graph_node(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    // map of direction as int and adjacent graph_node
    std::map<Direction, graph_node*> ConnectedGNodes;

    // func to connect this and other node
    void connect(graph_node* other) {};

    // func to disconnect this and other node
    void disconnect(graph_node* other) {};
};

#endif