//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_ROOTNODE_H
#define PRINCEPT_ROOTNODE_H


#include <vector>
#include "Node.h"

class RootNode : public Node {

public:
    explicit RootNode(std::vector<Node *> *classes);

private:
    std::vector<Node *> *classes;

};


#endif //PRINCEPT_ROOTNODE_H
