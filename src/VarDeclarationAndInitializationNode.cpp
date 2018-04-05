//
// Created by Felix Klauke on 05.04.18.
//

#include "VarDeclarationAndInitializationNode.h"

VarDeclarationAndInitializationNode::VarDeclarationAndInitializationNode(std::string *variableName,
                                                                         TokenType variableType, Node *value)
        : VarAssignNode(variableName, value) {}
