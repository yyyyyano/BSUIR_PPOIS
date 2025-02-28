#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\PickUpPoint.h"
#include "E:\PPOIS\labs\OnlineStore\PickUpPoint.cpp"

TEST(PickUpPointTest, IssueParcel_NoUser) {
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
    vector<Product*> popOrders;
    vector<UserAccount*> users;
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.IssueParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nError!\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointTest, IssueParcel_NoOrder) {
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
    vector<Product*> popOrders = { &banana };
    vector<UserAccount*> users = { &meUser };
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.IssueParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nThere is no Order #aaa\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointTest, IssueParcel_OK) {
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
    vector<Product*> popOrders = { &banana };
    vector<UserAccount*> users = { &meUser };
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.IssueParcel("Art_ban38_29", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "Order #Art_ban38_29 was issued to user #Yyyyyano\nProduct #Art_ban38 was removed from the warehouse\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointTest, ReturnParcel_NoUser) {
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
    vector<Product*> popOrders;
    vector<UserAccount*> users;
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.ReturnParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nError!\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointTest, ReturnParcel_NoOrder) {
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
    vector<Product*> popOrders = { &banana };
    vector<UserAccount*> users = { &meUser };
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.ReturnParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nThere is no Order #aaa\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointTest, ReturnParcel_OK) {
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
    vector<Product*> popOrders = { &banana };
    vector<UserAccount*> users = { &meUser };
    PickUpPoint pop(100, "Bobkino 12a", popOrders, users);
    testing::internal::CaptureStdout();
    pop.ReturnParcel("Art_ban41_32", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "Order #Art_ban41_32 was returned by user #Yyyyyano from POP#6\nProduct #Art_ban41 was removed from the warehouse\n";
    EXPECT_EQ(output, expected_output);
}
