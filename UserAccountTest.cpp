#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\UserAccount.h"
#include "E:\PPOIS\labs\MailSystem_post\UserAccount.cpp"

TEST(UserAccountTest, IsValidEmailTest_ExpectTrue) {
	Date DariaBday(13, 10, 2005);
	Customer Daria("Daria", "Sergievich", DariaBday, "BY2544561", "Pushkino 8a");
	UserAccount userDaria(&Daria, "loginDasha", "password1234", "dasha@gmail.com");
	EXPECT_TRUE(userDaria.IsValidEmail("dasha@gmail.com"));
}

TEST(UserAccountTest, IsValidEmailTest_ExpectFalse) {
	Date DaridaBday(13, 10, 2005);
	Customer Darida("Darida", "Sergievich", DaridaBday, "BY2544561", "Pushkino 8a");
	UserAccount userDarida(&Darida, "loginDasha", "password1234", "gmail.com");
	EXPECT_FALSE(userDarida.IsValidEmail("gmail.com"));
}

TEST(UserAccountTest, IsValidEmail_ReturnFalse) {
	Date DaridaBday(13, 10, 2005);
	Customer Darida("Darida", "Sergievich", DaridaBday, "BY2544561", "Pushkino 8a");
	UserAccount userDarida(&Darida, "loginDasha", "password1234", "gmail.com");
	EXPECT_FALSE(userDarida.IsValidEmail("yana@gmailcom"));
}

TEST(UserAccountTest, CheckPasswordTest_ExpectTrue) {
	Date DariBday(13, 10, 2005);
	Customer Dari("Dari", "Sergievich", DariBday, "BY2544561", "Pushkino 8a");
	UserAccount userDari(&Dari, "dariii", "password1234", "gmail.com");
	EXPECT_TRUE(userDari.CheckPassword("password1234"));
}

TEST(UserAccountTest, CheckPasswordTest_ExpectFalse) {
	Date DaBday(13, 10, 2005);
	Customer Da("Da", "Sergievich", DaBday, "BY2544561", "Pushkino 8a");
	UserAccount userDa(&Da, "dariii", "password1234", "gmail.com");
	EXPECT_FALSE(userDa.CheckPassword("password"));
}

TEST(UserAccountTest, ShowUserInfoOutput) {
	Date DaBday(13, 10, 2005);
	Customer Da("Da", "Sergievich", DaBday, "BY2544561", "Pushkino 8a");
	UserAccount user(&Da, "bubelka18","12345", "bubka@gmail.com");
	testing::internal::CaptureStdout();
	user.ShowUserInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\naccountID:\t8\nlogin:\tbubelka18\nemail:\tbubka@gmail.com";
	EXPECT_EQ(output, expected_output);
}