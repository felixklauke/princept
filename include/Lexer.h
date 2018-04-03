//
// Created by Felix Klauke on 23.02.18.
//

#ifndef PRINCEPT_LEXER_H
#define PRINCEPT_LEXER_H


#include <string>
#include "Token.h"

class Lexer {

public:
    explicit Lexer(const std::string &content);

    Token readNextToken();

private:
    std::string content;

    bool endOfFileIsReached;

    unsigned long currentReaderPosition;

    char currentCharacter;

    void pollCharacter();

    char peekCharacter();

    char readCharacter(unsigned long position);

    std::string readIntegerToken();
};


#endif //PRINCEPT_LEXER_H
