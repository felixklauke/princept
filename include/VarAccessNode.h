//
// Created by Felix Klauke on 04.04.18.
//

#ifndef PRINCEPT_VARACCESSNODE_H
#define PRINCEPT_VARACCESSNODE_H


#include <string>
#include "StatementNode.h"

class VarAccessNode : public StatementNode {

public:
    explicit VarAccessNode(std::string *variableName);

    std::string *GetVariableName();

private:
    std::string *variableName;

};


#endif //PRINCEPT_VARACCESSNODE_H
