//
// Created by Felix Klauke on 23.02.18.
//

#include "Lexer.h"

Lexer::Lexer(const std::string &content) : content(content) {

}

Token Lexer::readNextToken() {
    peekCharacter();

    if (endOfFileIsReached) {
        return Token("END_OF_FILE", TokenType::END_OF_FILE);
    }
    pollCharacter();

    if (iswspace(currentCharacter)) {
        return readNextToken();
    }

    if (currentCharacter == '{') {
        return Token("{", TokenType::LEFT_CURLY_BRACE);
    } else if (currentCharacter == '}') {
        return Token("}", TokenType::RIGHT_CURLY_BRACE);
    } else if (currentCharacter == '(') {
        return Token("(", TokenType::LEFT_BRACE);
    } else if (currentCharacter == ')') {
        return Token(")", TokenType::RIGHT_BRACE);
    } else if (currentCharacter == '+') {
        return Token("+", TokenType::PLUS);
    } else if (currentCharacter == '-') {
        return Token("-", TokenType::MINUS);
    }

    return Token("UNKNOWN", TokenType::UNKNOWN);
}

void Lexer::pollCharacter() {
    currentCharacter = readCharacter(currentReaderPosition);
    currentReaderPosition++;
}

char Lexer::peekCharacter() {
    return readCharacter(currentReaderPosition + 1);
}

char Lexer::readCharacter(unsigned long position) {
    if (position == content.size() - 1) {
        endOfFileIsReached = true;
        return 0;
    }

    return content.at(position);
}
