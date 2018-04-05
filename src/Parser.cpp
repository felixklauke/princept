//
// Created by Felix Klauke on 29.03.18.
//

#include <RootNode.h>
#include <ClassNode.h>
#include <iostream>
#include <StatementNode.h>
#include <VarDeclarationNode.h>
#include <VarAssignNode.h>
#include <IntegerNode.h>
#include <FunctionCallNode.h>
#include <VarDeclarationAndInitializationNode.h>
#include "Parser.h"

Parser::Parser(const Lexer &lexer) : lexer(lexer) {

}

Node *Parser::parse() {
    currentToken = lexer.ReadNextToken();

    std::vector<Node *> classNodes = std::vector<Node *>();

    while (currentToken->GetTokenType() == TokenType::CLASS) {
        ClassNode *classNode = ParseClass();
        classNodes.push_back(classNode);
    }

    auto *rootNode = new RootNode(&classNodes);

    std::cout << "Found root with " << classNodes.size() << " classes.";

    return rootNode;
}

ClassNode *Parser::ParseClass() {
    std::vector<FunctionNode *> functionNodes = std::vector<FunctionNode *>();

    EatToken(TokenType::CLASS);
    std::string className = currentToken->GetValue();
    EatToken(TokenType::LABEL);

    EatToken(TokenType::LEFT_CURLY_BRACE);
    while (currentToken->GetTokenType() == TokenType::FUNCTION) {
        FunctionNode *functionNode = ParseFunction();
        functionNodes.push_back(functionNode);
    }
    EatToken(TokenType::RIGHT_CURLY_BRACE);

    auto *classNode = new ClassNode(className, &functionNodes);

    std::cout << "Found class " << className << " with " << functionNodes.size() << " functions." << std::endl;

    return classNode;
}

void Parser::EatToken(TokenType type) {
    if (currentToken->GetTokenType() == type) {
        Token *token = lexer.ReadNextToken();
        currentToken = token;
        return;
    }

    throw std::invalid_argument("Unexpected token " + currentToken->GetValue());
}

FunctionNode *Parser::ParseFunction() {
    EatToken(TokenType::FUNCTION);
    std::string functionName = currentToken->GetValue();
    EatToken(TokenType::FUNCTION_CALL);

    EatToken(TokenType::LEFT_BRACE);
    std::vector<Node *> parameters = std::vector<Node *>();
    while (currentToken->GetTokenType() != TokenType::RIGHT_BRACE) {
        parameters.push_back(ParseValue());

        if (currentToken->GetTokenType() == TokenType::COMMA) {
            EatToken(TokenType::COMMA);
        }
    }
    EatToken(TokenType::RIGHT_BRACE);

    EatToken(TokenType::LEFT_CURLY_BRACE);
    std::vector<Node *> statements = std::vector<Node *>();
    while (currentToken->GetTokenType() != TokenType::RIGHT_CURLY_BRACE) {
        Node *statementNode = ParseStatement();
        statements.push_back(statementNode);
    }
    EatToken(TokenType::RIGHT_CURLY_BRACE);

    auto *functionNode = new FunctionNode(&functionName, &statements, &parameters);

    std::cout << "Found function " << functionName << " with " << statements.size() << " statements and "
              << parameters.size() << " parameters." << std::endl;

    return functionNode;
}

Node *Parser::ParseStatement() {
    if (currentToken->GetTokenType() == TokenType::INTEGER || currentToken->GetTokenType() == TokenType::STRING) {
        return ParseVariableStatement();
    } else if (currentToken->GetTokenType() == TokenType::FUNCTION_CALL) {
        return ParseFunctionCall();
    } else if (currentToken->GetTokenType() == TokenType::LABEL) {
        return ParseVariableAssignStatement();
    }
}

StatementNode *Parser::ParseVariableStatement() {
    TokenType variableType = currentToken->GetTokenType();
    EatToken(variableType);

    std::string variableName = currentToken->GetValue();
    EatToken(TokenType::LABEL);

    if (currentToken->GetTokenType() == TokenType::ASSIGN) {
        EatToken(TokenType::ASSIGN);

        auto *variableStatement = new VarDeclarationAndInitializationNode(&variableName, variableType, ParseValue());

        std::cout << "Found declared and assigned variable: " << variableName << "." << std::endl;

        return variableStatement;
    }

    auto *variableStatement = new VarDeclarationNode(&variableName, variableType);

    std::cout << "Found declared variable: " << variableName << "." << std::endl;

    return variableStatement;
}

Node *Parser::ParseValue() {
    if (currentToken->GetTokenType() == TokenType::INTEGER) {
        IntegerNode *integerNode = new IntegerNode(std::stoi(currentToken->GetValue()));
        EatToken(TokenType::INTEGER);
        return integerNode;
    }
}

Node *Parser::ParseFunctionCall() {
    std::string functionName = currentToken->GetValue();
    EatToken(TokenType::FUNCTION_CALL);
    EatToken(TokenType::LEFT_BRACE);

    std::vector<Node *> parameters = std::vector<Node *>();
    while (currentToken->GetTokenType() != TokenType::RIGHT_BRACE) {
        parameters.push_back(ParseValue());

        if (currentToken->GetTokenType() == TokenType::COMMA) {
            EatToken(TokenType::COMMA);
        }
    }

    EatToken(TokenType::RIGHT_BRACE);

    auto *functionCallNode = new FunctionCallNode(nullptr, &parameters);

    std::cout << "Found function call: " << functionName << " with " << parameters.size() << " parameters."
              << std::endl;

    return functionCallNode;
}

Node *Parser::ParseVariableAssignStatement() {
    std::string variableName = currentToken->GetValue();
    EatToken(TokenType::LABEL);
    EatToken(TokenType::ASSIGN);

    auto *varAssignNode = new VarAssignNode(&variableName, ParseValue());

    std::cout << "Found variable assign node: " << variableName << std::endl;

    return varAssignNode;
}
