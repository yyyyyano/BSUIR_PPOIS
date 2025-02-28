#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Product.h"
#include "E:\PPOIS\labs\MailSystem_post\Product.cpp"

TEST(ProductTest, GenerateWeightCathegoryTest_ExpectLight) {
	Product prod("banana", 11.1, 2.1);
	EXPECT_EQ(prod.GetWeightCategory(), "light");
}

TEST(ProductTest, GenerateWeightCathegoryTest_ExpectMedium) {
	Product prod1("apple", 2.5, 5.1);
	EXPECT_EQ(prod1.GetWeightCategory(), "medium");
}

TEST(ProductTest, GenerateWeightCathegoryTest_ExpectHeavy) {
	Product prod2("ananas", 11.1, 12.1);
	EXPECT_EQ(prod2.GetWeightCategory(), "heavy");
}

TEST(ProductTest, DiscountRouletteTest_ExpectRaise) {
	Product cocojambo("cocojambo", 1, 3.4);
	cocojambo.DiscountRoulette();
	EXPECT_EQ(cocojambo.GetCost(), 1.05);
}

TEST(ProductTest, DiscountRouletteTest_ExpectLow) {
	Product Cocojambo("Cocojambo", 1, 0.3);
	Cocojambo.DiscountRoulette();
	EXPECT_EQ(Cocojambo.GetCost(), 0.85);
}

TEST(ProductTest, ShowInfoOutput) {
	Product product("Car bmw m5", 1000, 5000);
	testing::internal::CaptureStdout();
	product.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nProduct name: Car bmw m5\nProduct cost: 1000\nProduct weight: 5000\nWeight cathegory: heavy\n";
	EXPECT_EQ(output, expected_output);
}
