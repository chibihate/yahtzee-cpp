#include <iostream>
#include <cstdint>
#include <array>
#include <algorithm>

#define NUMBERS_OF_DICE 5
#define ATTEMP_TIMES_PER_ROUND 3
#define ATTEMP_TIMES_PER_GAME 13

enum eCategory
{
    Aces,
    Twos,
    Threes,
    Fours,
    Fives,
    Sixes,
    ThreeOfAKind,
    FourOfAKind,
    FullHouse,
    SmallStraight,
    LargeStraight,
    Yahtzee,
    Chance,
    MAX_SIZE
};

std::string covertCategoryToString(eCategory category)
{
    std::string stringCovert;
    switch (category)
    {
    case eCategory::Aces:
        stringCovert = "Aces";
        break;
    case eCategory::Twos:
        stringCovert = "Twos";
        break;
    case eCategory::Threes:
        stringCovert = "Threes";
        break;
    case eCategory::Fours:
        stringCovert = "Fours";
        break;
    case eCategory::Fives:
        stringCovert = "Fives";
        break;
    case eCategory::Sixes:
        stringCovert = "Sixes";
        break;
    case eCategory::ThreeOfAKind:
        stringCovert = "ThreeOfAKind";
        break;
    case eCategory::FourOfAKind:
        stringCovert = "FourOfAKind";
        break;
    case eCategory::FullHouse:
        stringCovert = "FullHouse";
        break;
    case eCategory::SmallStraight:
        stringCovert = "SmallStraight";
        break;
    case eCategory::LargeStraight:
        stringCovert = "LargeStraight";
        break;
    case eCategory::Yahtzee:
        stringCovert = "Yahtzee";
        break;
    case eCategory::Chance:
        stringCovert = "Chance";
        break;
    default:
        break;
    }
    return stringCovert;
}

struct Dice
{
    uint16_t side;
    bool isLock;
};

struct Category
{
    uint16_t score;
    bool isLock;
};

struct
{
    bool operator()(Dice a, Dice b) const { return a.side < b.side; }
} compareSide;

uint16_t roll()
{
    uint16_t side = 1;
    side = std::rand() % 6 + 1;
    return side;
}

void rollDices(std::array<Dice, NUMBERS_OF_DICE>& dices)
{
    for (auto& dice: dices)
    {
        if (dice.isLock == false)
        {
            dice.side = roll();
        }
    }
}

void drawSequence(std::array<Dice, NUMBERS_OF_DICE> dices, std::string firstCharacter, std::string secondCharacter, bool isCheckLock)
{
    if (isCheckLock)
    {
        for (auto dice: dices)
        {
            if (dice.isLock)
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
                std::cout << firstCharacter << " " << dice.side << " ";
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

void showDices(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    drawSequence(dices, " ", "-", false);
    drawSequence(dices, "|", "side", false);
    drawSequence(dices, " ", "-", false);
}

void showAllDices(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    drawSequence(dices, " ", "-", false);
    drawSequence(dices, "|", "side", false);
    drawSequence(dices, " ", "-", false);
}

void showChoseDice(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    drawSequence(dices, "|", "x", true);
    drawSequence(dices, " ", "-", false);
    drawSequence(dices, " ", "^", false);
    drawSequence(dices, " ", "|", false);
    drawSequence(dices, " ", "index", false);
}

uint16_t aces(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 1)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t twos(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 2)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t threes(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 3)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t fours(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 4)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t fives(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 5)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t sixes(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        if (dice.side == 6)
        {
            score += dice.side;
        }
    }
    return score;
}

uint16_t threeOfAKind(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for ( int i = 0; i < 3; i++ )
    {
        if ((dices[i].side == dices[i+1].side)
        && (dices[i+1].side == dices[i+2].side))
        {
            score = dices[i].side*3;
        }
    }
    return score;
}

uint16_t fourOfAKind(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if ((dices[i].side == dices[i+1].side)
        && (dices[i+1].side == dices[i+2].side)
        && (dices[i+2].side == dices[i+3].side))
        {
            score = dices[i].side*4;
        }
    }
    return score;
}

uint16_t fullHouse(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    uint16_t sideOfThreeOfAKind = threeOfAKind(dices)/3;

    if (sideOfThreeOfAKind == 0)
    {
        return score;
    }

    for ( int i = 0; i < 4; i++ )
    {
        if (dices[i].side == sideOfThreeOfAKind)
        {
            continue;
        }
        else
        {
            if (dices[i].side == dices[i+1].side)
            {
                score = 25;
            }
        }
    }
    return score;
}

uint16_t smallStraight(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if (((dices[i].side + 1) == dices[i+1].side)
        && ((dices[i+1].side + 1) == dices[i+2].side)
        && ((dices[i+2].side + 1) == dices[i+3].side))
        {
            score = 30;
        }
    }
    return score;
}

uint16_t largeStraight(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    if (((dices[0].side + 1) == dices[1].side)
    && ((dices[1].side + 1) == dices[2].side)
    && ((dices[2].side + 1) == dices[3].side)
    && ((dices[3].side + 1) == dices[4].side))
    {
        score = 40;
    }
    return score;
}

uint16_t yahtzee(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    if ((dices[0].side == dices[1].side)
    && (dices[1].side == dices[2].side)
    && (dices[2].side == dices[3].side)
    && (dices[3].side == dices[4].side))
    {
        score = 50;
    }
    return score;
}

uint16_t chance(std::array<Dice, NUMBERS_OF_DICE> dices)
{
    uint16_t score = 0;
    for (auto dice: dices)
    {
        score += dice.side;
    }
    return score;
}

void calculationSection(std::array<Dice, NUMBERS_OF_DICE> dices, std::array<Category, eCategory::MAX_SIZE>& categories)
{
    uint16_t index = 0;
    std::array<Dice, NUMBERS_OF_DICE> dicesSort = dices;
    std::sort(dicesSort.begin(), dicesSort.end(), compareSide);
    for (auto& category: categories)
    {
        if (category.isLock == false)
        {
            switch (index)
            {
            case eCategory::Aces:
                category.score = aces(dicesSort);
                break;
            case eCategory::Twos:
                category.score = twos(dicesSort);
                break;
            case eCategory::Threes:
                category.score = threes(dicesSort);
                break;
            case eCategory::Fours:
                category.score = fours(dicesSort);
                break;
            case eCategory::Fives:
                category.score = fives(dicesSort);
                break;
            case eCategory::Sixes:
                category.score = sixes(dicesSort);
                break;
            case eCategory::ThreeOfAKind:
                category.score = threeOfAKind(dicesSort);
                break;
            case eCategory::FourOfAKind:
                category.score = fourOfAKind(dicesSort);
                break;
            case eCategory::FullHouse:
                category.score = fullHouse(dicesSort);
                break;
            case eCategory::SmallStraight:
                category.score = smallStraight(dicesSort);
                break;
            case eCategory::LargeStraight:
                category.score = largeStraight(dicesSort);
                break;
            case eCategory::Yahtzee:
                category.score = yahtzee(dicesSort);
                break;
            case eCategory::Chance:
                category.score = chance(dicesSort);
                break;
            default:
                break;
            }
        }
        ++index;
    }
}

void showTotalScore(std::array<Category, eCategory::MAX_SIZE> categories)
{
    uint16_t score = 0;
    uint16_t scoreBonus = 0;
    for ( int i = 0; i < 6; i++ )
    {
        scoreBonus += categories[0].score;
    }
    if (scoreBonus >= 63)
    {
        score += 35;
    }
    for (auto category: categories)
    {
        if (category.isLock)
        {
            score += category.score;
        }
    }
    std::cout << "Total score: " << score << std::endl;
}

void showSection(std::array<Category, eCategory::MAX_SIZE> categories)
{
    uint16_t index = 0;
    std::cout << "Index|Chose|Score|Description" << std::endl;
    for (auto category: categories)
    {
        if (index < 6)
        {
            std::cout << "  " << (index+11) << " ";
        }
        else
        {
            std::cout << "  " << (index+15) << " ";
        }
        if (category.isLock)
        {
            std::cout << "|  x  ";
        }
        else
        {
            std::cout << "|     ";
        }
        if (category.score > 9)
        {
            std::cout << "|  " << category.score << " ";
        }
        else
        {
            std::cout << "|   " << category.score << " ";
        }
        std::cout << "|" << covertCategoryToString(eCategory(index)) << std::endl;
        ++index;
    }
}

void oneRound(std::array<Dice, NUMBERS_OF_DICE>& dices, std::array<Category, eCategory::MAX_SIZE>& categories)
{
    uint16_t attemptTimes = ATTEMP_TIMES_PER_ROUND + 1;
    while (attemptTimes > 0)
    {
        std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
        uint16_t action = UINT16_MAX;
        rollDices(dices);
        calculationSection(dices, categories);
        while (action != 0)
        {
            if (attemptTimes != 0)
            {
                showSection(categories);
                showTotalScore(categories);
                if (attemptTimes - 1 > 0)
                {
                    showAllDices(dices);
                    showChoseDice(dices);
                    std::cout << "0 - Roll again" << std::endl;
                    std::cout << "1 -> 5: Choose dice" << std::endl;
                    std::cout << "11 -> 16: Choose upper section" << std::endl;
                    std::cout << "21 -> 27: Choose lower section" << std::endl;
                    std::cout << "Attempt times: " << attemptTimes - 1 << std::endl;
                }
                else
                {
                    showAllDices(dices);
                    std::cout << "0 - Exit" << std::endl;
                    std::cout << "11 -> 16: Choose upper section" << std::endl;
                    std::cout << "21 -> 27: Choose lower section" << std::endl;
                }
            }
            else
            {
                showDices(dices);
                break;
            }
            std::cout << "Please insert your action: ";
            std::cin >> action;
            switch (action)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                dices[action-1].isLock = !dices[action-1].isLock;
                break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
                if (categories[action - 11].isLock == false)
                {
                    categories[action - 11].isLock = true;
                    action = 0;
                    attemptTimes = 1;
                }
                break;
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
                if (categories[action - 15].isLock == false)
                {
                    categories[action - 15].isLock = true;
                    action = 0;
                    attemptTimes = 1;
                }
                break;
            case 0:
            default:
                break;
            }
        }
        --attemptTimes;
    }
}

void playGame()
{
    uint16_t numberOfDices = NUMBERS_OF_DICE;
    std::array<Dice, NUMBERS_OF_DICE> dices;
    std::array<Dice, NUMBERS_OF_DICE> dicesTemp;
    std::array<Category, eCategory::MAX_SIZE> categories;
    categories.fill({0,false});
    uint16_t attemptTimes = ATTEMP_TIMES_PER_GAME;
    while (attemptTimes > 0)
    {
        dices.fill({1,false});
        oneRound(dices,categories);
        --attemptTimes;
    }
    std::cout << "+++++ Final score +++++" << std::endl;
    showTotalScore(categories);
}

int main()
{
    uint16_t action;
    std::cout << "Do you want to play game?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
    std::cin >> action;
    while(true)
    {
        if (action == 1)
        {
            playGame();
        }
        else
        {
            break;
        }
        std::cout << "Do you want to play game again?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
        std::cin >> action;
    }
    return 0;
}