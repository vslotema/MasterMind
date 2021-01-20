#include <iostream>
#include <unistd.h>
#include "../header files/MasterMind.h"
#include "../header files/CodeMaster.h"
#include "../header files/Board.h"
#include "../header files/Pegs.h"
using namespace std;

MasterMind::MasterMind()
{
    this->guessNum = 0;
    this->nRounds = 0;
    this->won = 0;
    this->cm = CodeMaster();
};

void MasterMind::setUp()
{
    char dup;
    cout << "Welcome to MasterMind!" << endl;
    cout << "How many rounds would you like to play?  " << endl;
    cin >> this->rounds;
    cout << "Would you like to play with code pegs of the same color? [y/n] " << endl;
    while (dup != 'y' && dup != 'n')
    {
        cin >> dup;
    }
    this->duplicate = dup == 'y';
}

void MasterMind::printRules()
{
    cout << "MasterMind Rules" << endl;
    cout << "1. Break the code consisting of four numbers within 10 guesses." << endl;
    cout << "2. Choose between the code pegs: 1, 2, 3, 4, 5, and 6." << endl;
    cout << "3. Feedback consists of: " << endl;
    cout << "   Key peg 'W': Right number but wrong position." << endl;
    cout << "   Key peg 'B': Right numer and right position." << endl;
    cout << "4. You win the round when all four key pegs return 'B'." << endl;
    cout << "5. You win the game when total of won rounds > total rounds." << endl;
    cout << "\n To exit the game press Ctrl + c.\n"
         << endl;
}

void MasterMind::printStats()
{
    string same = duplicate ? "True" : "False";
    cout << "\nPegs of same number: " << same << endl;
    cout << "Round: " << nRounds << "/" << rounds << endl;
    cout << "Wins: " << won << endl;
}

bool MasterMind::isLegalCodePeg(char p)
{

    for (int i = 0; i < 6; i++)
    {
        if (Pegs::getCodePeg(i) == p)
            return true;
    }
    return false;
}

bool MasterMind::isLegalGuess(string guess)
{
    if (guess.length() < 4)
        return false;

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
string MasterMind::getCorrectGuessFormat(string guess)
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

string MasterMind::getGuess()
{
    string guess;
    cout << "\nGuess the code **** and press enter: " << endl;

    while (!isLegalGuess(guess))
    {
        getline(cin, guess);
        guess = getCorrectGuessFormat(guess);
        if (guess.length() < 4 || guess.length() > 4)
            cout << "Please select only four numbers!";
    }
    return guess;
}

bool MasterMind::isCorrectGuess(string feedback)
{
    if (feedback.length() == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        if (feedback[i] != 'B')
            return false;
    }
    system("clear");
    cout << "CONGRATULATIONS YOU HAVE WON THIS ROUND!!!!" << endl;
    usleep(2e+6);
    this->won += 1;

    return true;
}

void MasterMind::runGame()
{

    while (nRounds < rounds)
    {
        guessNum = 0;
        Board b;
        string feedback;
        cm.setUpCode(duplicate);
        this->nRounds += 1;
        while (guessNum <= totalGuesses && !isCorrectGuess(feedback))
        {
            system("clear");
            cout << cm.getCode() << endl;
            printRules();
            b.showBoard();
            printStats();
            string guess = getGuess();
            b.setNewGuess(guess, guessNum);
            feedback = cm.analyzeGuess(guess);
            b.setNewFeedBack(feedback, guessNum);
            guessNum += 1;
        }
    }

    system("clear");
    if (won > rounds / 2)
    {
        printf("CONGRATS YOU HAVE WON THIS GAME WITH A TOTAL OF: %i OUT OF %i", won, rounds);
        usleep(5e+6);
    }
    else
    {
        cout << "sorry you have lost this game :(" << endl;
        usleep(5e+6);
    }
}
