#include <iostream>
#pragma once

class CodeMaster
{
private:
    char code[5];
    bool foundDuplicates();

public:
    CodeMaster();
    void setUpCode(bool duplicate);
    std::string analyzeGuess(std::string guess);
    std::string shuffleArray(std::string pegs); // Shuffles feedback string
    std::string getCode();
};