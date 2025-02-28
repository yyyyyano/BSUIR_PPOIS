#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\SearchSystem.h"
#include "E:\PPOIS\labs\OnlineStore\SearchSystem.cpp"

TEST(SearchSystemTest, FindCategory_Found) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	vector<Product*> foun = { &apple,&pear };
	EXPECT_EQ(ss.FindProductsByCategory("food"), foun);
}

TEST(SearchSystemTest, FindCategory_NotFound) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	vector<Product*> foun = { };
	EXPECT_EQ(ss.FindProductsByCategory("fd"), foun);
}

TEST(SearchSystemTest, FindArticle_NotFound) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	EXPECT_EQ(ss.FindProductByArticle("article"), nullptr);
	testing::internal::CaptureStdout();
	ss.FindProductByArticle("article");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "No matches found among 3 products :(\n";
	EXPECT_EQ(output, expected_output);
}
