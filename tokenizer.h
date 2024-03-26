#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>


enum class TokenType
{
    SPACE,
    NEWLINE,

    IDENTIFIER,
    OPERATOR,
    ASSIGNMENT,
    PREPROCESSOR,

    NUMERIC_LITERAL,
    STRING_LITERAL,

    UNKNOWN,
};


class Token
{
public:
    Token(TokenType type, std::string const& value);
    TokenType getType() const;
    std::string const& getValue() const;
private:
    TokenType type;
    std::string value;
};


class Tokenizer
{
public:
    Tokenizer(std::string const& data);
    std::unique_ptr<Token> getNextToken();
    bool hasNextToken() const;

    void reset();  // reset the tokenizer to the beginning of the data
private:
    size_t pos;
    std::string data;

    std::unique_ptr<Token> getMatched();
};


std::unordered_map<TokenType, std::string> const  PATTERNS
{
    { TokenType::SPACE, "^\\s+" },
    { TokenType::NEWLINE, "^\\n" },

    { TokenType::IDENTIFIER, "^\\w+" },
    { TokenType::OPERATOR, "^[+\\-*/]" },
    { TokenType::ASSIGNMENT, "^=" },
    { TokenType::PREPROCESSOR, "^\\#\\w+" },

    { TokenType::STRING_LITERAL, "^\"[^\"]*\"" },
    { TokenType::NUMERIC_LITERAL, "^\\d+" },


    // { TokenType::UNKNOWN, "^." },
};


std::unordered_map<TokenType, std::string> const TYPE_LITERALS
{
    { TokenType::SPACE, "TokenType::SPACE" },
    { TokenType::NEWLINE, "TokenType::NEWLINE" },

    { TokenType::IDENTIFIER, "TokenType::IDENTIFIER" },
    { TokenType::OPERATOR, "TokenType::OPERATOR" },
    { TokenType::ASSIGNMENT, "TokenType::ASSIGNMENT" },
    { TokenType::PREPROCESSOR, "TokenType::PREPROCESSOR" },

    { TokenType::STRING_LITERAL, "TokenType::STRING_LITERAL" },
    { TokenType::NUMERIC_LITERAL, "TokenType::NUMERIC_LITERAL" },

    { TokenType::UNKNOWN, "TokenType::UNKNOWN" },
};


#endif // TOKENIZER_H
