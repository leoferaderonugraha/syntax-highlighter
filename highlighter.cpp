#include "highlighter.h"
#include "tokenizer.h"

#include <iostream>


std::string highlight(std::string const& text, Colour const colour)
{
    return colours.at(colour) + text + colours.at(Colour::DEFAULT);
}

void run_syntax_highlighter(std::string const& code)
{
    Tokenizer tokenizer(code);

    std::unique_ptr<Token> token = tokenizer.getNextToken();

    while (token != nullptr) {
        std::string value = token->getValue();
        switch (token->getType()) {
            case TokenType::IDENTIFIER:
                {
                    if (!value.compare("int") ||
                            !value.compare("float") ||
                            !value.compare("double") ||
                            !value.compare("char") ||
                            !value.compare("bool") ||
                            !value.compare("void")) {
                        std::cout << highlight(value, Colour::CYAN);
                    } else {
                        std::cout << value;
                    }
                    break;
                }
                break;
            case TokenType::NUMERIC_LITERAL:
                std::cout << highlight(value, Colour::GREEN);
                break;
            case TokenType::STRING_LITERAL:
                std::cout << highlight(value, Colour::BLUE);
                break;
            case TokenType::OPERATOR:
                std::cout << highlight(value, Colour::RED);
                break;
            case TokenType::PREPROCESSOR:
                std::cout << highlight(value, Colour::MAGENTA);
                break;
            default:
                std::cout << value;
                break;
        }
        token = tokenizer.getNextToken();
    }

    std::cout << std::endl;
}
