#ifndef EX05_CPP_INVALIDINPUT_H
#define EX05_CPP_INVALIDINPUT_H

#include <iostream>

class InvalidInput : public std::invalid_argument {
public:
    explicit InvalidInput(const std::string &str) : std::invalid_argument(str) {};
};


#endif //EX05_CPP_INVALIDINPUT_H
