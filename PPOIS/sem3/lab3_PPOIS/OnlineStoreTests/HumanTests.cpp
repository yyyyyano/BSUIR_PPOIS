#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\Human.h"
#include "E:\PPOIS\labs\OnlineStore\Human.cpp"

#include "E:\PPOIS\labs\OnlineStore\Employee.h"
#include "E:\PPOIS\labs\OnlineStore\Employee.cpp"

TEST(HumanTest, ShowInfo_CorrectOutput) {
	Date day(8, 8, 2006);
	Human human("Alexa", "Bubkina", day, "+375254325678");
	testing::internal::CaptureStdout();
	human.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Full name: Bubkina Alexa\nBirthdate: 8.8.2006\nPhone number: +375254325678\n";
	EXPECT_EQ(output, expected_output);
}

TEST(HumanTest, IsValidNumber_False) {
	Date day(8, 8, 2006);
	Human human("Alexa", "Bubkina", day, "375325678");
	string output = human.GetPhoneNumber();
	string expected_output = "incorrect phone number ";
	EXPECT_EQ(output, expected_output);
}

TEST(HumanTest, ChangePhoneNumber_Incorrect) {
	Date day11(8, 8, 2006);
	Human human11("Alexa", "Bubkina", day11, "375325678");
	testing::internal::CaptureStdout();
	human11.ChangePhoneNumber("3232");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Incorrect phone number!";
	EXPECT_EQ(output, expected_output);
}

TEST(HumanTest, ChangePhoneNumber_Correct) {
	Date day11(8, 8, 2006);
	Human human11("Alexa", "Bubkina", day11, "375325678");
	testing::internal::CaptureStdout();
	human11.ChangePhoneNumber("+375256978778");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nPhone number has been changed successfully!Full name: Bubkina Alexa\nBirthdate: 8.8.2006\nPhone number: +375256978778\n";
	EXPECT_EQ(output, expected_output);
}
