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

    Token *ReadNextToken();

private:
    std::string content;

    bool endOfFileIsReached;

    unsigned long currentReaderPosition;

    char currentCharacter;

    void PollCharacter();

    char PeekCharacter();

    char ReadCharacter(unsigned long position);

    Token *ReadIntegerToken();

    Token *ReadAlphabeticToken();

    Token *ReadEqualityToken();

    Token *ReadNegationToken();

    Token *ReadString();

    Token *ReadSmallerToken();

    Token *ReadGreaterToken();
};


#endif //PRINCEPT_LEXER_H
