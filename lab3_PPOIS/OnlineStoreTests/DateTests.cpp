#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\Date.h"
#include "E:\PPOIS\labs\OnlineStore\Date.cpp"

TEST(DateTest, ShowDate_CorrectOutput) {
	Date bday(10, 10, 2000);
	testing::internal::CaptureStdout();
	bday.ShowDate();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "10.10.2000\n";
	EXPECT_EQ(output, expected_output);
}

TEST(DateTest, IsValidDate_ReturnsTrue) {
	Date PetrBday(17, 11, 2005);
	EXPECT_TRUE(PetrBday.IsValidDate());
}

TEST(DateTest, IsValidDate_ReturnsFalse) {
	Date PetrBday(37, 100, 2005);
	EXPECT_FALSE(PetrBday.IsValidDate());
}

TEST(DateTest, IsLeapYearFebLeap_True) {
	Date dat(2, 2, 2024);
	EXPECT_TRUE(dat.IsValidDate());
}

TEST(DateTest, IsLeapYearFebLeap_False) {
	Date dat(30, 2, 2024);
	EXPECT_FALSE(dat.IsValidDate());
}

TEST(DateTest, IsLeapYearFebNotLeap_True) {
	Date data(12, 2, 2023);
	EXPECT_TRUE(data.IsValidDate());
}

TEST(DateTest, IsLeapYearFebNotLeap_False) {
	Date data(29, 2, 2023);
	EXPECT_FALSE(data.IsValidDate());
}

TEST(DateTest, IsLeapYearMarch_True) {
	Date dat(30, 3, 2024);
	EXPECT_TRUE(dat.IsValidDate());
}

TEST(DateTest, IsLeapYearMarch_False) {
	Date dat(40, 3, 2024);
	EXPECT_FALSE(dat.IsValidDate());
}