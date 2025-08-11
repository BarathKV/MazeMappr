#ifndef NODE_STATES_HPP
#define NODE_STATES_HPP

#include <map>
#include <vector>
#include "maze_code.hpp"

class NodeState {
   public:
    // Enum representing the state of a node in the maze
    enum NodeStateValue {
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
        notn = e | s | w,    // 1110
        note = n | s | w,    // 1101
        nots = n | e | w,    // 1011
        notw = n | e | s,    // 0111
        all = n | e | s | w  // 1111
    };

    NodeStateValue stateValue;

    NodeState() = default;

    NodeState(const NodeStateValue astate) : stateValue(astate) {}

    NodeState& operator+=(const NodeStateValue astate) {
        stateValue = static_cast<NodeStateValue>(stateValue | astate);
        return *this;
    }

    // NodeState& operator-=(const NodeStateValue astate) {
    //     stateValue = static_cast<NodeStateValue>(stateValue & ~astate);
    //     return *this;
    // }

    NodeState operator+(const NodeStateValue astate) const {
        return NodeState(static_cast<NodeStateValue>(stateValue | astate));
    }

    // NodeStateperator-(const NodeStateValue astate) const {
    //     return NodeState(static_cast<NodeStateValue>(stateValue & ~astate));
    // }

    std::vector<std::vector<std::string>> template_from_state() {
        switch (stateValue) {
            case n:
                return {{u8"╶", u8"─", u8"─", u8"─", u8"╴"},  // ╶───╴
                        {u8" ", u8" ", u8" ", u8" ", u8" "},  //      
                        {u8" ", u8" ", u8" ", u8" ", u8" "}}; //      
            case e:
                return {{u8" ", u8" ", u8" ", u8" ", u8"╷"},  //     ╷
                        {u8" ", u8" ", u8" ", u8" ", u8"│"},  //     │
                        {u8" ", u8" ", u8" ", u8" ", u8"╵"}}; //     ╵
            case s:
                return {{u8" ", u8" ", u8" ", u8" ", u8" "},  //      
                        {u8" ", u8" ", u8" ", u8" ", u8" "},  //      
                        {u8"╶", u8"─", u8"─", u8"─", u8"╴"}}; // ╶───╴
            case w:
                return {{u8"╷", u8" ", u8" ", u8" ", u8" "},  // ╷    
                        {u8"│", u8" ", u8" ", u8" ", u8" "},  // │    
                        {u8"╵", u8" ", u8" ", u8" ", u8" "}}; // ╵    
            case nw:
                return {{u8"┌", u8"─", u8"─", u8"─", u8"╴"},  // ┌───╴
                        {u8"│", u8" ", u8" ", u8" ", u8" "},  // │    
                        {u8"╵", u8" ", u8" ", u8" ", u8" "}}; // ╵    
            case ne:
                return {{u8"╶", u8"─", u8"─", u8"─", u8"┐"},  // ╶───┐
                        {u8" ", u8" ", u8" ", u8" ", u8"│"},  //     │
                        {u8" ", u8" ", u8" ", u8" ", u8"╵"}}; //     ╵
            case sw:
                return {{u8"╷", u8" ", u8" ", u8" ", u8" "},  // ╷    
                        {u8"│", u8" ", u8" ", u8" ", u8" "},  // │    
                        {u8"└", u8"─", u8"─", u8"─", u8"─"}}; // └───╴
            case se:
                return {{u8" ", u8" ", u8" ", u8" ", u8"╷"},  //     ╷
                        {u8" ", u8" ", u8" ", u8" ", u8"│"},  //     │
                        {u8"╶", u8"─", u8"─", u8"─", u8"┘"}}; // ╶───┘
            case sn:
                return {{u8"╶", u8"─", u8"─", u8"─", u8"╴"},  // ╶───╴
                        {u8" ", u8" ", u8" ", u8" ", u8" "},  //
                        {u8"╶", u8"─", u8"─", u8"─", u8"╴"}}; // ╶───╴
            case ew:
                return {{u8"╷", u8" ", u8" ", u8" ", u8"╷"},  // ╷   ╷
                        {u8"│", u8" ", u8" ", u8" ", u8"│"},  // │   │
                        {u8"╵", u8" ", u8" ", u8" ", u8"╵"}}; // ╵   ╵
            case notn:
                return {{u8"╷", u8" ", u8" ", u8" ", u8"╷"},  // ╷   ╷
                        {u8"│", u8" ", u8" ", u8" ", u8"│"},  // │   │
                        {u8"└", u8"─", u8"─", u8"─", u8"┘"}}; // └───┘
            case note:
                return {{u8"┌", u8"─", u8"─", u8"─", u8"╴"},  // ┌───╴
                        {u8"│", u8" ", u8" ", u8" ", u8" "},  // │
                        {u8"└", u8"─", u8"─", u8"─", u8"╴"}}; // └───╴
            case nots:
                return {{u8"┌", u8"─", u8"─", u8"─", u8"┐"},  // ┌───┐
                        {u8"│", u8" ", u8" ", u8" ", u8"│"},  // │   │
                        {u8"╵", u8" ", u8" ", u8" ", u8"╵"}}; // ╵   ╵
            case notw:
                return {{u8"╶", u8"─", u8"─", u8"─", u8"┐"},  // ╶───┐
                        {u8" ", u8" ", u8" ", u8" ", u8"│"},  //     │
                        {u8"╶", u8"─", u8"─", u8"─", u8"┘"}}; // ╶───┘
            case all:
                return {{u8"┌", u8"─", u8"─", u8"─", u8"┐"},  // ┌───┐
                        {u8"│", u8" ", u8" ", u8" ", u8"│"},  // │   │
                        {u8"└", u8"─", u8"─", u8"─", u8"┘"}}; // └───┘
            default:
                return {{u8" ", u8" ", u8" ", u8" ", u8" "},  // ┌───┐
                        {u8" ", u8" ", u8" ", u8" ", u8" "},  // │   │
                        {u8" ", u8" ", u8" ", u8" ", u8" "}}; // └───┘
        }
    }
};

#endif