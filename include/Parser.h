//
// Created by Felix Klauke on 29.03.18.
//

#ifndef PRINCEPT_PARSER_H
#define PRINCEPT_PARSER_H


#include "Lexer.h"

class Parser {

public:
    explicit Parser(const Lexer &lexer);

    void parse();

private:
    Lexer lexer;

};


#endif //PRINCEPT_PARSER_H
