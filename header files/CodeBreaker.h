#include <iostream>
#pragma once

class CodeBreaker
{

private:
    static bool isLegalCodePeg(char p);
    static bool isLegalGuess(std::string guess);
    static std::string getCorrectGuessFormat(std::string guess);

public:
    static std::string getGuess();
};