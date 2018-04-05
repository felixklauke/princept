//
// Created by Felix Klauke on 23.02.18.
//

#include <iostream>
#include "Lexer.h"

Lexer::Lexer(const std::string &content) : content(content) {

}

Token *Lexer::ReadNextToken() {
    PeekCharacter();

    if (endOfFileIsReached) {
        return new Token("END_OF_FILE", TokenType::END_OF_FILE);
    }

    PollCharacter();

    if (iswspace(currentCharacter)) {
        return ReadNextToken();
    }

    if (isalpha(currentCharacter)) {
        return ReadAlphabeticToken();
    }

    if (isdigit(currentCharacter)) {
        return ReadIntegerToken();
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
        return ReadSmallerToken();
    } else if (currentCharacter == '>') {
        return ReadGreaterToken();
    } else if (currentCharacter == '=') {
        return ReadEqualityToken();
    } else if (currentCharacter == '"') {
        return ReadString();
    } else if (currentCharacter == '!') {
        return ReadNegationToken();
    }

    return new Token("UNKNOWN", TokenType::UNKNOWN);
}

void Lexer::PollCharacter() {
    currentCharacter = ReadCharacter(currentReaderPosition);
    currentReaderPosition++;
}

char Lexer::PeekCharacter() {
    return ReadCharacter(currentReaderPosition);
}

char Lexer::ReadCharacter(unsigned long position) {
    if (position >= content.size()) {
        endOfFileIsReached = true;
        return 0;
    }

    return content.at(position);
}

Token *Lexer::ReadIntegerToken() {
    std::string current;

    while (isdigit(currentCharacter)) {
        current += currentCharacter;

        if (!isdigit(PeekCharacter())) {
            break;
        }

        PollCharacter();
    }

    return new Token(current, TokenType::INTEGER);
}

Token *Lexer::ReadAlphabeticToken() {
    std::string current;

    while (isalpha(currentCharacter) || isdigit(currentCharacter)) {
        current += currentCharacter;

        if (!isalpha(PeekCharacter())) {
            break;
        }

        PollCharacter();
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

    if (PeekCharacter() == '(') {
        return new Token(current, TokenType::FUNCTION_CALL);
    }

    return new Token(current, TokenType::LABEL);
}

Token *Lexer::ReadEqualityToken() {
    if (PeekCharacter() == '=') {
        PollCharacter();
        return new Token("==", TokenType::EQUALITY);
    }

    return new Token(std::string(1, currentCharacter), TokenType::ASSIGN);
}

Token *Lexer::ReadNegationToken() {
    if (PeekCharacter() == '=') {
        PollCharacter();
        return new Token("!=", TokenType::INEQUALITY);
    }

    return new Token(std::string(1, currentCharacter), TokenType::NEGATION);
}

Token *Lexer::ReadString() {
    std::string current;

    PollCharacter();
    while (currentCharacter != '"') {
        current += currentCharacter;
        PollCharacter();
    }

    return new Token(current, TokenType::STRING);
}

Token *Lexer::ReadSmallerToken() {
    if (PeekCharacter() == '=') {
        PollCharacter();
        return new Token("<=", TokenType::SMALLER_OR_EQUAL);
    }

    return new Token(std::string(1, currentCharacter), TokenType::SMALLER);
}

Token *Lexer::ReadGreaterToken() {
    if (PeekCharacter() == '>') {
        PollCharacter();
        return new Token(">=", TokenType::GREATER_OR_EQUAL);
    }

    return new Token(std::string(1, currentCharacter), TokenType::GREATER);
}
