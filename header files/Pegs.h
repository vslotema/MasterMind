#pragma once

class Pegs
{
private:
    static constexpr char codePegs[6] = {'1', '2', '3', '4', '5', '6'};
    static constexpr char keyPegs[2] = {'B', 'W'};

public:
    static char getCodePeg(int peg);
    static char getKeyPeg(int peg);
};