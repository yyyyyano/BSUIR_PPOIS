#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\UserAccount.h"
#include "E:\PPOIS\labs\OnlineStore\UserAccount.cpp"

//TEST(UserAccountTest, MakeOrder_Correct) {
//	Date bday(9, 11, 2006);
//	Human me("Yana", "Bankevich", bday, "+375255433456");
//	vector<Order*> ob = {  };
//	OrderBasket orrder(ob);
//	NotificationSystem ns;
//	string login = "Yyyyyano";
//	string password = "kdjfdf"; 
//	string email = "bankevi4@gmail.com";
//	UserAccount meUser(&me, login, password,email, &ob, &ns);
//
//}

TEST(UserAccountTest, MakeOrder_Correct) {
    Date bday(9, 11, 2006);
    Human me("Yana", "Bankevich", bday, "+375255433456");
    Order banana("banana", 12, 12, "food");
    banana.ShowInfo();
    vector<Order*> orders = { &banana };
    OrderBasket orderBasket(orders);
    NotificationSystem ns;
    string login = "Yyyyyano";
    string password = "kdjfdf";
    string email = "bankevi4@gmail.com";
    UserAccount meUser(&me, login, password, email, &orderBasket, &ns);
    testing::internal::CaptureStdout();
    meUser.MakeOrder("Art_ban49_27");
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "No matches with Article Art_ban49_27 found among 1 products in your Orders basket : (\nUser #Yyyyyano ordered OD # successfully\n";
    EXPECT_EQ(output, expected_output);
}

TEST(UserAccountTest, ShowInfo_Correct) {
    Date bday(9, 11, 2006);
    Human me("Yana", "Bankevich", bday, "+375255433456");
    Order banana("banana", 12, 12, "food");
    Order banana2("banana", 12, 12, "food");
    banana.ShowInfo();
    vector<Order*> orders = { &banana,&banana2 };
    OrderBasket orderBasket(orders);
    NotificationSystem ns;
    string login = "Yyyyyano";
    string password = "kdjfdf";
    string email = "bankevi4@gmail.com";
    UserAccount meUser(&me, login, password, email, &orderBasket, &ns);
    testing::internal::CaptureStdout();
    meUser.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "Full name: Bankevich Yana\nBirthdate: 9.11.2006\nPhone number: +375255433456\nLogin: YyyyyanoEmail: bankevi4@gmail.com\nOrders history:\n Order basket: \nOrder basket: \n - Art_ban62_40\n - Art_ban63_41\n\nQuantity of goods: 2\n";
    EXPECT_EQ(output, expected_output);
}

TEST(UserAccountTest, CheckPassword_True) {
    Date bday(9, 11, 2006);
    Human me("Yana", "Bankevich", bday, "+375255433456");
    Order banana("banana", 12, 12, "food");
    banana.ShowInfo();
    vector<Order*> orders = { &banana };
    OrderBasket orderBasket(orders);
    NotificationSystem ns;
    string login = "Yyyyyano";
    string password = "kdjfdf";
    string email = "bankevi4@gmail.com";
    UserAccount meUser(&me, login, password, email, &orderBasket, &ns);
    EXPECT_TRUE(meUser.CheckPassword("kdjfdf"));
}

TEST(UserAccountTest, CheckPassword_False) {
    Date bday(9, 11, 2006);
    Human me("Yana", "Bankevich", bday, "+375255433456");
    Order banana("banana", 12, 12, "food");
    banana.ShowInfo();
    vector<Order*> orders = { &banana };
    OrderBasket orderBasket(orders);
    NotificationSystem ns;
    string login = "Yyyyyano";
    string password = "kdjfdf";
    string email = "bankevi4@gmail.com";
    UserAccount meUser(&me, login, password, email, &orderBasket, &ns);
    EXPECT_FALSE(meUser.CheckPassword("aaaaaaaaa"));
}