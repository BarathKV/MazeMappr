#ifndef SOLN_CODE_HPP
#define SOLN_CODE_HPP

#include <iostream>
#include <map>
#include <string>

class SolnCode {
   public:
    // enum of the Unicode char as the value word
    enum SolnCodeValue {
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

        // ╔
        Left_Up = Left | Up,  // 0110
        // ╗
        Right_Up = Right | Up,  // 1100
        // ╚
        Left_Down = Left | Down,  // 0011
        // ╝
        Right_Down = Right | Down,  // 1001

        // ═
        Horizontal = Right | Left,  // 1010
        // ║
        Vertical = Up | Down,  // 0101

        // ╦
        Up_Not = Down | Right | Left,  // 1110
        // ╩
        Down_Not = Up | Right | Left,  // 1011
        // ╠
        Left_Not = Right | Down | Up,  // 0111
        // ╣
        Right_Not = Left | Down | Up,  // 1101

        // ╬
        All,  // 1111
    };

    // enum value for the Unicode char
    SolnCodeValue value;

    // Default constructor for Code
    SolnCode() = default;

    // Constructor of Code with a enum value
    SolnCode(const SolnCodeValue avalue) : value(avalue) {}

    //+ operator to add the enum values together
    SolnCode operator+(const SolnCode a) const {};

    //+= operator to add the enum values together
    SolnCode& operator+=(const SolnCode a) {};

    // = operator to set the enum value
    SolnCode& operator=(const SolnCodeValue a) {};

    // Function to convert enum value to unicode char
    std::string toString() const {
        // Check if the value exists in the reference table
        auto it = reftable.find(value);
        if (it != reftable.end()) {
            std::cout << it->second;
            return it->second;
        }
        // Return a default character if not found
        return "?";  // Or any other default value like "unknown"
    }

   private:
    // iterator for the reference table
    static std::map<SolnCodeValue, std::string>::iterator it;

    // reference table for the enum value to Unicode char
    const std::map<SolnCodeValue, std::string> reftable = {
        {SolnCode::None, u8" "},

        {SolnCode::Up, u8"╵"},        {SolnCode::Right, u8"╶"},
        {SolnCode::Down, u8"╷"},      {SolnCode::Left, u8"╴"},

        {SolnCode::Left_Up, u8"╔"},    {SolnCode::Right_Up, u8"╗"},
        {SolnCode::Left_Down, u8"╚"},  {SolnCode::Right_Down, u8"╝"},

        {SolnCode::Horizontal, u8"═"}, {SolnCode::Vertical, u8"║"},

        {SolnCode::Up_Not, u8"╦"},     {SolnCode::Down_Not, u8"╩"},
        {SolnCode::Left_Not, u8"╠"},   {SolnCode::Right_Not, u8"╣"},

        {SolnCode::All, u8"╬"}};
};

#endif