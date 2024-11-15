#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\CallCenterOperator.h"
#include "E:\PPOIS\labs\OnlineStore\CallCenterOperator.cpp"

TEST(CallCenterOperatorTest, ShowInfo_CorrectOutput) {
	Date Ybday(9, 11, 2006);
	CallCenterOperator Yana("Yana", "Bankevich", Ybday, "+375256974761", "call center operator", 15, "payments", 14);
	testing::internal::CaptureStdout();
	Yana.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Full name: Bankevich Yana\nBirthdate: 9.11.2006\nPhone number: +375256974761\nPosition: call center operator\nEmployee ID: cal_14\nSpecialization: payments\nCall center index: 0\nAverage calls per day: 15\n";
	EXPECT_EQ(output, expected_output);
}

TEST(CallCenterOperatorTest, Work_Exception) {
	Date Ybday(9, 11, 2006);
	CallCenterOperator Yana("Yana", "Bankevich", Ybday, "+375256974761", "call center operator", 15, "payments", 15);
	testing::internal::CaptureStdout();
	Yana.Work();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Error: This call center operator has completed the work plan for today!";
	EXPECT_EQ(output, expected_output);
	ASSERT_THROW(Yana.Work(),runtime_error);
}

TEST(CallCenterOperatorTest, OrderConfirm_Exception) {
	Date Ybday(9, 11, 2006);
	CallCenterOperator Yana("Yana", "Bankevich", Ybday, "+375256974761", "call center operator", 15, "payments", 15);
	Order banana("banana", 12, 12, "food");
	Human me("yana", "bank", Ybday, "+375256974761");
	NotificationSystem ns;
	vector<Order*> orders;
	OrderBasket ob(orders);
	UserAccount yn(&me, "login0", "pass", "email@dot.com", &ob, &ns);
	Yana.IsAvailable();
	testing::internal::CaptureStdout();
	Yana.OrderConfirmation(&banana, &yn);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Error: Call center operator Bankevich Yana isn`t available now\n";
	EXPECT_EQ(output, expected_output);
	ASSERT_THROW(Yana.OrderConfirmation(&banana, &yn), runtime_error);
}
