//
// Created by Felix Klauke on 29.03.18.
//

#include <RootNode.h>
#include <ClassNode.h>
#include <iostream>
#include "Parser.h"

Parser::Parser(const Lexer &lexer) : lexer(lexer) {

}

Node *Parser::parse() {
    currentToken = lexer.readNextToken();

    std::vector<Node *> classNodes = std::vector<Node *>();

    while (currentToken->getTokenType() == TokenType::CLASS) {
        ClassNode *classNode = parseClass();
        classNodes.push_back(classNode);
    }

    auto *rootNode = new RootNode(&classNodes);

    std::cout << "Found root with " << classNodes.size() << " classes.";

    return rootNode;
}

ClassNode *Parser::parseClass() {
    std::vector<FunctionNode *> functionNodes = std::vector<FunctionNode *>();

    eatToken(TokenType::CLASS);
    std::string className = currentToken->getValue();
    eatToken(TokenType::LABEL);

    eatToken(TokenType::LEFT_CURLY_BRACE);
    while (currentToken->getTokenType() == TokenType::FUNCTION) {
        FunctionNode *functionNode = parseFunction();
        functionNodes.push_back(functionNode);
    }
    eatToken(TokenType::RIGHT_CURLY_BRACE);

    auto *classNode = new ClassNode(className, &functionNodes);

    std::cout << "Found class " << className << " with " << functionNodes.size() << " functions." << std::endl;

    return classNode;
}

void Parser::eatToken(TokenType type) {
    if (currentToken->getTokenType() == type) {
        Token *token = lexer.readNextToken();
        currentToken = token;
        return;
    }

    throw std::invalid_argument("Unexpected token " + currentToken->getValue());
}

FunctionNode *Parser::parseFunction() {
    eatToken(TokenType::FUNCTION);
    std::string functionName = currentToken->getValue();
    eatToken(TokenType::LABEL);

    eatToken(TokenType::LEFT_BRACE);
    // Parameters
    eatToken(TokenType::RIGHT_BRACE);

    eatToken(TokenType::LEFT_CURLY_BRACE);
    std::vector<Node *> statements = std::vector<Node *>();
    // Statements
    eatToken(TokenType::RIGHT_CURLY_BRACE);

    auto *functionNode = new FunctionNode(&functionName, statements);

    std::cout << "Found function " << functionName << " with " << statements.size() << " statements" << std::endl;

    return functionNode;
}
