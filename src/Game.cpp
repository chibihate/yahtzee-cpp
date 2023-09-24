#include <algorithm>
#include "Game.h"

Game::Game()
: dices()
, categories()
{
}

Game::~Game()
{
}

void Game::calculationSection()
{
    uint16_t index = 0;
    Dices dicesSort;
    dicesSort.setValue(dices.getValue());
    std::sort(dicesSort.getValueMutable().begin(), dicesSort.getValueMutable().end(), compareSide);
    for (auto& category: categories.getValueMutable())
    {
        if (category.getLock() == false)
        {
            switch (index)
            {
            case eCategory::Aces:
                category.setScore(dicesSort.aces());
                break;
            case eCategory::Twos:
                category.setScore(dicesSort.twos());
                break;
            case eCategory::Threes:
                category.setScore(dicesSort.threes());
                break;
            case eCategory::Fours:
                category.setScore(dicesSort.fours());
                break;
            case eCategory::Fives:
                category.setScore(dicesSort.fives());
                break;
            case eCategory::Sixes:
                category.setScore(dicesSort.sixes());
                break;
            case eCategory::OnePair:
                category.setScore(dicesSort.onePair());
                break;
            case eCategory::TwoPair:
                category.setScore(dicesSort.twoPair());
                break;
            case eCategory::ThreeOfAKind:
                category.setScore(dicesSort.threeOfAKind());
                break;
            case eCategory::FourOfAKind:
                category.setScore(dicesSort.fourOfAKind());
                break;
            case eCategory::FullHouse:
                category.setScore(dicesSort.fullHouse());
                break;
            case eCategory::SmallStraight:
                category.setScore(dicesSort.smallStraight());
                break;
            case eCategory::LargeStraight:
                category.setScore(dicesSort.largeStraight());
                break;
            case eCategory::FiveOfAKind:
                category.setScore(dicesSort.fiveOfAKind());
                break;
            case eCategory::SumOfFive:
                category.setScore(dicesSort.sumOfFive());
                break;
            default:
                break;
            }
        }
        ++index;
    }
}

void Game::oneRound()
{
    uint16_t attemptTimes = ATTEMP_TIMES_PER_ROUND + 1;
    while (attemptTimes > 0)
    {
        std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
        uint16_t action = UINT16_MAX;
        dices.roll();
        calculationSection();
        while (action != 0)
        {
            if (attemptTimes != 0)
            {
                categories.showSection();
                categories.showTotalScore();
                if (attemptTimes - 1 > 0)
                {
                    dices.showDices();
                    dices.showChoseDice();
                    std::cout << "0 - Roll again" << std::endl;
                    std::cout << "1 -> 5: Choose dice" << std::endl;
                    std::cout << "11 -> 16: Choose upper section" << std::endl;
                    std::cout << "21 -> 28: Choose lower section" << std::endl;
                    std::cout << "Attempt times: " << attemptTimes - 1 << std::endl;
                }
                else
                {
                    dices.showDices();
                    std::cout << "0 - Exit" << std::endl;
                    std::cout << "11 -> 16: Choose upper section" << std::endl;
                    std::cout << "21 -> 28: Choose lower section" << std::endl;
                }
            }
            else
            {
                dices.showDices();
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
                dices.getValueMutable()[action-1].setLock(!dices.getValue()[action-1].getLock());
                break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
                if (categories.getValue()[action - 11].getLock() == false)
                {
                    categories.getValue()[action - 11].setLock(true);
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
            case 28:
                if (categories.getValue()[action - 15].getLock() == false)
                {
                    categories.getValue()[action - 15].setLock(true);
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

void Game::execute()
{
    Categories categories;
    uint16_t attemptTimes = MAX_SIZE;
    while (attemptTimes > 0)
    {
        dices = Dices();
        oneRound();
        --attemptTimes;
    }
    std::cout << "+++++ Final score +++++" << std::endl;
    categories.showTotalScore();
}