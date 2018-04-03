//
// Created by Felix Klauke on 23.02.18.
//

#include <iostream>
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
        return Token(std::string(1, currentCharacter), TokenType::LEFT_CURLY_BRACE);
    } else if (currentCharacter == '}') {
        return Token(std::string(1, currentCharacter), TokenType::RIGHT_CURLY_BRACE);
    } else if (currentCharacter == '(') {
        return Token(std::string(1, currentCharacter), TokenType::LEFT_BRACE);
    } else if (currentCharacter == ')') {
        return Token(std::string(1, currentCharacter), TokenType::RIGHT_BRACE);
    } else if (currentCharacter == '+') {
        return Token(std::string(1, currentCharacter), TokenType::PLUS);
    } else if (currentCharacter == '-') {
        return Token(std::string(1, currentCharacter), TokenType::MINUS);
    } else if (isdigit(currentCharacter)) {
        return readIntegerToken();
    } else if (isalpha(currentCharacter)) {
        return readAlphabeticToken();
    }

    return Token("UNKNOWN", TokenType::UNKNOWN);
}

void Lexer::pollCharacter() {
    currentCharacter = readCharacter(currentReaderPosition);
    currentReaderPosition++;
}

char Lexer::peekCharacter() {
    return readCharacter(currentReaderPosition);
}

char Lexer::readCharacter(unsigned long position) {
    if (position >= content.size()) {
        endOfFileIsReached = true;
        return 0;
    }

    return content.at(position);
}

Token Lexer::readIntegerToken() {
    std::string current;

    while (isdigit(currentCharacter)) {
        pollCharacter();
        current += currentCharacter;
    }

    return Token(current, TokenType::INTEGER);
}

Token Lexer::readAlphabeticToken() {
    std::string current;

    while (isalpha(currentCharacter)) {
        current += currentCharacter;

        if (!isalpha(peekCharacter())) {
            break;
        }

        pollCharacter();
    }

    if (current == "class") {
        return Token(current, TokenType::CLASS);
    }

    if (current == "function") {
        return Token(current, TokenType::FUNCTION);
    }

    if (current == "true" || current == "false") {
        return Token(current, TokenType::BOOL);
    }

    return Token(current, TokenType::LABEL);
}
