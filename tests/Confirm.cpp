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

long multiplyBy2 (long value)
{
    return value * 2L;
}

long long multiplyBy2 (long long value)
{
    return value * 2LL;
}

TEST("Test int confirms")
{
    int result = multiplyBy2(0);
    CONFIRM(0, result);
    result = multiplyBy2(1);
    CONFIRM(2, result);
    result = multiplyBy2(-1);
    CONFIRM(-2, result);
}

TEST("Test long confirms")
{
    long result = multiplyBy2(0L);
    CONFIRM(0L, result);
    result = multiplyBy2(1L);
    CONFIRM(2L, result);
    result = multiplyBy2(-1L);
    CONFIRM(-2L, result);
}

TEST("Test long confirm failure")
{
    std::string reason = "    Expected: 0\n";
    reason += "    Actual  : 2";
    setExpectedFailureReason(reason);
    long result = multiplyBy2(1L);
    CONFIRM(0L, result);
}

TEST("Test long long confirms")
{
    long long result = multiplyBy2(0LL);
    CONFIRM(0LL, result);
    result = multiplyBy2(10'000'000'000LL);
    CONFIRM(20'000'000'000LL, result);
    result = multiplyBy2(-10'000'000'000LL);
    CONFIRM(-20'000'000'000LL, result);
}

TEST("Test long long confirm failure")
{
    std::string reason = "    Expected: 10000000000\n";
    reason += "    Actual  : 20000000000";
    setExpectedFailureReason(reason);
    long long result = multiplyBy2(10'000'000'000LL);
    CONFIRM(10'000'000'000LL, result);
}

TEST("Test string confirms")
{
    std::string result = "abc";
    std::string expected = "abc";
    CONFIRM(expected, result);
}

TEST("Test string confirm failure")
{
    std::string reason = "    Expected: def\n";
    reason += "    Actual  : abc";
    setExpectedFailureReason(reason);
    std::string result = "abc";
    std::string expected = "def";
    CONFIRM(expected, result);
}

TEST("Test bool pointer confirms")
{
    bool result1 = true;
    bool result2 = false;
    bool * pResult1 = &result1;
    bool * pResult2 = &result2;
    CONFIRM_TRUE(*pResult1);
    CONFIRM_FALSE(*pResult2);
}

TEST("Test string and string literal confirms")
{
    std::string result = "abc";
    CONFIRM("abc", result);
}

TEST("Test float confirms")
{
    float f1 = 0.1f;
    float f2 = 0.2f;
    float sum = f1 + f2;
    float expected = 0.3f;
    CONFIRM(expected, sum);
}

TEST("Test double confirms")
{
    double d1 = 0.1;
    double d2 = 0.2;
    double sum = d1 + d2;
    double expected = 0.3;
    CONFIRM(expected, sum);
}

TEST("Test long double confirms")
{
    long double ld1 = 0.1;
    long double ld2 = 0.2;
    long double sum = ld1 + ld2;
    long double expected = 0.3;
    CONFIRM(expected, sum);
}