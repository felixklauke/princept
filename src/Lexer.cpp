//
// Created by Felix Klauke on 23.02.18.
//

#include <iostream>
#include "Lexer.h"

Lexer::Lexer(const std::string &content) : content(content) {

}

Token *Lexer::readNextToken() {
    peekCharacter();

    if (endOfFileIsReached) {
        return new Token("END_OF_FILE", TokenType::END_OF_FILE);
    }

    pollCharacter();

    if (iswspace(currentCharacter)) {
        return readNextToken();
    }

    if (isalpha(currentCharacter)) {
        return readAlphabeticToken();
    }

    if (isdigit(currentCharacter)) {
        return readIntegerToken();
    }

    if (currentCharacter == '{') {
        return new Token(std::string(1, currentCharacter), TokenType::LEFT_CURLY_BRACE);
    } else if (currentCharacter == '}') {
        return new Token(std::string(1, currentCharacter), TokenType::RIGHT_CURLY_BRACE);
    } else if (currentCharacter == '(') {
        return new Token(std::string(1, currentCharacter), TokenType::LEFT_BRACE);
    } else if (currentCharacter == ')') {
        return new Token(std::string(1, currentCharacter), TokenType::RIGHT_BRACE);
    } else if (currentCharacter == '+') {
        return new Token(std::string(1, currentCharacter), TokenType::PLUS);
    } else if (currentCharacter == '-') {
        return new Token(std::string(1, currentCharacter), TokenType::MINUS);
    } else if (currentCharacter == '.') {
        return new Token(std::string(1, currentCharacter), TokenType::DOT);
    } else if (currentCharacter == '<') {
        return readSmallerToken();
    } else if (currentCharacter == '>') {
        return readGreaterToken();
    } else if (currentCharacter == '=') {
        return readEqualityToken();
    } else if (currentCharacter == '"') {
        return readString();
    } else if (currentCharacter == '!') {
        return readNegationToken();
    }

    return new Token("UNKNOWN", TokenType::UNKNOWN);
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

Token *Lexer::readIntegerToken() {
    std::string current;

    while (isdigit(currentCharacter)) {
        current += currentCharacter;

        if (!isdigit(peekCharacter())) {
            break;
        }

        pollCharacter();
    }

    return new Token(current, TokenType::INTEGER);
}

Token *Lexer::readAlphabeticToken() {
    std::string current;

    while (isalpha(currentCharacter) || isdigit(currentCharacter)) {
        current += currentCharacter;

        if (!isalpha(peekCharacter())) {
            break;
        }

        pollCharacter();
    }

    if (current == "class") {
        return new Token(current, TokenType::CLASS);
    }

    if (current == "function") {
        return new Token(current, TokenType::FUNCTION);
    }

    if (current == "true" || current == "false") {
        return new Token(current, TokenType::BOOL);
    }

    if (current == "for") {
        return new Token(current, TokenType::FOR);
    }

    if (current == "while") {
        return new Token(current, TokenType::WHILE);
    }

    if (current == "return") {
        return new Token(current, TokenType::RETURN);
    }

    if (current == "if") {
        return new Token(current, TokenType::IF);
    }

    if (current == "else") {
        return new Token(current, TokenType::ELSE);
    }

    if (current == "int") {
        return new Token(current, TokenType::INTEGER);
    }

    if (current == "String") {
        return new Token(current, TokenType::STRING);
    }

    if (peekCharacter() == '(') {
        return new Token(current, TokenType::FUNCTION_CALL);
    }

    return new Token(current, TokenType::LABEL);
}

Token *Lexer::readEqualityToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return new Token("==", TokenType::EQUALITY);
    }

    return new Token(std::string(1, currentCharacter), TokenType::ASSIGN);
}

Token *Lexer::readNegationToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return new Token("!=", TokenType::INEQUALITY);
    }

    return new Token(std::string(1, currentCharacter), TokenType::NEGATION);
}

Token *Lexer::readString() {
    std::string current;

    pollCharacter();
    while (currentCharacter != '"') {
        current += currentCharacter;
        pollCharacter();
    }

    return new Token(current, TokenType::STRING);
}

Token *Lexer::readSmallerToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return new Token("<=", TokenType::SMALLER_OR_EQUAL);
    }

    return new Token(std::string(1, currentCharacter), TokenType::SMALLER);
}

Token *Lexer::readGreaterToken() {
    if (peekCharacter() == '>') {
        pollCharacter();
        return new Token(">=", TokenType::GREATER_OR_EQUAL);
    }

    return new Token(std::string(1, currentCharacter), TokenType::GREATER);
}
