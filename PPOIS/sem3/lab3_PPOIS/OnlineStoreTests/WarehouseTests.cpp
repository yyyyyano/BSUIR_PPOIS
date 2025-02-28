#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\Warehouse.h"
#include "E:\PPOIS\labs\OnlineStore\Warehouse.cpp"

TEST(WarehouseTest, AcceptProducts_NoFreeSpace) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { &Banana };
	Product Apple("apple", 11, 1, "food");
	vector<Product*> qwe = { &Apple };
	Warehouse ware(1,  "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.AcceptProducts(qwe);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "There is no space for all products! Still 1 haven`t been accepted\n0 goods were accepted!\n";
	EXPECT_EQ(output, expected_output);
}

TEST(WarehouseTest, AcceptProducts_FreeSpace) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { &Banana };
	Product Apple("apple", 11, 1, "food");
	vector<Product*> qwe = { &Apple };
	Warehouse ware(10, "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.AcceptProducts(qwe);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "1 goods were accepted!\n";
	EXPECT_EQ(output, expected_output);
}

TEST(WarehouseTest, DeleteProduct_Empty) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { };
	Warehouse ware(10, "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.DeleteProduct("");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "There is no products in thw warehouse\n";
	EXPECT_EQ(output, expected_output);
}

TEST(WarehouseTest, DeleteProduct_NotEmpty_NoHave) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { &Banana };
	Warehouse ware(10, "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.DeleteProduct("atr");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "";
	EXPECT_EQ(output, expected_output);
}

TEST(WarehouseTest, DeleteProduct_NotEmpty_Have) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { &Banana };
	Banana.ShowInfo();
	Warehouse ware(10, "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.DeleteProduct("atr");
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "";
	EXPECT_EQ(output, expected_output);
}

TEST(WarehouseTest, ShowInfo_CorrectOutput) {
	Product Banana("Banana", 14.5, 10, "food");
	vector<Product*> prod = { &Banana };
	Warehouse ware(10, "Abobino 12", prod);
	testing::internal::CaptureStdout();
	ware.ShowGoods();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = " - Art_Ban73\n";
	EXPECT_EQ(output, expected_output);
}
