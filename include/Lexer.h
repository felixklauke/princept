//
// Created by Felix Klauke on 23.02.18.
//

#ifndef PRINCEPT_LEXER_H
#define PRINCEPT_LEXER_H


#include <string>

class Lexer {
public:
    explicit Lexer(const std::string &content);

private:
    std::string content;
};


#endif //PRINCEPT_LEXER_H
