#ifndef NODE_STATES_H
#define NODE_STATES_H

#include <map>
#include <vector>
#include "maze_code.h"

class node_state {
   public:
    // Enum representing the state of a node in the maze
    enum node_state_value {
        none = 0,            // 0000
        n = 1 << 0,          // 0001
        e = 1 << 1,          // 0010
        s = 1 << 2,          // 0100
        w = 1 << 3,          // 1000
        nw = n | w,          // 1001
        ne = n | e,          // 0011
        sw = s | w,          // 1100
        se = s | e,          // 0110
        sn = s | n,          // 0101
        ew = e | w,          // 1010
        notn = ~n,           // 1110
        note = ~e,           // 1101
        nots = ~s,           // 1011
        notw = ~w,           // 0111
        all = n | e | s | w  // 1111
    };

    node_state_value stateValue;

    node_state() = default;

    node_state(const node_state_value astate) : stateValue(astate) {}

    node_state& operator+=(const node_state_value astate) {
        stateValue = static_cast<node_state_value>(stateValue | astate);
        return *this;
    }

    // node_state& operator-=(const node_state_value astate) {
    //     stateValue = static_cast<node_state_value>(stateValue & ~astate);
    //     return *this;
    // }

    node_state operator+(const node_state_value astate) const {
        return node_state(static_cast<node_state_value>(stateValue | astate));
    }

    // node_state operator-(const node_state_value astate) const {
    //     return node_state(static_cast<node_state_value>(stateValue & ~astate));
    // }

    std::vector<std::vector<std::string>> template_from_state() {
        switch (stateValue) {
            case n:
                return {{"╶", "─", "─", "─", "╴"},  // ╶───╴
                        {" ", " ", " ", " ", " "},  //      
                        {" ", " ", " ", " ", " "}}; //      
            case e:
                return {{" ", " ", " ", " ", "╷"},  //     ╷
                        {" ", " ", " ", " ", "│"},  //     │
                        {" ", " ", " ", " ", "╵"}}; //     ╵
            case s:
                return {{" ", " ", " ", " ", " "},  //      
                        {" ", " ", " ", " ", " "},  //      
                        {"╶", "─", "─", "─", "╴"}}; // ╶───╴
            case w:
                return {{"╷", " ", " ", " ", " "},  // ╷    
                        {"│", " ", " ", " ", " "},  // │    
                        {"╵", " ", " ", " ", " "}}; // ╵    
            case nw:
                return {{"┌", "─", "─", "─", "╴"},  // ┌───╴
                        {"│", " ", " ", " ", " "},  // │    
                        {"╵", " ", " ", " ", " "}}; // ╵    
            case ne:
                return {{"╶", "─", "─", "─", "┐"},  // ╶───┐
                        {" ", " ", " ", " ", "│"},  //     │
                        {" ", " ", " ", " ", "╵"}}; //     ╵
            case sw:
                return {{"╷", " ", " ", " ", " "},  // ╷    
                        {"│", " ", " ", " ", " "},  // │    
                        {"└", "─", "─", "─", "─"}}; // └───╴
            case se:
                return {{" ", " ", " ", " ", "╷"},  //     ╷
                        {" ", " ", " ", " ", "│"},  //     │
                        {"╶", "─", "─", "─", "┘"}}; // ╶───┘
            case sn:
                return {{"╶", "─", "─", "─", "╴"},  // ╶───╴
                        {" ", " ", " ", " ", " "},  //
                        {"╶", "─", "─", "─", "╴"}}; // ╶───╴
            case ew:
                return {{"╷", " ", " ", " ", "╷"},  // ╷   ╷
                        {"│", " ", " ", " ", "│"},  // │   │
                        {"╵", " ", " ", " ", "╵"}}; // ╵   ╵
            case notn:
                return {{"╷", " ", " ", " ", "╷"},  // ╷   ╷
                        {"│", " ", " ", " ", "│"},  // │   │
                        {"└", "─", "─", "─", "┘"}}; // └───┘
            case note:
                return {{"┌", "─", "─", "─", "╴"},  // ┌───╴
                        {"│", " ", " ", " ", " "},  // │    
                        {"└", "─", "─", "─", "╴"}}; // └───╴
            case nots:
                return {{"┌", "─", "─", "─", "┐"},  // ┌───┐
                        {"│", " ", " ", " ", "│"},  // │   │
                        {"╵", " ", " ", " ", "╵"}}; // ╵   ╵
            case notw:
                return {{"╶", "─", "─", "─", "┐"},  // ╶───┐
                        {" ", " ", " ", " ", "│"},  //     │
                        {"╶", "─", "─", "─", "┘"}}; // ╶───┘
            case all:
                return {{"┌", "─", "─", "─", "┐"},  // ┌───┐
                        {"│", " ", " ", " ", "│"},  // │   │
                        {"└", "─", "─", "─", "┘"}}; // └───┘
            default:
                return {{" ", " ", " ", " ", " "},  // ┌───┐
                        {" ", " ", " ", " ", " "},  // │   │
                        {" ", " ", " ", " ", " "}}; // └───┘
        }
    }
};

#endif