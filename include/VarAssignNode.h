//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_VARASSIGNNODE_H
#define PRINCEPT_VARASSIGNNODE_H


#include <string>
#include "Node.h"
#include "TokenType.h"
#include "StatementNode.h"

class VarAssignNode : public StatementNode {

public:
    VarAssignNode(std::string *variableName, Node *value);

private:
    std::string *variableName;

    Node *value;

};


#endif //PRINCEPT_VARASSIGNNODE_H
