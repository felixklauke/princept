//
// Created by Felix Klauke on 04.04.18.
//

#include "VarAssignNode.h"

VarAssignNode::VarAssignNode(std::string *variableName, Node *value)
        : variableName(variableName), value(value) {

}
