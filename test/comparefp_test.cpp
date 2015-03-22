#include <comparefp.h>

#include <gtest/gtest.h>

using namespace ::testing;
using namespace ::useful;

TEST(CompareFPTest, testFloatingPointAlmostEqual)
{

    double d1 = 0.12345678;
    double x1 = (d1*2.0)-d1;
    double x2 = (d1+d1)/2.0;
    FloatingPoint<double> a1(x1);
    FloatingPoint<double> a2(x2);
    EXPECT_TRUE(a1.almostEqual(a2));

    double x3 = (0.12345678*2)-0.123456779999;
    FloatingPoint<double> a3(x3);
    EXPECT_FALSE(a1.almostEqual(a3));

    double x4 = x1 - x2;
    FloatingPoint<double> a4(x4);
    EXPECT_TRUE(a4.almostEqual(0.0))<<"x4="<<x4;

    {
        double d1 = 12345678.9999999;
        double x1 = (d1*2.0)-d1;
        double x2 = (d1+d1)/2.0;
        FloatingPoint<double> a1(x1);
        FloatingPoint<double> a2(x2);
        EXPECT_TRUE(a1.almostEqual(a2));
    }
    {
        double d1 = 12345678999999.9;
        double x1 = (d1*2.0)-d1;
        double x2 = (d1+d1)/2.0 - 0.1;
        FloatingPoint<double> a1(x1);
        FloatingPoint<double> a2(x2);
        EXPECT_FALSE(a1.almostEqual(a2));
    }
}

TEST(CompareFPTest, testNonMemberAlmostEqual)
{
    double d1 = 0.12345678;
    double x1 = (d1*2.0)-d1;
    double x2 = (d1+d1)/2.0;
    EXPECT_TRUE(almostEqual(x1, x2));

    double x3 = (0.12345678*2)-0.123456779999;
    EXPECT_TRUE(almostEqual(x1, x3));

    double x4 = x1 - x2;
    EXPECT_TRUE(almostEqual(x4, 0.0))<<"x4="<<x4;

    {
        double d1 = 12345678.9999999;
        double x1 = (d1*2.0)-d1;
        double x2 = (d1+d1)/2.0;
        EXPECT_TRUE(almostEqual(x1, x2));
    }
    {
        double d1 = 12345678999999.9;
        double x1 = (d1*2.0)-d1;
        double x2 = (d1+d1)/2.0 - 0.1;
        EXPECT_FALSE(almostEqual(x1, x2));
    }
}
