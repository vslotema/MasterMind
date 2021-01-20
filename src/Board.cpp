#include <iostream>
#include "../header files/Board.h"
using namespace std;
Board::Board()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->guesses[i][j] = '.';
            this->feedback[i][j] = '.';
        }
    }
};

void Board::setNewGuess(string guess, int numGuess)
{

    if (numGuess <= 10)
    {
        for (int i = 0; i < 4; i++)
        {
            this->guesses[numGuess][i] = guess[i];
        }
    }
}
void Board::setNewFeedBack(string feedback, int numGuess)
{

    if (numGuess <= 10)
    {
        for (int i = 0; i < 4; i++)

        {

            this->feedback[numGuess][i] = feedback[i];
        }
    }
}
void Board::showBoard()
{
    for (int i = 0; i < 13; i++)
    {
        string line;
        for (int j = 0; j < 16; j++)
        {
            if (i >= 2 && i < 12 && j >= 2 && j < 6)
            {
                line += this->guesses[i - 2][j - 2];
            }
            else if (i >= 2 && i < 12 && j >= 9 && j < 13)
            {
                line += this->feedback[i - 2][j - 9];
            }
            else
            {
                line += this->board[i][j];
            }
        }

        cout << line << endl;
    }
};
