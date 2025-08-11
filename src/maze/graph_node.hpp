#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP

#include <map>
#include "direction.hpp"

class GraphNode {
    // store x and y coord
    int x, y;

   public:
    // Constructor for GraphNode with x and y co-ords
    GraphNode(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    // map of direction as int and adjacent GraphNode
    std::map<Direction, GraphNode*> ConnectedGNodes;

    // func to connect this and other node
    void connect(GraphNode* other) {};

    // func to disconnect this and other node
    void disconnect(GraphNode* other) {};
};

#endif