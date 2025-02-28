#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\OrderBasket.h"
#include "E:\PPOIS\labs\OnlineStore\OrderBasket.cpp"

TEST(OrderBasketTest, MakeOrderByID_NoMatches) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	Order buying;
	testing::internal::CaptureStdout();
	orrder.MakeOrderByID("fdkf", &buying);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "No matches with Article fdkf found among 2 products in your Orders basket : (\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(OrderBasketTest, MakeOrderByID_Match) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	Order buying;
	bag.ShowInfo();
	testing::internal::CaptureStdout();
	orrder.MakeOrderByID("Art_bag23_14", &buying);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "OD #Art_bag23_14 was ordered!\nOrder #Art_bag23_14 has been made successfully!\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(OrderBasketTest, ShowInfo_CorrectOutput) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	Order buying;
	testing::internal::CaptureStdout();
	orrder.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Order basket: \n - Art_ban24_15\n - Art_bag25_16\n\nQuantity of goods: 2\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(OrderBasketTest, ShowInfo_Empty) {
	vector<Order*> ob = {  };
	OrderBasket orrder(ob);
	Order buying;
	testing::internal::CaptureStdout();
	orrder.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Order basket: \nYour order basket is empty!\n";
	EXPECT_NO_THROW();
	EXPECT_EQ(output, expected_output);
}

TEST(OrderBasketTest, GetTotalrice_Empty) {
	vector<Order*> ob = {  };
	OrderBasket orrder(ob);
	Order buying;
	testing::internal::CaptureStdout();
	orrder.GetTotalPrice();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Your order basket is empty!\n";
	EXPECT_EQ(output, expected_output);
	EXPECT_EQ(orrder.GetTotalPrice(), 0);
}

TEST(OrderBasketTest, GetTotalrice) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	EXPECT_EQ(orrder.GetTotalPrice(), 23.6);
}

TEST(OrderBasketTest, IsInBasket_True) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	EXPECT_TRUE(orrder.IsInBasket(&Banana));
}

TEST(OrderBasketTest, IsInBasket_False) {
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &bag };
	OrderBasket orrder(ob);
	EXPECT_FALSE(orrder.IsInBasket(&Banana));
}
