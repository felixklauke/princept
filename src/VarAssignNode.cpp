//
// Created by Felix Klauke on 04.04.18.
//

#include "VarAssignNode.h"

VarAssignNode::VarAssignNode(std::string *variableName, TokenType variableType, Node *value)
        : variableName(variableName), variableType(variableType), value(value) {

}
