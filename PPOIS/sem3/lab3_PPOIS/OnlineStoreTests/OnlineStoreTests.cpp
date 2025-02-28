#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\OnlineStore.h"
#include "E:\PPOIS\labs\OnlineStore\OnlineStore.cpp"

TEST(OnlineStoreTest, LogUserTest) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	NotificationSystem notificSys;
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	vector<UserAccount*> users = { &user };
	vector<Warehouse*> ware;
	OnlineStore shop(&ss, "shop", users, ware);
	shop.LogUser(&user);
	testing::internal::CaptureStdout();
	user.GetNotify()->CheckAllNotifications();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Notification: Welcome to online store <shop> ! | Unread\n";
	EXPECT_EQ(output, expected_output);
}

TEST(OnlineStoreTest, CheckGoods_FalseFlag) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	Order Banana("banana", 12.5, 1, "food");
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	NotificationSystem notificSys;
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	vector<UserAccount*> users = { &user };
	vector<Warehouse*> ware;
	OnlineStore shop(&ss, "shop", users, ware);
	vector<string> find;
	vector<Product*> found;
	testing::internal::CaptureStdout();
	shop.CheckGoods(find, found);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "There is no goods with this articles\n";
	EXPECT_EQ(output, expected_output);
}

TEST(OnlineStoreTest, CheckGoods_FalseTrue) {
	Product apple("apple", 10, 100, "food");
	Product pear("pear", 11, 1, "food");
	Product car("bmw", 12345, 11, "mobility");
	vector<Product*> products = { &apple,&pear,&car };
	SearchSystem ss(products);
	Date bday(9, 11, 2006);
	Human me("yana", "bankevich", bday, "+375256974761");
	Order Banana("banana", 12.5, 1, "food");
	apple.ShowInfo();
	Order bag("bag", 11.1, 1, "entity");
	vector<Order*> ob = { &Banana,&bag };
	OrderBasket orrder(ob);
	NotificationSystem notificSys;
	UserAccount user(&me, "yanix", "121", "bankevi4@gmail.com", &orrder, &notificSys);
	vector<UserAccount*> users = { &user };
	vector<Warehouse*> ware;
	OnlineStore shop(&ss, "shop", users, ware);
	vector<string> find = { "Art_app15" };
	vector<Product*> found;
	testing::internal::CaptureStdout();
	shop.CheckGoods(find, found);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Name: apple\nPrice: 10\nArticle: Art_app15\nCurrent quantity: 100\nCategory: food\n\nThere is no goods with this articles\n";
	EXPECT_EQ(output, expected_output);
}
