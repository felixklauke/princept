//
// Created by Felix Klauke on 12.03.18.
//

#include "Token.h"

Token::Token(std::string *value, TokenType tokenType) : content(value), tokenType(tokenType) {

}

std::string Token::getValue() {
    return *content;
}

TokenType Token::getTokenType() {
    return tokenType;
}
