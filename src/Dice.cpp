#include "Dice.h"

Dice::Dice()
: isLock(false)
, side(1)
{
}

Dice::~Dice()
{    
}

bool Dice::getLock() const
{
    return isLock;
}

void Dice::setLock(bool _isLock)
{
    isLock = _isLock;
}

uint16_t Dice::getSide() const
{
    return side;
}

void Dice::setSide(uint16_t _side)
{
    side = _side;
}

uint16_t Dice::randomSide()
{
    uint16_t side = 1;
    side = std::rand() % 6 + 1;
    return side;
}

void Dice::roll()
{
    if (isLock == false)
    {
        side = randomSide();
    }
}

Dices::Dices()
{
    for (auto& dice: dices)
    {
        dice = Dice();
    }
}

Dices::~Dices()
{
}

std::array<Dice, NUMBERS_OF_DICE> Dices::getValue() const
{
    return dices;
}

std::array<Dice, NUMBERS_OF_DICE>& Dices::getValueMutable()
{
    return dices;
}

void Dices::setValue(std::array<Dice, NUMBERS_OF_DICE> _value)
{
    dices = _value;
}

void Dices::roll()
{
    for (auto& dice: dices)
    {
        if (dice.getLock() == false)
        {
            dice.roll();
        }
    }
}

void Dices::drawSequence(std::string firstCharacter, std::string secondCharacter, bool isCheckLock) const
{
    if (isCheckLock)
    {
        for (auto dice: dices)
        {
            if (dice.getLock())
            {
                std::cout << firstCharacter << " " << secondCharacter << " ";

            }
            else
            {
                std::cout << firstCharacter << "   ";
            }
        }
    }
    else
    {
        uint16_t index = 1;
        for (auto dice: dices)
        {
            if (secondCharacter == "side")
            {
                std::cout << firstCharacter << " " << dice.getSide() << " ";
            }
            else if (secondCharacter == "index")
            {
                std::cout << firstCharacter << " " << index << " ";
                ++index;
            }
            else if (secondCharacter != " " && secondCharacter != "-")
            {
                std::cout << firstCharacter << " " << secondCharacter << " ";
            }
            else
            {
                std::cout << firstCharacter << secondCharacter << secondCharacter << secondCharacter ;
            }
        }
    }
    std::cout << firstCharacter << std::endl;
}

void Dices::showDices() const
{
    drawSequence(" ", "-", false);
    drawSequence("|", "side", false);
    drawSequence(" ", "-", false);
}

void Dices::showChoseDice() const
{
    drawSequence("|", "x", true);
    drawSequence(" ", "-", false);
    drawSequence(" ", "^", false);
    drawSequence(" ", "|", false);
    drawSequence(" ", "index", false);
}

uint16_t Dices::aces() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 1)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::twos() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 2)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::threes() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 3)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::fours() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 4)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::fives() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 5)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::sixes() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.getSide() == 6)
        {
            score += dice.getSide();
        }
    }
    return score;
}

uint16_t Dices::onePair() const
{
    uint16_t score = 0;
    for ( int i = 0; i < 4; i++ )
    {
        if (dices[i].getSide() == dices[i+1].getSide())
        {
            score = dices[i].getSide()*2;
        }
    }
    return score;
}

uint16_t Dices::twoPair() const
{
    uint16_t score = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if ((dices[i].getSide() == dices[i+1].getSide())
        && (dices[i+2].getSide() == dices[i+3].getSide()))
        {
            score += dices[i].getSide();
            score += dices[i+1].getSide();
            score += dices[i+2].getSide();
            score += dices[i+3].getSide();
            return score;
        }
    }

    if ((dices[0].getSide() == dices[1].getSide())
    && (dices[3].getSide() == dices[4].getSide()))
    {
        score += dices[0].getSide();
        score += dices[1].getSide();
        score += dices[3].getSide();
        score += dices[4].getSide();
        return score;
    }
    return score;
}

uint16_t Dices::threeOfAKind() const
{
    uint16_t score = 0;
    for ( int i = 0; i < 3; i++ )
    {
        if ((dices[i].getSide() == dices[i+1].getSide())
        && (dices[i+1].getSide() == dices[i+2].getSide()))
        {
            score = dices[i].getSide()*3;
        }
    }
    return score;
}

uint16_t Dices::fourOfAKind() const
{
    uint16_t score = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if ((dices[i].getSide() == dices[i+1].getSide())
        && (dices[i+1].getSide() == dices[i+2].getSide())
        && (dices[i+2].getSide() == dices[i+3].getSide()))
        {
            score = dices[i].getSide()*4;
        }
    }
    return score;
}

uint16_t Dices::fullHouse() const
{
    uint16_t score = 0;
    uint16_t sideOfThreeOfAKind = threeOfAKind()/3;

    if (sideOfThreeOfAKind == 0)
    {
        return score;
    }

    for ( int i = 0; i < 4; i++ )
    {
        if (dices[i].getSide() == sideOfThreeOfAKind)
        {
            continue;
        }
        else
        {
            if (dices[i].getSide() == dices[i+1].getSide())
            {
                score += sideOfThreeOfAKind*3;
                score += dices[i].getSide()*2;
            }
        }
    }
    return score;
}

uint16_t Dices::smallStraight() const
{
    uint16_t score = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if (((dices[i].getSide() + 1) == dices[i+1].getSide())
        && ((dices[i+1].getSide() + 1) == dices[i+2].getSide())
        && ((dices[i+2].getSide() + 1) == dices[i+3].getSide()))
        {
            score = 30;
        }
    }

    if (((dices[0].getSide() + 1) == dices[1].getSide())
    && ((dices[1].getSide() + 1) == dices[3].getSide())
    && ((dices[3].getSide() + 1) == dices[4].getSide()))
    {
        score = 30;
    }
    return score;
}

uint16_t Dices::largeStraight() const
{
    uint16_t score = 0;
    if (((dices[0].getSide() + 1) == dices[1].getSide())
    && ((dices[1].getSide() + 1) == dices[2].getSide())
    && ((dices[2].getSide() + 1) == dices[3].getSide())
    && ((dices[3].getSide() + 1) == dices[4].getSide()))
    {
        score = 40;
    }
    return score;
}

uint16_t Dices::fiveOfAKind() const
{
    uint16_t score = 0;
    if ((dices[0].getSide() == dices[1].getSide())
    && (dices[1].getSide() == dices[2].getSide())
    && (dices[2].getSide() == dices[3].getSide())
    && (dices[3].getSide() == dices[4].getSide()))
    {
        score = 50;
    }
    return score;
}

uint16_t Dices::sumOfFive() const
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        score += dice.getSide();
    }
    return score;
}

