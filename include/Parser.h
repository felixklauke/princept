//
// Created by Felix Klauke on 29.03.18.
//

#ifndef PRINCEPT_PARSER_H
#define PRINCEPT_PARSER_H


#include "Lexer.h"
#include "Node.h"
#include "ClassNode.h"
#include "StatementNode.h"

class Parser {

public:
    explicit Parser(const Lexer &lexer);

    Node *parse();

private:
    Lexer lexer;

    Token *currentToken;

    ClassNode *ParseClass();

    void EatToken(TokenType type);

    FunctionNode *ParseFunction();

    StatementNode *ParseStatement();

    StatementNode *ParseVariableStatement();

    Node *ParseValue();
};


#endif //PRINCEPT_PARSER_H
