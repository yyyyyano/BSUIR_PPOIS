#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\CallCenter.h"
#include "E:\PPOIS\labs\OnlineStore\CallCenter.cpp"

TEST(CallCenterTest, TransferCallTest_AvailableOperator) {
	Date Ybday(9, 11, 2006);
	CallCenterOperator Yana("Yana", "Bankevich", Ybday, "+375256974761", "call center operator", 15, "payments", 14);
	vector<CallCenterOperator*> CCstaff = { &Yana };
	CallCenter CC(CCstaff, "84-12-11");
	testing::internal::CaptureStdout();
	CC.TransferCallToOperator();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "The call is transfered to available operator Bankevich Yana. Please wait.\n Call center operator Bankevich Yana is on phone helping users with specialization <payments>\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(CallCenterTest, TransferCallTest_UnavailableOperator) {
	Date Dbday(13, 10, 2005);
	Date Ybday(9, 11, 2006);
	CallCenterOperator Daria("Daria", "Serhievich", Dbday, "+375255433212", "call center operator", 10, "calls",6);
	CallCenterOperator Yana("Yana", "Bankevich", Ybday, "+375256974761", "call center operator", 15, "payments", 14);
	Daria.Work();
	Yana.Work();
	vector<CallCenterOperator*> CCstaff1 = { &Daria,&Yana };
	CallCenter CC1(CCstaff1, "84-12-11");
	testing::internal::CaptureStdout();
	CC1.TransferCallToOperator();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "All operators are too busy. Please wait untill operator will be free.\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(CallCenterTest, ConfirmOrderTest_InStaff_Free) {
	Date kbday(25, 11, 2005);
	CallCenterOperator Kate("Kate", "Rubleuskaya", kbday, "+375256789009", "call center operator", 15, "confirmation", 7);
	vector<CallCenterOperator*> CCstaff = { &Kate };
	CallCenter CC1(CCstaff, "84-12-11");
	Order Banana("banana", 12.5, 1, "food");
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	NotificationSystem notificSys;
	vector<Order*> ob = { &Banana };
	OrderBasket orrder(ob);
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	testing::internal::CaptureStdout();
	CC1.ConfirmOrder(&Banana, &user, Kate);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nOrder #Art_ban1_1 was confirmed by user #yanix on line 0\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(CallCenterTest, ConfirmOrderTest_InStaff_NotFree) {
	Date kbday(25, 11, 2005);
	CallCenterOperator Kate("Kate", "Rubleuskaya", kbday, "+375256789009", "call center operator", 15, "confirmation", 7);
	vector<CallCenterOperator*> CCstaff = { &Kate };
	Kate.Work();
	CallCenter CC1(CCstaff, "84-12-11");
	Order Banana("banana", 12.5, 1, "food");
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	NotificationSystem notificSys;
	vector<Order*> ob = { &Banana };
	OrderBasket orrder(ob);
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	ASSERT_THROW(CC1.ConfirmOrder(&Banana, &user, Kate), runtime_error);
}

TEST(CallCenterTest, ConfirmOrderTest_InStaff_NoInBasket) {
	Date kbday(25, 11, 2005);
	CallCenterOperator Kate("Kate", "Rubleuskaya", kbday, "+375256789009", "call center operator", 15, "confirmation", 7);
	vector<CallCenterOperator*> CCstaff = { &Kate };
	CallCenter CC1(CCstaff, "84-12-11");
	Order Banana("banana", 12.5, 1, "food");
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	NotificationSystem notificSys;
	vector<Order*> ob;
	OrderBasket orrder(ob);
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	testing::internal::CaptureStdout();
	CC1.ConfirmOrder(&Banana, &user, Kate);
	string output1 = testing::internal::GetCapturedStdout();
	string expected_output1 = "\nUser #yanix doesn`t have Order #Art_ban3_3 in his basket\n";
	EXPECT_EQ(output1, expected_output1);
	EXPECT_NO_THROW();
}

TEST(CallCenterTest, ConfirmOrderTest_NotInStaff) {
	Date kbday(25, 11, 2005);
	CallCenterOperator Kate("Kate", "Rubleuskaya", kbday, "+375256789009", "call center operator", 15, "confirmation", 7);
	vector<CallCenterOperator*> CCstaff = { };
	CallCenter CC1(CCstaff, "84-12-11");
	Order Banana("banana", 12.5, 1, "food");
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	NotificationSystem notificSys;
	vector<Order*> ob;
	OrderBasket orrder(ob);
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	testing::internal::CaptureStdout();
	CC1.ConfirmOrder(&Banana, &user, Kate);
	string output1 = testing::internal::GetCapturedStdout();
	string expected_output1 = "Worker Rubleuskaya Kate doesn`t work there\n";
	EXPECT_EQ(output1, expected_output1);
}
