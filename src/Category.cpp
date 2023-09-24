#include "Category.h"

Category::Category()
: isLock(false)
, score(0)
{
}

Category::~Category()
{
}

bool Category::getLock() const
{
    return isLock;
}

void Category::setLock(bool _isLock)
{
    score = _isLock;
}

uint16_t Category::getScore() const
{
    return score;
}

void Category::setScore(uint16_t _score)
{
    score = _score;
}

Categories::Categories()
{
    for (auto& category: categories)
    {
        category = Category();
    }
}

Categories::~Categories()
{
}

std::array<Category, eCategory::MAX_SIZE> Categories::getValue() const
{
    return categories;
}

std::array<Category, eCategory::MAX_SIZE>& Categories::getValueMutable()
{
    return categories;
}

void Categories::setValue(std::array<Category, eCategory::MAX_SIZE> _categories)
{
    categories = _categories;
}

void Categories::showTotalScore() const
{
    uint16_t score = 0;
    uint16_t scoreBonus = 0;
    for ( int i = 0; i < 6; i++ )
    {
        scoreBonus += categories[0].getScore();
    }
    if (scoreBonus >= 63)
    {
        score += 35;
    }
    for (auto category: categories)
    {
        if (category.getLock())
        {
            score += category.getScore();
        }
    }
    std::cout << "Total score: " << score << std::endl;
}

void Categories::showSection() const
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
        if (category.getLock())
        {
            std::cout << "|  x  ";
        }
        else
        {
            std::cout << "|     ";
        }
        if (category.getScore() > 9)
        {
            std::cout << "|  " << category.getScore() << " ";
        }
        else
        {
            std::cout << "|   " << category.getScore() << " ";
        }
        std::cout << "|" << covertCategoryToString(eCategory(index)) << std::endl;
        ++index;
    }
}

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
    case eCategory::OnePair:
        stringCovert = "One Pair";
        break;
    case eCategory::TwoPair:
        stringCovert = "Two Pair";
        break;
    case eCategory::ThreeOfAKind:
        stringCovert = "Three Of A Kind";
        break;
    case eCategory::FourOfAKind:
        stringCovert = "Four Of A Kind";
        break;
    case eCategory::FullHouse:
        stringCovert = "Full House";
        break;
    case eCategory::SmallStraight:
        stringCovert = "Small Straight";
        break;
    case eCategory::LargeStraight:
        stringCovert = "Large Straight";
        break;
    case eCategory::FiveOfAKind:
        stringCovert = "Five Of A Kind";
        break;
    case eCategory::SumOfFive:
        stringCovert = "Sum Of Five";
        break;
    default:
        break;
    }
    return stringCovert;
}