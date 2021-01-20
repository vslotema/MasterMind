#include "../header files/Pegs.h"
#include <iostream>

char Pegs::getCodePeg(int peg)
{
    switch (peg)
    {
    case 0:
        return codePegs[0];
    case 1:
        return codePegs[1];
    case 2:
        return codePegs[2];
    case 3:
        return codePegs[3];
    case 4:
        return codePegs[4];
    case 5:
        return codePegs[5];
    case 6:
        return codePegs[6];
    default:
        return -1;
    }
}
char Pegs::getKeyPeg(int peg)
{
    switch (peg)
    {
    case 0:
        return keyPegs[0];
    case 1:
        return keyPegs[1];
    default:
        return -1;
    }
}
