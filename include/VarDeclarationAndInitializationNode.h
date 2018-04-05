//
// Created by Felix Klauke on 05.04.18.
//

#ifndef PRINCEPT_VARDECLARATIONANDINITIALIZATIONNODE_H
#define PRINCEPT_VARDECLARATIONANDINITIALIZATIONNODE_H


#include "Node.h"
#include "VarAssignNode.h"

class VarDeclarationAndInitializationNode : public VarAssignNode {
public:
    VarDeclarationAndInitializationNode(std::string *variableName, TokenType variableType, Node *value);

private:
    TokenType variableType;
};


#endif //PRINCEPT_VARDECLARATIONANDINITIALIZATIONNODE_H
