//
// Created by Felix Klauke on 29.03.18.
//

#ifndef PRINCEPT_TOKENTYPE_H
#define PRINCEPT_TOKENTYPE_H


#include <map>

enum class TokenType {

    LEFT_CURLY_BRACE,
    RIGHT_CURLY_BRACE,

    LEFT_BRACE,
    RIGHT_BRACE,

    PLUS,
    MINUS,

    GREATER,
    SMALLER,
    GREATER_OR_EQUAL,
    SMALLER_OR_EQUAL,

    DOT,

    BOOL,
    INTEGER,
    STRING,

    CLASS,
    FUNCTION,
    FUNCTION_CALL,

    FOR,
    WHILE,
    IF,
    ELSE,
    RETURN,

    ASSIGN,
    EQUALITY,
    INEQUALITY,
    NEGATION,

    LABEL,

    END_OF_FILE,
    UNKNOWN
};

#endif //PRINCEPT_TOKENTYPE_H
