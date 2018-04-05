//
// Created by Felix Klauke on 05.04.18.
//

#ifndef PRINCEPT_FUNCTIONCALLNODE_H
#define PRINCEPT_FUNCTIONCALLNODE_H


#include "FunctionNode.h"

class FunctionCallNode : public Node {
public:
    FunctionCallNode(FunctionNode *function, std::vector<Node *> *parameters);

private:
    FunctionNode *function;

    std::vector<Node *> *parameters;
};


#endif //PRINCEPT_FUNCTIONCALLNODE_H
