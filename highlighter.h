#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <string>
#include <unordered_map>


enum class Colour
{
    DEFAULT,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

std::unordered_map<Colour, std::string> const colours
{
    { Colour::DEFAULT, "\033[0m" },
    { Colour::BLACK, "\033[30m" },
    { Colour::RED, "\033[31m" },
    { Colour::GREEN, "\033[32m" },
    { Colour::YELLOW, "\033[33m" },
    { Colour::BLUE, "\033[34m" },
    { Colour::MAGENTA, "\033[35m" },
    { Colour::CYAN, "\033[36m" },
    { Colour::WHITE, "\033[37m" }
};

std::string highlight(std::string const& text, Colour const colour);
void run_syntax_highlighter(std::string const& code);

#endif  // HIGHLIGHTER_H
