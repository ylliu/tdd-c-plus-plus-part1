#include "../Test.h"

bool isPassingGrade (int value)
{
    if (value < 60)
    {
        return false;
    }
    return true;
}

TEST("Test passing grades")
{
    bool result = isPassingGrade(0);
    CONFIRM_FALSE(result);
    result = isPassingGrade(100);
    CONFIRM_TRUE(result);
}

bool isNegative(int value) {
    return value < 0;
}

TEST("Test bool confirms"){
    bool result = isNegative(0);
    CONFIRM_FALSE(result);
    result = isNegative(-1);
    CONFIRM_TRUE(result);
}

int multiplyBy2 (int value)
{
    return value * 2;
}

TEST("Test int confirms")
{
    int result = multiplyBy2(0);
    CONFIRM(0, result);
    result = multiplyBy2(1);
    CONFIRM(2, result);
    result = multiplyBy2(-1);
    CONFIRM(-3, result);
}