#include <gtest/gtest.h>

#include <reni/math.hpp>
#include <reni/print.hpp>

using namespace reni;

class MatrixOperations3D : public testing::Test {
protected:
	const Mat3x3 m1 = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};

	const Mat3x3 m2 = {
		2,  4,  6,
		8,  10, 12,
		14, 16, 18
	};
};

TEST_F(MatrixOperations3D, IterationOverComponents) {
	float nextVal = 0;
	for(const auto& row : m1) {
		for(const auto& col : row) {
			EXPECT_EQ(col, (nextVal += 1));
		}
	}
	EXPECT_EQ(nextVal, 9);
}

TEST_F(MatrixOperations3D, MutatingIterationOverComponents) {
	float nextVal = 0;
	Mat3x3 m;

	for(auto& row : m) {
		for(auto& col : row) {
			col = (nextVal += 1);
		}
	}
	
	EXPECT_EQ(nextVal, 9);
	EXPECT_EQ(m, m1);
}

TEST_F(MatrixOperations3D, EqualityComparison) {
	EXPECT_EQ(m1, m1);
	EXPECT_NE(m1, m2);
}

TEST_F(MatrixOperations3D, Addition) {
	ASSERT_EQ(m1 + m1, m2);
}

TEST_F(MatrixOperations3D, Subtraction) {
	ASSERT_EQ(m2 - m1, m1);
}

TEST_F(MatrixOperations3D, Multiplication) {
	const auto m3 = Mat3x3(
		60,  72,  84,
		132, 162, 192,
		204, 252, 300
	);
	ASSERT_EQ(m1 * m2, m3);
}

TEST_F(MatrixOperations3D, ScalarAddition) {
	const auto m3 = Mat3x3(
		6,  7,  8,
		9,  10, 11,
		12, 13, 14
	);
	ASSERT_EQ(m1 + 5, m3);
}

TEST_F(MatrixOperations3D, ScalarSubtraction) {
	const auto m3 = Mat3x3(
		0,  2,  4,
		6,  8,  10,
		12, 14, 16
	);
	ASSERT_EQ(m2 - 2, m3);
}

TEST_F(MatrixOperations3D, ScalarMultiplication) {
	ASSERT_EQ(m1 * 2, m2);
}

TEST_F(MatrixOperations3D, ScalarDivision) {
	ASSERT_EQ(m2 / 2, m1);
}

TEST_F(MatrixOperations3D, FindingTranspose) {
	const auto m3 = Mat3x3(
		1, 4, 7,
		2, 5, 8,
		3, 6, 9
	);
	ASSERT_EQ(m1.transpose(), m3);
}

TEST_F(MatrixOperations3D, FindingDeterminant) {
	const auto m3 = Mat3x3(
		5, 2, 3,
		1, 4, 2,
		9, 2, 3
	);

	const auto expected =
		+ 5 * (4 * 3 - 2 * 2)
		- 2 * (1 * 3 - 2 * 9)
		+ 3 * (1 * 2 - 4 * 9);

	ASSERT_EQ(m3.determinant(), expected);
}

TEST_F(MatrixOperations3D, FindingInverse) {
	const auto m3 = Mat3x3(
		3, 2, 1,
		2, 3, 1,
		1, 3, 1
	);
	ASSERT_EQ(m3 * m3.inverse(), Mat3x3::identity());
}
