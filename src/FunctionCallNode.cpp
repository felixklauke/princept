//
// Created by Felix Klauke on 05.04.18.
//

#include "FunctionCallNode.h"

FunctionCallNode::FunctionCallNode(FunctionNode *function, std::vector<Node *> *parameters)
        : function(function), parameters(parameters) {
}
