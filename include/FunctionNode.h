//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_FUNCTIONNODE_H
#define PRINCEPT_FUNCTIONNODE_H


#include <string>
#include <vector>
#include "Node.h"

class FunctionNode : Node {
public:
    FunctionNode(std::string *functionName, std::vector<Node *> statements,
                 std::vector<Node *> parameters);

private:
    std::string *functionName;

    std::vector<Node *> statements;

    std::vector<Node *> parameters;
};


#endif //PRINCEPT_FUNCTIONNODE_H
