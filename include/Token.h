//
// Created by Felix Klauke on 12.03.18.
//

#ifndef PRINCEPT_TOKEN_H
#define PRINCEPT_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {

private:
    std::string content;

    TokenType tokenType;

public:
    explicit Token(const std::string &content, TokenType tokenType);

    std::string GetValue();

    TokenType GetTokenType();

};


#endif //PRINCEPT_TOKEN_H
