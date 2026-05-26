#include <gtest/gtest.h>
#include "MathFunc/MathFunc.h"

MathFunc mf;
std::vector<double> result;

TEST(MathFuncTest, DescriminantBZeroCAboveZero) {

	result = mf.solve(1.0, 0.0, 1.0);

	EXPECT_TRUE(result.empty());

}

TEST(MathFuncTest, DescriminantBZeroCBelowZero) {

	result = mf.solve(1.0, 0.0, -1.0);
	bool equalElem = fabs(result[0]) == fabs(result[1]);

	EXPECT_EQ(result.size(), 2u);
	EXPECT_TRUE(equalElem);

}

TEST(MathFuncTest, DescriminantBZeroCEqualZero) {

	result = mf.solve(1.0, 0.0, 0.0);
	bool equalElem = fabs(result[0]) == fabs(result[1]);

	EXPECT_EQ(result.size(), 2u);
	EXPECT_TRUE(equalElem);

}

TEST(MathFuncTest, DescriminantEqualZero) {

	result = mf.solve(1.0, 2.0, 1.0);
	bool equalElem = fabs(result[0]) == fabs(result[1]);

	EXPECT_EQ(result.size(), 2u);
	EXPECT_TRUE(equalElem);

	result = mf.solve(4.0, 4.0, 1.0);
	equalElem = fabs(result[0]) == fabs(result[1]);

	EXPECT_EQ(result.size(), 2u);
	EXPECT_TRUE(equalElem);

}

TEST(MathFuncTest, DescriminantBelowZero) {
	result = mf.solve(1.0, 1.0, 1.0);
	
	EXPECT_TRUE(result.empty());
}

TEST(MathFuncTest, DescriminantAboveZero) {
	result = mf.solve(1.0, 4.0, 1.0);

	EXPECT_EQ(result.size(), 2u);
}

TEST(MathFuncTest, DescriminantExceptionABellowZero) {

	EXPECT_THROW(mf.solve(0.0, 2.0, 1.0), std::invalid_argument);

}

