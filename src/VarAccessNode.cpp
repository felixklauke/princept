//
// Created by Felix Klauke on 04.04.18.
//

#include "VarAccessNode.h"

VarAccessNode::VarAccessNode(std::string *variableName) : variableName(variableName) {

}

std::string *VarAccessNode::GetVariableName() {
    return variableName;
}
