//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_CLASSNODE_H
#define PRINCEPT_CLASSNODE_H


#include <vector>
#include <string>
#include "Node.h"
#include "FunctionNode.h"

class ClassNode : public Node {

public:
    explicit ClassNode(std::string className, std::vector<FunctionNode *> *functions);

private:
    std::vector<FunctionNode *> *functions;

    std::string className;
};


#endif //PRINCEPT_CLASSNODE_H
