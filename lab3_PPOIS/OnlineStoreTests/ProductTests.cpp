#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\Product.h"
#include "E:\PPOIS\labs\OnlineStore\Product.cpp"

TEST(ProductTest, ChangePrice_HasDiscount) {
	Product apple("apple", 5, 11, "food");
	apple.ChangePriceWithDiscount("Seasonal Discount");
	EXPECT_NEAR(apple.GetPrice(), 4, 0.01);
}

TEST(ProductTest, ChangePrice_HasPromocode) {
	Product apple("apple", 5, 11, "food");
	apple.ChangePriceWithDiscount("QWERTY");
	EXPECT_EQ(apple.GetPrice(), 3);
}

TEST(ProductTest, ChangePrice_NoDiscount) {
	Product apple("apple", 5, 11, "food");
	testing::internal::CaptureStdout();
	apple.ChangePriceWithDiscount("QweqweTY");
	string output2 = testing::internal::GetCapturedStdout();
	string expected_output2 = "Unfortunately we don`t have this discount :(\n";
	EXPECT_EQ(output2, expected_output2);
}

TEST(ProductTest, ShowTest_CorrectOutput) {
	Product apple("apple", 5, 11, "food");
	testing::internal::CaptureStdout();
	apple.ShowInfo();
	string output2 = testing::internal::GetCapturedStdout();
	string expected_output2 = "Name: apple\nPrice: 5\nArticle: Art_app51\nCurrent quantity: 11\nCategory: food\n";
	EXPECT_EQ(output2, expected_output2);
}