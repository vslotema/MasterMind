#include "../header files/MasterMind.h"



int main()
{

    system("clear");
    MasterMind mm;
    mm.setUp();
    std::cout << "Press enter to start the game!";
    std::cin.ignore();
    std::cin.get();
    mm.runGame();
}
