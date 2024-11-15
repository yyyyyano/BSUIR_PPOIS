#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\Order.h"
#include "E:\PPOIS\labs\OnlineStore\Order.cpp"

TEST(OrderTest, MakeOrder_NotInStock) {
	Order pear("pear", 12.5, 0, "food");
	testing::internal::CaptureStdout();
	pear.MakeOrder();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "All this products sold out\n";
	EXPECT_EQ(output, expected_output);
}

TEST(OrderTest, MakeOrder_InStock) {
	Order pear("pear", 12.5, 10, "food");
	testing::internal::CaptureStdout();
	pear.MakeOrder();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Order #Art_pea33_24 has been made successfully!\n";
	EXPECT_EQ(output, expected_output);
	EXPECT_EQ(pear.GetQuantity(), 9);
	EXPECT_EQ(pear.GetStatus(), "Ordered");
}

TEST(OrderTest, CancelOrder) {
	Order pear("pear", 12.5, 10, "food");
	testing::internal::CaptureStdout();
	pear.CancelOrder();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Order #Art_pea34_25 was cancelled successfully!\n";
	EXPECT_EQ(output, expected_output);
	EXPECT_EQ(pear.GetQuantity(), 11);
	EXPECT_EQ(pear.GetStatus(), "Cancelled");
}

TEST(OrderTest, ShowInfo_CorrectOutput) {
	Order pear("pear", 12.5, 10, "food");
	testing::internal::CaptureStdout();
	pear.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Name: pear\nPrice: 12.5\nArticle: Art_pea35\nCurrent quantity: 10\nCategory: food\nOrder idx: Art_pea35_26\nOrder status: Created\n";
	EXPECT_EQ(output, expected_output);
}