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

        {SolnCode::Left_Top, u8"╔"},    {SolnCode::Right_Top, u8"╗"},
        {SolnCode::Left_Bottom, u8"╚"}, {SolnCode::Right_Bottom, u8"╝"},

        {SolnCode::Horizontal, u8"═"},  {SolnCode::Vertical, u8"║"},

        {SolnCode::Top_Not, u8"╦"},     {SolnCode::Bottom_Not, u8"╩"},
        {SolnCode::Left_Not, u8"╠"},    {SolnCode::Right_Not, u8"╣"},

        {SolnCode::All, u8"╬"}};
};

#endif