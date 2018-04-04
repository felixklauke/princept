//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_VARDECLARATIONNODE_H
#define PRINCEPT_VARDECLARATIONNODE_H


#include <string>
#include "Node.h"
#include "TokenType.h"
#include "StatementNode.h"

class VarDeclarationNode : public StatementNode {
public:
    explicit VarDeclarationNode(std::string *variableName, TokenType variableType);

public:

private:
    std::string *variableName;

    TokenType variableType;
};


#endif //PRINCEPT_VARDECLARATIONNODE_H
