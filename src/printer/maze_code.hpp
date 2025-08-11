#ifndef MAZE_CODE_HPP
#define MAZE_CODE_HPP

#include <iostream>
#include <map>
#include <string>

class MazeCode {
   public:
    // enum of the Unicode char as the value word
    enum MazeCodeValue {
        //" "
        None,  // 0000
        // ╵
        Up = 1 << 0,  // 0001
        // ╶
        Right = 1 << 1,  // 0010
        // ╷
        Down = 1 << 2,  // 0100
        // ╴
        Left = 1 << 3,  // 1000
        // ┌
        Right_Down = Right | Down,  // 0110
        // ┐
        Left_Down = Left | Down,  // 1100
        // └
        Right_Up = Right | Up,  // 0011
        // ┘
        Left_Up = Left | Up,  // 1001
        // ─
        Horizontal = Left | Right,  // 1010
        // │
        Vertical = Up | Down,  // 0101
        // ┬
        notUp = Left | Down | Right,  // 1110
        // ┴
        notDown = Up | Right | Left,  // 1011
        // ├
        notLeft = Up | Down | Right,  // 0111
        // ┤
        notRight = Up | Down | Left,  // 1101
        // ┼
        All = Up | Down | Left | Right  // 1111
    };

    // enum value for the Unicode char
    MazeCodeValue value;

    // Default constructor for Code
    MazeCode() = default;

    // Constructor of Code with a enum value
    MazeCode(const MazeCodeValue avalue) : value(avalue) {}

    //+= operator to add the enum values together
    MazeCode& operator+=(const MazeCode& other) {
        value = static_cast<MazeCodeValue>(value | other.value);
        return *this;
    }

    //+ operator to add the enum values together
    MazeCode operator+(const MazeCode& other) const {
        return MazeCode(static_cast<MazeCodeValue>(value | other.value));
    }

    // = operator to set the enum value
    MazeCode& operator=(const MazeCodeValue a) {
        value = a;
        return *this;
    };

    // Function to convert enum value to unicode char
    std::string toString() const {
        // Check if the value exists in the reference table
        auto it = reftable.find(value);
        if (it != reftable.end()) {
            return it->second;
        }
        return u8"?";
    }

    // iterator for the reference table
    // static std::map<MazeCodeValue, std::string>::iterator it;

    // reference table for the enum value to Unicode char
    std::map<MazeCodeValue, std::string> reftable = {
        {None, u8" "},

        {Up, u8"╵"},         {Right, u8"╶"},
        {Down, u8"╷"},       {Left, u8"╴"},

        {Right_Down, u8"┌"}, {Left_Down, u8"┐"},
        {Right_Up, u8"└"},   {Left_Up, u8"┘"},

        {Horizontal, u8"─"}, {Vertical, u8"│"},

        {notUp, u8"┬"},      {notDown, u8"┴"},
        {notLeft, u8"├"},    {notRight, u8"┤"},

        {All, u8"┼"}};

    static const std::map<std::string, MazeCode::MazeCodeValue>
        reverse_reftable;
};
#endif
