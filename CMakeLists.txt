cmake_minimum_required(VERSION 3.9)
project(princept)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(princept main.cpp src/Lexer.cpp include/Lexer.h src/Token.cpp include/Token.h include/TokenType.h src/Parser.cpp include/Parser.h src/Node.cpp include/Node.h src/RootNode.cpp include/RootNode.h src/ClassNode.cpp include/ClassNode.h src/FunctionNode.cpp include/FunctionNode.h src/VarDeclarationNode.cpp include/VarDeclarationNode.h src/VarAssignNode.cpp include/VarAssignNode.h src/StatementNode.cpp include/StatementNode.h src/IntegerNode.cpp include/IntegerNode.h src/StringNode.cpp include/StringNode.h src/VarAccessNode.cpp include/VarAccessNode.h src/FunctionCallNode.cpp include/FunctionCallNode.h src/VarDeclarationAndInitializationNode.cpp include/VarDeclarationAndInitializationNode.h)