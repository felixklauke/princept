//
// Created by Felix Klauke on 04.04.18.
//

#include "FunctionNode.h"

FunctionNode::FunctionNode(std::string *functionName, std::vector<Node *> statements)
        : functionName(functionName), statements(statements) {}
