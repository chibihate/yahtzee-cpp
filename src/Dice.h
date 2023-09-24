#pragma once
#include <iostream>
#include <array>

#define NUMBERS_OF_DICE 5

class Dice
{
private:
    bool isLock;
    uint16_t side;
public:
    Dice();
    ~Dice();
    bool getLock() const;
    void setLock(bool _isLock);
    uint16_t getSide() const;
    void setSide(uint16_t _side);
    uint16_t randomSide();
    virtual void roll();
};

class Dices : public Dice
{
private:
    std::array<Dice, NUMBERS_OF_DICE> dices;
public:
    Dices();
    ~Dices();
    std::array<Dice, NUMBERS_OF_DICE> getValue() const;
    std::array<Dice, NUMBERS_OF_DICE>& getValueMutable();
    void setValue(std::array<Dice, NUMBERS_OF_DICE> _value);
    
    void roll() override;
    void drawSequence(std::string firstCharacter, std::string secondCharacter, bool isCheckLock) const;
    void showDices() const;
    void showChoseDice() const;
    uint16_t aces() const;
    uint16_t twos() const;
    uint16_t threes() const;
    uint16_t fours() const;
    uint16_t fives() const;
    uint16_t sixes() const;
    uint16_t onePair() const;
    uint16_t twoPair() const;
    uint16_t threeOfAKind() const;
    uint16_t fourOfAKind() const;
    uint16_t fullHouse() const;
    uint16_t smallStraight() const;
    uint16_t largeStraight() const;
    uint16_t fiveOfAKind() const;
    uint16_t sumOfFive() const;
};