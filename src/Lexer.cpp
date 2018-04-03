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
    } else if (currentCharacter == '.') {
        return Token(std::string(1, currentCharacter), TokenType::DOT);
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
        current += currentCharacter;

        if (!isdigit(peekCharacter())) {
            break;
        }

        pollCharacter();
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

    if (current == "for") {
        return Token(current, TokenType::FOR);
    }

    if (current == "while") {
        return Token(current, TokenType::WHILE);
    }

    if (current == "return") {
        return Token(current, TokenType::RETURN);
    }

    if (current == "if") {
        return Token(current, TokenType::IF);
    }

    if (current == "else") {
        return Token(current, TokenType::ELSE);
    }

    return Token(current, TokenType::LABEL);
}

Token Lexer::readEqualityToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return Token("==", TokenType::EQUALITY);
    }

    return Token(std::string(1, currentCharacter), TokenType::ASSIGN);
}

Token Lexer::readNegationToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return Token("!=", TokenType::INEQUALITY);
    }

    return Token(std::string(1, currentCharacter), TokenType::NEGATION);
}

Token Lexer::readString() {
    std::string current;

    pollCharacter();
    while (currentCharacter != '"') {
        current += currentCharacter;
        pollCharacter();
    }

    return Token(current, TokenType::STRING);
}

Token Lexer::readSmallerToken() {
    if (peekCharacter() == '=') {
        pollCharacter();
        return Token("<=", TokenType::SMALLER_OR_EQUAL);
    }

    return Token(std::string(1, currentCharacter), TokenType::SMALLER);
}

Token Lexer::readGreaterToken() {
    if (peekCharacter() == '>') {
        pollCharacter();
        return Token(">=", TokenType::GREATER_OR_EQUAL);
    }

    return Token(std::string(1, currentCharacter), TokenType::GREATER);
}
