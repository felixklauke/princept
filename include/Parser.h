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

    ClassNode *parseClass();

    void eatToken(TokenType type);

    FunctionNode *parseFunction();

    StatementNode *parseStatement();

    StatementNode *parseVariableStatement();

    Node *parseValue();
};


#endif //PRINCEPT_PARSER_H
