#include <gtest/gtest.h>
#include "Dice.h"

class TestDice : public ::testing::Test
{
public:
    TestDice()
    : dice()
    {
    }

    ~TestDice()
    {
    }

    Dice dice;
};

TEST_F(TestDice, defaultConstructor)
{
    ASSERT_FALSE(dice.getLock());
    ASSERT_EQ(1,dice.getSide());
}

TEST_F(TestDice, setSide)
{
    ASSERT_EQ(1,dice.getSide());
    uint16_t expectedValue = 6;

    dice.setSide(expectedValue);
    ASSERT_EQ(expectedValue,dice.getSide());
}

TEST_F(TestDice, setLock)
{
    ASSERT_FALSE(dice.getLock());
    bool expectedValue = true;

    dice.setLock(expectedValue);
    ASSERT_EQ(expectedValue,dice.getLock());
}

TEST_F(TestDice, randomSide)
{
    uint16_t returnValue = 0;

    returnValue = dice.randomSide();
    ASSERT_NE(0,returnValue);
}

TEST_F(TestDice, roll_isLock_nothingChange)
{
    dice.setLock(true);
    dice.setSide(0);

    dice.roll();
    ASSERT_EQ(0,dice.getSide());
}

TEST_F(TestDice, roll_isNotLock_hasChange)
{
    dice.setLock(false);
    dice.setSide(0);

    dice.roll();
    ASSERT_NE(0,dice.getSide());
}

struct T_FiveDicesValue
{
    uint16_t first;
    uint16_t second;
    uint16_t third;
    uint16_t fourth;
    uint16_t fifth;
};

class TestDices : public ::testing::Test
{
public:
    TestDices()
    : dices()
    {
    }

    ~TestDices()
    {
    }

    void setInitializeDices(T_FiveDicesValue _dices)
    {
        dices.getValueMutable()[0].setSide(_dices.first);
        dices.getValueMutable()[1].setSide(_dices.second);
        dices.getValueMutable()[2].setSide(_dices.third);
        dices.getValueMutable()[3].setSide(_dices.fourth);
        dices.getValueMutable()[4].setSide(_dices.fifth);
    }

    Dices dices;
};

TEST_F(TestDices, defaultConstructor)
{
    for (auto& dice: dices.getValue())
    {
        ASSERT_FALSE(dice.getLock());
        ASSERT_EQ(1,dice.getSide());
    }
}

TEST_F(TestDices, getValue)
{
    uint16_t index = 1;
    for (auto& dice: dices.getValue())
    {
        dice.setLock(true);
        dice.setSide(index);
    }

    for (auto& dice: dices.getValue())
    {
        ASSERT_FALSE(dice.getLock());
        ASSERT_EQ(1,dice.getSide());
    }
}

TEST_F(TestDices, getValueMutable)
{
    uint16_t index = 1;
    for (auto& dice: dices.getValueMutable())
    {
        dice.setLock(true);
        dice.setSide(index);
    }

    for (auto& dice: dices.getValue())
    {
        ASSERT_TRUE(dice.getLock());
        ASSERT_NE(0,dice.getSide());
    }
}

TEST_F(TestDices, setValue)
{
    uint16_t index = 1;
    Dices expectedDices;
    for (auto& dice: expectedDices.getValueMutable())
    {
        dice.setLock(true);
        dice.setSide(index);
    }

    dices.setValue(expectedDices.getValue());
    for (auto& dice: dices.getValue())
    {
        ASSERT_TRUE(dice.getLock());
        ASSERT_NE(0,dice.getSide());
    }
}

TEST_F(TestDices, roll)
{
    setInitializeDices(T_FiveDicesValue({0,0,0,0,0}));
    dices.roll();
    for (auto& dice: dices.getValue())
    {
        ASSERT_NE(0,dice.getSide());
    }
}

struct T_BoundaryValue
{
    T_FiveDicesValue dices;
    uint16_t score;
};

class TestAces : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestAces, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.aces();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestAces, 
                        ::testing::Values(
                        T_BoundaryValue({{2,4,3,5,6},0}),
                        T_BoundaryValue({{1,4,3,5,6},1}),
                        T_BoundaryValue({{1,1,3,5,6},2}),
                        T_BoundaryValue({{1,1,1,5,6},3}),
                        T_BoundaryValue({{1,1,1,1,6},4}),
                        T_BoundaryValue({{1,1,1,1,1},5})
                        ));

class TestTwos : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestTwos, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.twos();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestTwos, 
                        ::testing::Values(
                        T_BoundaryValue({{1,4,3,5,6},0}),
                        T_BoundaryValue({{2,4,3,5,6},2}),
                        T_BoundaryValue({{2,2,3,5,6},4}),
                        T_BoundaryValue({{2,2,2,5,6},6}),
                        T_BoundaryValue({{2,2,2,2,6},8}),
                        T_BoundaryValue({{2,2,2,2,2},10})
                        ));

class TestThrees : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestThrees, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.threes();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestThrees, 
                        ::testing::Values(
                        T_BoundaryValue({{1,4,2,5,6},0}),
                        T_BoundaryValue({{3,4,2,5,6},3}),
                        T_BoundaryValue({{3,3,2,5,6},6}),
                        T_BoundaryValue({{3,3,3,5,6},9}),
                        T_BoundaryValue({{3,3,3,3,6},12}),
                        T_BoundaryValue({{3,3,3,3,3},15})
                        ));

class TestFours : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestFours, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.fours();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestFours, 
                        ::testing::Values(
                        T_BoundaryValue({{1,3,2,5,6},0}),
                        T_BoundaryValue({{4,3,2,5,6},4}),
                        T_BoundaryValue({{4,4,2,5,6},8}),
                        T_BoundaryValue({{4,4,4,5,6},12}),
                        T_BoundaryValue({{4,4,4,4,6},16}),
                        T_BoundaryValue({{4,4,4,4,4},20})
                        ));

class TestFives : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestFives, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.fives();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestFives, 
                        ::testing::Values(
                        T_BoundaryValue({{1,3,2,4,6},0}),
                        T_BoundaryValue({{5,3,2,4,6},5}),
                        T_BoundaryValue({{5,5,2,4,6},10}),
                        T_BoundaryValue({{5,5,5,4,6},15}),
                        T_BoundaryValue({{5,5,5,5,6},20}),
                        T_BoundaryValue({{5,5,5,5,5},25})
                        ));

class TestSixes : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestSixes, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.sixes();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestSixes, 
                        ::testing::Values(
                        T_BoundaryValue({{1,3,2,4,5},0}),
                        T_BoundaryValue({{6,3,2,4,5},6}),
                        T_BoundaryValue({{6,6,2,4,5},12}),
                        T_BoundaryValue({{6,6,6,4,5},18}),
                        T_BoundaryValue({{6,6,6,6,5},24}),
                        T_BoundaryValue({{6,6,6,6,6},30})
                        ));

class TestOnePair : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestOnePair, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.onePair();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestOnePair, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,1,3,4},2}),
                        T_BoundaryValue({{1,1,1,2,2},4}),
                        T_BoundaryValue({{2,2,2,6,6},12}),
                        T_BoundaryValue({{1,3,2,6,6},12}),
                        T_BoundaryValue({{1,4,4,5,5},10})
                        ));

class TestTwoPair : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestTwoPair, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.twoPair();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestTwoPair, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,2,3,3},8}),
                        T_BoundaryValue({{1,1,1,2,2},6}),
                        T_BoundaryValue({{3,3,4,4,4},14})
                        ));

class TestThreeOfAKind : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestThreeOfAKind, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.threeOfAKind();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestThreeOfAKind, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,2,3,3},0}),
                        T_BoundaryValue({{1,1,1,2,2},3}),
                        T_BoundaryValue({{3,3,4,4,4},12})
                        ));

class TestFourOfAKind : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestFourOfAKind, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.fourOfAKind();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestFourOfAKind, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,2,3,3},0}),
                        T_BoundaryValue({{1,1,1,1,2},4}),
                        T_BoundaryValue({{3,4,4,4,4},16})
                        ));

class TestFullHouse : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestFullHouse, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.fullHouse();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestFullHouse, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,3,3,3},11}),
                        T_BoundaryValue({{1,1,1,1,2},0}),
                        T_BoundaryValue({{3,3,3,4,4},17})
                        ));

class TestSmallStraight : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestSmallStraight, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.smallStraight();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestSmallStraight, 
                        ::testing::Values(
                        T_BoundaryValue({{1,3,4,5,6},30}),
                        T_BoundaryValue({{1,1,3,3,3},0}),
                        T_BoundaryValue({{1,2,2,3,4},30}),
                        T_BoundaryValue({{1,2,3,4,6},30})
                        ));

class TestLargeStraight : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestLargeStraight, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.largeStraight();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestLargeStraight, 
                        ::testing::Values(
                        T_BoundaryValue({{1,3,4,5,6},0}),
                        T_BoundaryValue({{1,1,3,3,3},0}),
                        T_BoundaryValue({{2,3,4,5,6},40}),
                        T_BoundaryValue({{1,2,3,4,5},40})
                        ));

class TestFiveOfAKind : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestFiveOfAKind, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.fiveOfAKind();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestFiveOfAKind, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},0}),
                        T_BoundaryValue({{1,1,1,1,1},50}),
                        T_BoundaryValue({{2,2,2,2,2},50}),
                        T_BoundaryValue({{3,3,3,3,3},50}),
                        T_BoundaryValue({{4,4,4,4,4},50}),
                        T_BoundaryValue({{5,5,5,5,5},50}),
                        T_BoundaryValue({{6,6,6,6,6},50})
                        ));

class TestSumOfFive : public TestDices, public testing::WithParamInterface<T_BoundaryValue>
{
};
TEST_P(TestSumOfFive, TestParam)
{
    uint16_t returnValue = 0;
    setInitializeDices(GetParam().dices);
    returnValue = dices.sumOfFive();
    ASSERT_EQ(GetParam().score, returnValue);
}
INSTANTIATE_TEST_SUITE_P(TestParam, 
                        TestSumOfFive, 
                        ::testing::Values(
                        T_BoundaryValue({{1,2,3,4,5},15}),
                        T_BoundaryValue({{1,1,1,1,1},5}),
                        T_BoundaryValue({{2,2,2,2,2},10}),
                        T_BoundaryValue({{3,3,3,3,3},15}),
                        T_BoundaryValue({{4,4,4,4,4},20}),
                        T_BoundaryValue({{5,5,5,5,5},25}),
                        T_BoundaryValue({{6,6,6,6,6},30})
                        ));