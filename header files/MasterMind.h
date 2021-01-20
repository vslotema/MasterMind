#pragma once

#include "./CodeMaster.h"

class MasterMind
{
private:
    int guessNum;
    int rounds;
    int nRounds;
    int won;
    bool duplicate;
    const int totalGuesses = 10;
    CodeMaster cm;

public:
    MasterMind();
    void setUp();
    void printRules();
    void printStats();
    bool isCorrectGuess(std::string feedback);
    void runGame();
};