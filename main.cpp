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

    /* while ((token = lexer.ReadNextToken()).getTokenType() != TokenType::END_OF_FILE) {
        if (token.GetTokenType() == TokenType::UNKNOWN) {
            std::cout << "Ecountered unknown token: " << token.getValue();
        }

        std::cout << token.GetValue() << std::endl;
    }*/

    Parser parser = Parser(lexer);
    Node *node = parser.parse();


    return 0;
}