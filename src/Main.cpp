#include "Game.h"

int main()
{
    uint16_t action;
    std::cout << "Do you want to play game?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
    std::cin >> action;
    Game game;
    while(true)
    {
        if (action == 1)
        {
            game.execute();
        }
        else
        {
            break;
        }
        std::cout << "Play again?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
        std::cin >> action;
    }
    return 0;
}