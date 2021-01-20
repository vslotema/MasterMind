#include <iostream>
#pragma once

class Board
{
private:
    // char guesses[10][5];
    char feedback[10][5];
    char guesses[10][5];
    char board[13][16] = {
        "codepeg|keypeg ",
        "###############",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "# .... # .... #",
        "##****#########",

    };

public:
    Board();
    void setNewGuess(std::string guess, int numGuess);
    void setNewFeedBack(std::string feedback, int numGuess);
    void showBoard();
};