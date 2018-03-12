//
// Created by Felix Klauke on 12.03.18.
//

#include "Token.h"

Token::Token(std::string value) : content(value) {

}

std::string Token::getValue() {
    return content;
}
