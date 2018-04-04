//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_INTEGERNODE_H
#define PRINCEPT_INTEGERNODE_H


#include "Node.h"

class IntegerNode : public Node {
public:
    explicit IntegerNode(int value);

    int GetValue();

private:
    int value;
};


#endif //PRINCEPT_INTEGERNODE_H
