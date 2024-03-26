#include "tokenizer.h"

#include <vector>
#include <string>
#include <regex>
#include <memory>


Token::Token(TokenType type, std::string const& value) :
    type(type),
    value(value)
{
}


TokenType Token::getType() const
{
    return this->type;
}


std::string const& Token::getValue() const
{
    return this->value;
}


Tokenizer::Tokenizer(std::string const& text) :
    pos(0),
    data(text)
{
}


bool Tokenizer::hasNextToken() const
{
    return this->pos < this->data.size();
}


std::unique_ptr<Token> Tokenizer::getNextToken()
{
    if (!this->hasNextToken()) {
        return nullptr;
    }

    std::unique_ptr<Token> matched = this->getMatched();

    return matched;
}

void Tokenizer::reset()
{
    this->pos = 0;
}

std::unique_ptr<Token> Tokenizer::getMatched()
{
    std::string value;

    for (auto const& pattern : PATTERNS) {
        std::regex r(pattern.second);
        std::smatch match;
        std::string const& text = this->data.substr(this->pos);

        if (std::regex_search(text, match, r)) {
            value = match.str();
            this->pos += value.size();
            return std::make_unique<Token>(pattern.first, value);
        }
    }

    value = this->data[this->pos];
    this->pos++;

    return std::make_unique<Token>(TokenType::UNKNOWN, value);
}
