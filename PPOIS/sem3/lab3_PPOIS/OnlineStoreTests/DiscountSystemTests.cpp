#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\DiscountSystem.h"
#include "E:\PPOIS\labs\OnlineStore\DiscountSystem.cpp"

TEST(DiscountSystemTest, ApplyDiscount_LessTen) {
	DiscountSystem a;
	double price = 5.00;
	double newPrice=a.ApplyDiscount(price);
	EXPECT_DOUBLE_EQ(newPrice, 4.00);
}

TEST(DiscountSystemTest, ApplyDiscount_MoreTenLessFifty) {
	DiscountSystem a;
	double price = 20.00;
	double newPrice = a.ApplyDiscount(price);
	EXPECT_NEAR(newPrice,19.45,0.01);
}

TEST(DiscountSystemTest, ApplyDiscount_MoreFifty) {
	DiscountSystem a;
	double price = 60.00;
	double newPrice = a.ApplyDiscount(price);
	EXPECT_EQ(newPrice, 58.01);
}

TEST(DiscountSystemTest, HasDiscountTypes) {
	DiscountSystem b;
	EXPECT_TRUE(b.HasDiscountType("Seasonal Discount"));
	EXPECT_FALSE(b.HasDiscountType("Seasonal"));
}

TEST(DiscountSystemTest, HasProocodes) {
	DiscountSystem c;
	EXPECT_TRUE(c.HasPromocode("QWERTY"));
	EXPECT_FALSE(c.HasPromocode("RTY"));
}

TEST(DiscountSystemTest, DeleteDiscounts) {
	DiscountSystem d;
	d.DeleteDiscount("QWERTY");
	d.DeleteDiscount("sd");
	d.DeleteDiscount("Seasonal Discount");
	testing::internal::CaptureStdout();
	d.DisplayDiscounts();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Available Discount Types:\n - Black Friday\n - Coupon Code\n - New Customer Discount\n - Birthday Discount\n\nAvailable Promocodes:\n - HELLOWORLD\n - PROMOCODE\n - BOOLEAN\n - YEEEEEERRRR\n";
	EXPECT_EQ(output, expected_output);

}
