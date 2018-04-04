//
// Created by Felix Klauke on 04.04.18.
//

#include "VarDeclarationNode.h"

VarDeclarationNode::VarDeclarationNode(std::string *variableName, TokenType variableType)
        : variableType(variableType), variableName(variableName) {
}
