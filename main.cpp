#include "highlighter.h"
#include "tokenizer.h"

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();
    std::string data = buffer.str();

    file.close();

    run_syntax_highlighter(data);

    return 0;
}
