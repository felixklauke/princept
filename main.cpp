#include <fstream>
#include <Lexer.h>
#include <iostream>
#include <Parser.h>

int main(int arg, char *argv[]) {


    std::fstream infile{"test.pct"};
    std::string content{std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>()};

    std::cout << content.size() << std::endl;

    Lexer lexer(content);

    Token token = Token("", TokenType::UNKNOWN);

    /* while ((token = lexer.readNextToken()).getTokenType() != TokenType::END_OF_FILE) {
        if (token.getTokenType() == TokenType::UNKNOWN) {
            std::cout << "Ecountered unknown token: " << token.getValue();
        }

        std::cout << token.getValue() << std::endl;
    }*/

    Parser parser = Parser(lexer);
    Node *node = parser.parse();


    return 0;
}