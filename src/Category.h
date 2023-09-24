#pragma once
#include <iostream>
#include <array>

enum eCategory
{
    Aces,
    Twos,
    Threes,
    Fours,
    Fives,
    Sixes,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    FourOfAKind,
    FullHouse,
    SmallStraight,
    LargeStraight,
    FiveOfAKind,
    SumOfFive,
    MAX_SIZE
};

std::string covertCategoryToString(eCategory category);

class Category
{
private:
    bool isLock;
    uint16_t score;
public:
    Category();
    ~Category();
    bool getLock() const;
    void setLock(bool _isLock);
    uint16_t getScore() const;
    void setScore(uint16_t _score);
};

class Categories : public Category
{
private:
    std::array<Category, eCategory::MAX_SIZE> categories;
public:
    Categories();
    ~Categories();
    std::array<Category, eCategory::MAX_SIZE> getValue() const;
    std::array<Category, eCategory::MAX_SIZE>& getValueMutable();
    void setValue(std::array<Category, eCategory::MAX_SIZE> _categories);
    void showTotalScore() const;
    void showSection() const;
};