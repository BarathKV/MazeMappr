#ifndef SOLN_CODE_H
#define SOLN_CODE_H

#include <iostream>
#include <map>
#include <string>

class Soln_code {
   public:
    // enum of the Unicode char as the value word
    enum Soln_Code_Value {
        //" "
        None,

        // ╔
        Left_Top,
        // ╗
        Right_Top,
        // ╚
        Left_Bottom,
        // ╝
        Right_Bottom,

        // ═
        Horizontal,
        // ║
        Vertical,

        // ╦
        Top_Not,
        // ╩
        Bottom_Not,
        // ╠
        Left_Not,
        // ╣
        Right_Not,

        // ╬
        All,
    };

    // enum value for the Unicode char
    Soln_Code_Value value;

    // Default constructor for Code
    Soln_code() = default;

    // Constructor of Code with a enum value
    Soln_code(const Soln_Code_Value avalue) : value(avalue) {}

    //+ operator to add the enum values together
    Soln_code operator+(const Soln_code a) const {};

    //+= operator to add the enum values together
    Soln_code& operator+=(const Soln_code a) {};

    // = operator to set the enum value
    Soln_code& operator=(const Soln_Code_Value a) {};

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
    static std::map<Soln_Code_Value, std::string>::iterator it;

    // reference table for the enum value to Unicode char
    const std::map<Soln_Code_Value, std::string> reftable = {
        {Soln_code::None, u8" "},

        {Soln_code::Left_Top, u8"╔"},    {Soln_code::Right_Top, u8"╗"},
        {Soln_code::Left_Bottom, u8"╚"}, {Soln_code::Right_Bottom, u8"╝"},

        {Soln_code::Horizontal, u8"═"},  {Soln_code::Vertical, u8"║"},

        {Soln_code::Top_Not, u8"╦"},     {Soln_code::Bottom_Not, u8"╩"},
        {Soln_code::Left_Not, u8"╠"},    {Soln_code::Right_Not, u8"╣"},

        {Soln_code::All, u8"╬"}};
};

#endif