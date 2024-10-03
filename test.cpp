#include "pch.h"
#include "MathVector.h"


TEST(ConstructorValuesTest, PositiveInput) {
    Vector a(0.25, 36, 1.4, 7, 3.33, 9);
    EXPECT_EQ(a.GetStartX(), 0.25);
    EXPECT_EQ(a.GetStartY(), 36);
    EXPECT_EQ(a.GetStartZ(), 1.4);
    EXPECT_EQ(a.GetEndX(), 7);
    EXPECT_EQ(a.GetEndY(), 3.33);
    EXPECT_EQ(a.GetEndZ(), 9);
}

TEST(ConstructorValuesTest, DifferentInput) {
    Vector a(-0.25, 0, -1.4, -7, 0.4, -9.79);
    EXPECT_EQ(a.GetStartX(), -0.25);
    EXPECT_EQ(a.GetStartY(), 0);
    EXPECT_EQ(a.GetStartZ(), -1.4);
    EXPECT_EQ(a.GetEndX(), -7);
    EXPECT_EQ(a.GetEndY(), 0.4);
    EXPECT_EQ(a.GetEndZ(), -9.79);
}

TEST(ConstructorAutoTest, SameValues) {
    Vector a;
    EXPECT_EQ(a.GetStartX(), 0);
    EXPECT_EQ(a.GetStartY(), 0);
    EXPECT_EQ(a.GetStartZ(), 0);
    EXPECT_EQ(a.GetEndX(), 1);
    EXPECT_EQ(a.GetEndY(), 2);
    EXPECT_EQ(a.GetEndZ(), 3);
}

TEST(CopyConstructorTest, SameCopyValues) {
    Vector a;
    Vector b = a;
    EXPECT_EQ(b.GetStartX(), 0);
    EXPECT_EQ(b.GetStartY(), 0);
    EXPECT_EQ(b.GetStartZ(), 0);
    EXPECT_EQ(b.GetEndX(), 1);
    EXPECT_EQ(b.GetEndY(), 2);
    EXPECT_EQ(b.GetEndZ(), 3);
}

TEST(CoordinateDifferenceTest, GetsPositiveOutput) {
    Vector a;
    EXPECT_EQ(a.CalculateLength(), sqrt(14));
}

TEST(CoordinateDifferenceTest, GetsZeroOutput) {
    Vector a(1, 0, -2.5, 1, 0, -2.5);
    EXPECT_EQ(a.CalculateLength(), 0);
}

TEST(SetStartCoordinatesTest, CorrectCoordinates) {
    Vector a;
    a.SetStartCoordinates(-0.25, 11, 3.47);
    EXPECT_EQ(a.GetStartX(), -0.25);
    EXPECT_EQ(a.GetStartY(), 11);
    EXPECT_EQ(a.GetStartZ(), 3.47);
}

TEST(SetEndCoordinatesTest, CorrectCoordinates) {
    Vector a;
    a.SetEndCoordinates(0, -18, 6.78);
    EXPECT_EQ(a.GetEndX(), 0);
    EXPECT_EQ(a.GetEndY(), -18);
    EXPECT_EQ(a.GetEndZ(), 6.78);
}

TEST(OperatorPlusTest, Sum) {
    Vector a;
    Vector b(-1, 0.25, 11, -3.33, 4, 5);
    Vector c = a + b;
    EXPECT_EQ(c.GetStartX(), 0);
    EXPECT_EQ(c.GetStartY(), 0);
    EXPECT_EQ(c.GetStartZ(), 0);
    EXPECT_EQ(c.GetEndX(), -1.33);
    EXPECT_EQ(c.GetEndY(), 5.75);
    EXPECT_EQ(c.GetEndZ(), -3);
}

TEST(OperatorPlusEqualsTest, PlusEq) {
    Vector a;
    Vector b(0, 15.48, -40.9, 3.529, 1, -18);
    a += b;
    EXPECT_EQ(a.GetStartX(), 0);
    EXPECT_EQ(a.GetStartY(), 0);
    EXPECT_EQ(a.GetStartZ(), 0);
    EXPECT_EQ(a.GetEndX(), 4.529);
    EXPECT_EQ(a.GetEndY(), -12.48);
    EXPECT_EQ(a.GetEndZ(), 25.9);
}

TEST(OperatorMinusTest, Difference) {
    Vector a;
    Vector b(17.3, 58.45, -7.1, -52, 703, 5729);
    Vector c = a - b;
    EXPECT_EQ(c.GetStartX(), -69.3);
    EXPECT_EQ(c.GetStartY(), 644.55);
    EXPECT_EQ(c.GetStartZ(), 5736.1);
    EXPECT_EQ(c.GetEndX(), 1);
    EXPECT_EQ(c.GetEndY(), 2);
    EXPECT_EQ(c.GetEndZ(), 3);
}

TEST(OperatorMinusEqualsTest, MinusEq) {
    Vector a;
    Vector b(0.25, 11, -16.3, 7, 0.05, 1);
    a -= b;
    EXPECT_EQ(a.GetStartX(), 6.75);
    EXPECT_EQ(a.GetStartY(), -10.95);
    EXPECT_EQ(a.GetStartZ(), 17.3);
    EXPECT_EQ(a.GetEndX(), 1);
    EXPECT_EQ(a.GetEndY(), 2);
    EXPECT_EQ(a.GetEndZ(), 3);
}

TEST(OperatorMultiplicationTest, VectorMultiply) {
    Vector a;
    Vector b(11.75, 2.228, 5.5, -999.9, 32.7, 36.6);
    Vector c = a * b;
    EXPECT_EQ(c.GetStartX(), 0);
    EXPECT_EQ(c.GetStartY(), 0);
    EXPECT_EQ(c.GetStartZ(), 0);
    EXPECT_NEAR(c.GetEndX(), -29.22, 0.01);
    EXPECT_NEAR(c.GetEndY(), -3066.05, 0.01);
    EXPECT_NEAR(c.GetEndZ(), 2053.772, 0.01);
}

TEST(OperatorMultiplicationEqualsTeat, VectorMultEq) {
    Vector a;
    Vector b(115.0, -2.05, 3.5, -1.9, 12.7, -1);
    a *= b;
    EXPECT_EQ(a.GetStartX(), 0);
    EXPECT_EQ(a.GetStartY(), 0);
    EXPECT_EQ(a.GetStartZ(), 0);
    EXPECT_NEAR(a.GetEndX(), -53.25, 0.01);
    EXPECT_NEAR(a.GetEndY(), -346.2, 0.01);
    EXPECT_NEAR(a.GetEndZ(), 248.55, 0.01);
}

TEST(OperatorMultiplicationTest, ScalarMultiply) {
    Vector a(0, -12, 0.1, 3, 6.81, 0.32);
    Vector b(18, -0.5, 193, 0, 0.25, -8.7);
    double scalarProduct = a * &b;
    EXPECT_EQ(scalarProduct, -84.2665);
}

TEST(OperatorMultiplicationTest, ValueVectorMultiply) {
    Vector a(-0.5, 7.11, -1, 18, 0.35, -0.678);
    Vector b = -1.5 * a;
    EXPECT_EQ(b.GetStartX(), 0.75);
    EXPECT_DOUBLE_EQ(b.GetStartY(), -10.665);
    EXPECT_EQ(b.GetStartZ(), 1.5);
    EXPECT_EQ(b.GetEndX(), -27);
    EXPECT_DOUBLE_EQ(b.GetEndY(), -0.525);
    EXPECT_DOUBLE_EQ(b.GetEndZ(), 1.017);
}

TEST(OperatorMultiplicationTest, VectorValueMultiply) {
    Vector a(0.17, -25.3, 13, 0.004, -7.8, 0.65);
    Vector b = a * 1.33;
    EXPECT_DOUBLE_EQ(b.GetStartX(), 0.2261);
    EXPECT_EQ(b.GetStartY(), -33.649);
    EXPECT_EQ(b.GetStartZ(), 17.29);
    EXPECT_EQ(b.GetEndX(), 0.00532);
    EXPECT_EQ(b.GetEndY(), -10.374);
    EXPECT_EQ(b.GetEndZ(), 0.8645);
}

TEST(OperatorMultiplicatonEqualTest, VectorValueMultEq) {
    Vector a(11.7, -23.546, -1.025, 7, -36214, 177);
    a *= -0.27;
    EXPECT_EQ(a.GetStartX(), -3.159);
    EXPECT_EQ(a.GetStartY(), 6.35742);
    EXPECT_EQ(a.GetStartZ(), 0.27675);
    EXPECT_DOUBLE_EQ(a.GetEndX(), -1.89);
    EXPECT_EQ(a.GetEndY(), 9777.78);
    EXPECT_DOUBLE_EQ(a.GetEndZ(), -47.79);
}

TEST(OperatorDivisionTest, CatchException) {
    Vector a(1.7, -0.2, -56.12, 4, 0.145, -7.36);
    Vector b;
    ASSERT_THROW(a / b, runtime_error);
}

TEST(OperatorDivisionTest, NoCatchException) {
    Vector a;
    Vector b(0.33, 18, 7.235, -9.9, 5.124, 0.3);
    ASSERT_NO_THROW(a / b, runtime_error);
}

TEST(OperatorDivisionTest, AccurateDivision) {
    Vector a(0.5, 0, 3, -9.9, 11, -63);
    Vector b(1, 2, -3, -4, 5, 6);
    Vector c = a / b;
    EXPECT_DOUBLE_EQ(c.GetStartX(), 0.5);
    EXPECT_DOUBLE_EQ(c.GetStartY(), 0);
    EXPECT_DOUBLE_EQ(c.GetStartZ(), -1);
    EXPECT_DOUBLE_EQ(c.GetEndX(), 2.475);
    EXPECT_DOUBLE_EQ(c.GetEndY(), 2.2);
    EXPECT_DOUBLE_EQ(c.GetEndZ(), -10.5);
}

TEST(OperatorDivisionEqualTest, CatchException) {
    Vector a(0.888, 1.2, -89, 7.32, 5, -78.102);
    Vector b(12.1, 0, 7, -9, 0.25, 0);
    ASSERT_THROW(a /= b, runtime_error);
}

TEST(OperatorDivisionEqualTest, CatchNoException) {
    Vector a(11, -0.23, 7, -78.321, 0.2567, 1.03);
    Vector b(0.11, -9.8, -1234.56, 11.023, 7, 9.89);
    ASSERT_NO_THROW(a /= b, runtime_error);
}

TEST(OperatorDivisionEqualTest, DivisEq) {
    Vector a(-0.25, 4.7, 8, -3.2, -1.1, 0);
    Vector b(11, -7.4, 0.3, -2.1, 14, -6.7);
    a /= b;
    EXPECT_NEAR(a.GetStartX(), -0.0227, 0.0001);
    EXPECT_NEAR(a.GetStartY(), -0.6351, 0.0001);
    EXPECT_NEAR(a.GetStartZ(), 26.667, 0.001);
    EXPECT_NEAR(a.GetEndX(), 1.5238, 0.0001);
    EXPECT_NEAR(a.GetEndY(), -0.07857, 0.0001);
    EXPECT_DOUBLE_EQ(a.GetEndZ(), -0);
}

TEST(OperatorCosineTest, CatchException) {
    Vector a(1.5, 3.3, -4.7, 1.5, 3.3, -4.7);
    Vector b(11.7, -9.9, -7, 11.7, -9.9, -7);
    ASSERT_THROW(a ^ b, runtime_error);
}

TEST(OperatorCosineTest, CatchNoException) {
    Vector a(0.46, -0.58, 0.05, -0.5, 0.35, 0.33);
    Vector b(10.35, -4.68, 25.8, 65.01, 89.3, -85.4);
    ASSERT_NO_THROW(a ^ b, runtime_error);
}

TEST(OperatorCosineTest, GetCorrectCosine) {
    Vector a(0, -12, 0.1, 3, 6.81, 0.32);
    Vector b(-0.5, 7.11, -1, 18, 0.35, -0.678);
    EXPECT_NEAR(a ^ b, -0.190767, 0.00001);
}

TEST(OperatorGreaterTest, ExpectTrue) {
    Vector a(0.11, -9, -54.3, -78.01, 12, 3.3); //99.5491
    Vector b(0.47, -99, -78.32, 0.01, 14, 0.5); //137.7745
    EXPECT_TRUE(b > a);
}

TEST(OperatorGreaterTest, ExpectFalse) {
    Vector a(12.68, -6.3, 7.02, -9.32, 0.1, 4);//23.1102
    Vector b(-9, -72.01, 1, 0.005, 6.3, -45);//91.27
    EXPECT_FALSE(a > b);
}

TEST(OperatorGreaterEqualTest, ExpectBiggerTrue) {
    Vector a(0.21, -5.69, -8, 0.45, -6.79, -7);//1.50586
    Vector b(1, 8, 7, -23, 0.658, -0.48);//26.189
    EXPECT_TRUE(b >= a);
}

TEST(OperatorGreaterEqualTest, ExpectEqualTrue) {
    Vector a(0.21, -98, -7.45, 0.12, -3.65, 4.1);
    Vector b = a;
    EXPECT_TRUE(a >= b);
}

TEST(OperatorGreaterEqualTest, ExpectLessFalse) {
    Vector a(0.12, -0.1, -9.3, -0.32, 0.45, 7.2);//16.615
    Vector b(11.7, -9.6, -3.02, -1.012, 0.47, 8);//19.607
    EXPECT_FALSE(a >= b);
}

TEST(OperatorLessTest, ExpectTrue) {
    Vector a(-11.3, 0.24, 3.7, -89.21, 0.001, 4.02);//77.911
    Vector b;//3.742
    EXPECT_TRUE(b < a);
}

TEST(OperatorLessTest, ExpectFalse) {
    Vector a(0.11, 4, -3.3, -2356, -78.012, 0);
    Vector b = a;
    EXPECT_FALSE(a < b);
}

TEST(OperatorLessEqualTest, ExpectLessTrue) {
    Vector a(0.11, -6.3, 5.7, -0.09, 11.3, 0.07);//18.48
    Vector b(1.025, -3.6, -8.79, 0.0004, -2.3, 7.7);//16.57
    EXPECT_TRUE(b <= b);
}

TEST(OperatorLessEqualTest, ExpectFalse) {
    Vector a(0.11, -6.3, 5.7, -0.09, 11.3, 0.07);//18.48
    Vector b;//3.742
    EXPECT_FALSE(a <= b);
}

TEST(OperatorLessEqualTest, ExpectEqualTrue) {
    Vector a(0.12, -3.6, -78.25, 0.07, 11, -9);
    Vector b = a;
    EXPECT_TRUE(a <= b);
}

TEST(OperatorAssignmentTest, ExpectTrue) {
    Vector a(0.11, -78, -3.6, -5987, 0.1456, -3.3);
    Vector b = a;
    EXPECT_TRUE(a == b);
}

TEST(OperatorAssignmentTest, ExpectFalse) {
    Vector a(0.001, -0.3, -89.3, -65.24, -0.0005, 1);
    Vector b;
    EXPECT_FALSE(a == b);
}

TEST(OperatorNotEqualTest, ExpectTrue) {
    Vector a;
    Vector b(0.11, -9.87, 7.35, -0.005, 23.6, 0.001);
    EXPECT_TRUE(a != b);
}

TEST(OperatorNotEqualTest, ExpectFalse) {
    Vector a, b;
    EXPECT_FALSE(a != b);
}

TEST(OperatorMakeEqualTest, CorrectValues) {
    Vector a(1.03, -9, -89.32, 0.05, -98.6, 0.002);
    Vector b;
    b = a;
    EXPECT_EQ(b.GetStartX(), 1.03);
    EXPECT_EQ(b.GetStartY(), -9);
    EXPECT_EQ(b.GetStartZ(), -89.32);
    EXPECT_EQ(b.GetEndX(), 0.05);
    EXPECT_EQ(b.GetEndY(), -98.6);
    EXPECT_EQ(b.GetEndZ(), 0.002);
}

TEST(OperatorMoveAssignmentTest, OtherZero) {
    Vector a;
    Vector b(-1, 0.25, 11, -3.33, 4, 5);
    b = move(a);

    EXPECT_EQ(b.GetStartX(), 0);
    EXPECT_EQ(b.GetStartY(), 0);
    EXPECT_EQ(b.GetStartZ(), 0);
    EXPECT_EQ(b.GetEndX(), 1);
    EXPECT_EQ(b.GetEndY(), 2);
    EXPECT_EQ(b.GetEndZ(), 3);

    EXPECT_EQ(a.GetStartX(), 0);
    EXPECT_EQ(a.GetStartY(), 0);
    EXPECT_EQ(a.GetStartZ(), 0);
    EXPECT_EQ(a.GetEndX(), 0);
    EXPECT_EQ(a.GetEndY(), 0);
    EXPECT_EQ(a.GetEndZ(), 0);
}

TEST(OperatorOutputTest, CorrectOutput) {
    Vector a;
    ostringstream output;
    output << a;
    string expectedOutput = "\nStart:\t(0, 0, 0)\nEnd:\t(1, 2, 3)\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(OperatorInputTest, CorrectInput) {
    Vector a;
    istringstream input("1 -8.5 11 -7.4 0.25 3");
    input >> a;
    EXPECT_EQ(a.GetStartX(), 1);
    EXPECT_EQ(a.GetStartY(), -8.5);
    EXPECT_EQ(a.GetStartZ(), 11);
    EXPECT_EQ(a.GetEndX(), -7.4);
    EXPECT_EQ(a.GetEndY(), 0.25);
    EXPECT_EQ(a.GetEndZ(), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}