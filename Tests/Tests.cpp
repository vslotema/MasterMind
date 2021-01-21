#include <iostream>
#include "./Tests.h"
#include "../header files/Pegs.h"
using namespace std;

string Tests::CodeMaster::analyzeGuess(string guess, char code[5])
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
                mark[i] = 1;
                break;
            }
            else if (mark[j] == 0 && guess[i] == code[j])
            {

                sameColIndx = j;
            }
            if (j == 3 && sameColIndx != -1)
            {

                mark[sameColIndx] = 1;
                keyPegs[sameColIndx] = Pegs::getKeyPeg(1); //Retrieve white peg
            }
        }
    }

    //keyPegs = shuffleArray(keyPegs);

    return keyPegs;
};

int main()
{
    char code[5] = "1345";
    string res = Tests::CodeMaster::analyzeGuess("1345", code);
    if (res == "BBBB")
        cout << "Test 1 passed!" << endl;
    else
        cout << "Test 1 failed got answer: " << res << " Instead of: "
             << "BBBB" << endl;

    res = Tests::CodeMaster::analyzeGuess("3154", code);
    if (res == "WWWW")
        cout << "Test 2 passed!" << endl;
    else
        cout << "Test 2 failed got answer: " << res << " Instead of: "
             << "WWWW" << endl;

    res = Tests::CodeMaster::analyzeGuess("1354", code);
    if (res == "BBWW")
        cout << "Test 3 passed!" << endl;
    else
        cout << "Test 3 failed got answer: " << res << " Instead of: "
             << "BBWW" << endl;

    res = Tests::CodeMaster::analyzeGuess("1435", code);
    if (res == "BWWB")
        cout << "Test 4 passed!" << endl;
    else
        cout << "Test 4 failed got answer: " << res << " Instead of: "
             << "BWWB" << endl;

    res = Tests::CodeMaster::analyzeGuess("1466", code);
    if (res == "B.W.")
        cout << "Test 5 passed!" << endl;
    else
        cout << "Test 5 failed got answer: " << res << " Instead of: "
             << "B.W." << endl;

    /************************************************************/
    char code2[5] = "3366";
    res = Tests::CodeMaster::analyzeGuess("1345", code2);
    if (res == ".B..")
        cout << "Test 6 passed!" << endl;
    else
        cout << "Test 6 failed got answer: " << res << " Instead of: "
             << ".B.." << endl;

    res = Tests::CodeMaster::analyzeGuess("6633", code2);
    if (res == "WWWW")
        cout << "Test 7 passed!" << endl;
    else
        cout << "Test 7 failed got answer: " << res << " Instead of: "
             << "WWWW" << endl;

    res = Tests::CodeMaster::analyzeGuess("6363", code2);
    if (res == "WBBW")
        cout << "Test 8 passed!" << endl;
    else
        cout << "Test 8 failed got answer: " << res << " Instead of: "
             << "WBBW" << endl;

    res = Tests::CodeMaster::analyzeGuess("5555", code2);
    if (res == "....")
        cout << "Test 9 passed!" << endl;
    else
        cout << "Test 9 failed got answer: " << res << " Instead of: "
             << "...." << endl;

    res = Tests::CodeMaster::analyzeGuess("6443", code2);
    if (res == ".W.W")
        cout << "Test 10 passed!" << endl;
    else
        cout << "Test 10 failed got answer: " << res << " Instead of: "
             << "W..W" << endl;
    /********************************************************************/

    char code3[5] = "1113";
    res = Tests::CodeMaster::analyzeGuess("1345", code3);
    if (res == "B..W")
        cout << "Test 11 passed!" << endl;
    else
        cout << "Test 11 failed got answer: " << res << " Instead of: "
             << "B..W" << endl;

    res = Tests::CodeMaster::analyzeGuess("3111", code3);
    if (res == "WBBW")
        cout << "Test 12 passed!" << endl;
    else
        cout << "Test 12 failed got answer: " << res << " Instead of: "
             << "WBBW" << endl;
    return 0;
}