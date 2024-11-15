#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Date.h"
#include "E:\PPOIS\labs\MailSystem_post\Date.cpp"

TEST(DateTest, IsValidDate_ReturnsTrue) {
	Date PetrBday(17, 11, 2005);
	EXPECT_TRUE(PetrBday.IsValidDate());
}

TEST(DateTest, IsValidDate_ReturnsFalse) {
	Date PetrBday(37, 100, 2005);
	EXPECT_FALSE(PetrBday.IsValidDate());
}

TEST(DateTest, ShowDateOutput) {
	Date date(9, 11, 2006);
	testing::internal::CaptureStdout();
	date.ShowDate();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "9.11.2006\n";
	EXPECT_EQ(output, expected_output);
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