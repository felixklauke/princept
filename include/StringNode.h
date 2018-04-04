//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_STRINGNODE_H
#define PRINCEPT_STRINGNODE_H


#include <string>
#include "Node.h"

class StringNode : Node {
public:
    StringNode(std::string *value);

public:
    std::string *value;
};


#endif //PRINCEPT_STRINGNODE_H
