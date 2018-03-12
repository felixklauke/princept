//
// Created by Felix Klauke on 12.03.18.
//

#ifndef PRINCEPT_TOKEN_H
#define PRINCEPT_TOKEN_H


#include <string>

class Token {
private:
    std::string content;

public:
    explicit Token(std::string content);

    std::string getValue();
};


#endif //PRINCEPT_TOKEN_H
