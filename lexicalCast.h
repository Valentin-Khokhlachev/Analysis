#ifndef LEXICALCAST_H
#define LEXICALCAST_H

#include <string>
#include <sstream>

namespace lexicalCast {

template <typename T>
std::string toString(const T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
    std::istringstream iss(s);
    T res;
    iss >> res;
    return res;
}

};

#endif // LEXICALCAST_H
