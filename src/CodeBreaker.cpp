#include "../header files/CodeBreaker.h"
#include "../header files/Pegs.h"
#include <iostream>
#include <unistd.h>
using namespace std;

bool CodeBreaker::isLegalCodePeg(char p)
{

    for (int i = 0; i < 6; i++)
    {
        if (Pegs::getCodePeg(i) == p)
            return true;
    }
    return false;
}

bool CodeBreaker::isLegalGuess(string guess)
{
    if (guess.length() < 4 || guess.length() > 4)
    {
        cout << "Please select 4 numbers!" << endl;
        return false;
    }

    string illegal;
    for (int i = 0; i < 4; i++)
    {
        if (!isLegalCodePeg(guess[i]))
        {
            illegal += guess[i];
            illegal += ',';
        }
    }

    if (illegal.length() > 0)
    {
        cout << "Code peg(s) {" << illegal << "} does not exist. Please choose out of {1,2,3,4,5,6}." << endl;
        return false;
    }

    return true;
}
string CodeBreaker::getCorrectGuessFormat(string guess)
{

    string correctF;
    int indx = 0;
    for (int i = 0; i < guess.length(); i++)
    {

        if (guess[i] != ' ')
        {
            correctF += guess[i];
            indx++;
        }
    }

    return correctF;
}

string CodeBreaker::getGuess()
{
    string guess;
    cout << "\nGuess the code **** and press enter: " << endl;

    do
    {
        getline(cin, guess);
        guess = getCorrectGuessFormat(guess);

    } while (!isLegalGuess(guess));

    return guess;
}
