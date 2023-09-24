#pragma once
#include "Dice.h"
#include "Category.h"

#define ATTEMP_TIMES_PER_ROUND 3

class Game
{
private:
    Dices dices;
    Categories categories;
    struct
    {
        bool operator()(Dice a, Dice b) const { return a.getSide() < b.getSide(); }
    } compareSide;
public:
    Game();
    ~Game();

    void calculationSection();
    void oneRound();
    void execute();
};