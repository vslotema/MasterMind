#include <iostream>
#include <unistd.h>
#include "../header files/MasterMind.h"
#include "../header files/CodeMaster.h"
#include "../header files/Board.h"
#include "../header files/Pegs.h"
#include "../header files/CodeBreaker.h"

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
    cout << "How many rounds would you like to play? Choose an even number. ";
    this->rounds = 1;
    while (this->rounds % 2 != 0)
    {
        cin >> this->rounds;
    }

    cout << "Would you like to play with code pegs of the same color? [y/n] ";
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

bool MasterMind::isCorrectGuess(string feedback)
{
    if (feedback.length() == 0)
        return false;

    for (int i = 0; i < 4; i++)
    {
        if (feedback[i] != 'B')
            return false;
    }

    this->won += 1;

    return true;
}

void MasterMind::printWon()
{
    cout << "\nCONGRATULATIONS YOU HAVE WON THIS ROUND!!!!" << endl;
    std::cout << "Press enter to play the next round!";
    std::cin.get();
}

void MasterMind::printLost()
{
    cout << "\nSorry you have lost this round :(" << endl;
    cout << "The code was ";
    cout << cm.getCode() << endl;
    std::cout << "Press enter to play the next round!";
    std::cin.get();
}

void MasterMind::gameOver()
{
    system("clear");
    cout << "GAME OVER!" << endl;
    if (won > rounds / 2)
    {
        printf("CONGRATS YOU HAVE WON THIS GAME WITH A TOTAL OF: %i OUT OF %i \n", won, rounds);
    }
    else
    {
        cout << "Sorry you have lost this game :(" << endl;
    }
    usleep(5e+6);
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
        int prevWon = won;

        while (guessNum <= totalGuesses && !isCorrectGuess(feedback))
        {
            system("clear");
            printRules();
            b.showBoard();
            printStats();
            if (guessNum == totalGuesses)
                break;
            string guess = CodeBreaker::getGuess();
            b.setNewGuess(guess, guessNum);
            feedback = cm.analyzeGuess(guess);
            b.setNewFeedBack(feedback, guessNum);
            guessNum += 1;
        }

        if (prevWon == won)
            printLost();
        else
            printWon();
    }

    gameOver();
}
