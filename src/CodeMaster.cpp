#include <iostream>
#include "../header files/CodeMaster.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "../header files/Pegs.h"
#include "../header files/CodeBreaker.h"

using namespace std;

void CodeMaster::setUpCode(bool duplicate)
{
    srand((unsigned)time(0));

    do
    {
        for (int i = 0; i < 4; i++)
        {
            int n = rand() % 6;
            this->code[i] = Pegs::getCodePeg(n);
        }

    } while (!duplicate && foundDuplicates());
}
bool CodeMaster::foundDuplicates()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {

                if (code[i] == code[j])
                {
                    return true;
                }
            }
        }
    }

    return false;
}
CodeMaster::CodeMaster() {}

string CodeMaster::analyzeGuess(string guess)
{
    int mark[4] = {0, 0, 0, 0};
    int sameColIndx;
    string keyPegs = "....";

    for (int i = 0; i < 4; i++)
    {
        sameColIndx = -1;
        for (int j = 0; j < 4; j++)
        {
            if (guess[i] == code[i]) //Found right position and right number
            {
                keyPegs[i] = Pegs::getKeyPeg(0); //Retrieve black peg
                mark[j] = 1;
                break;
            }
            else if (mark[j] == 0 && guess[i] == code[j])
            {
                //Found right number but wrong position
                sameColIndx = j;
            }
            if (j == 3 && sameColIndx != -1)
            {
                mark[sameColIndx] = 1;
                keyPegs[sameColIndx] = Pegs::getKeyPeg(1); //Retrieve white peg
            }
        }
    }
    keyPegs = shuffleArray(keyPegs);

    return keyPegs;
}

string CodeMaster::shuffleArray(string pegs)
{

    srand((unsigned)time(0));

    for (int i = 0; i < 4; i++)
    {
        int n = rand() % 4;
        char holder = pegs[i];
        pegs[i] = pegs[n];
        pegs[n] = holder;
    }
    return pegs;
}

string CodeMaster::getCode()
{
    string code;
    for (int i = 0; i < 4; i++)
    {
        code += this->code[i];
    }

    return code;
}