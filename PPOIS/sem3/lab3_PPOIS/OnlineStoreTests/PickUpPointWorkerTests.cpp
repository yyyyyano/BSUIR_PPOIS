#include "pch.h"
#include "E:\PPOIS\labs\OnlineStore\PickUpPointWorker.h"
#include "E:\PPOIS\labs\OnlineStore\PickUpPointWorker.cpp"

TEST(PickUpPointWorkerTest, IssueParcel_Done) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221","Pick up point worker", 12, 12, &pop);
    testing::internal::CaptureStdout();
    puper.IssueParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "PickUpPoint worker Rublevskaya Kate done his work for today\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointWorkerTest, IssueParcel_OK) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221", "Pick up point worker", 12, 1, &pop);
    testing::internal::CaptureStdout();
    puper.IssueParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "PickUpPoint worker Rublevskaya Kate works on PUP#8\n\n\nError!\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointWorkerTest, ReturnParcel_Done) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221", "Pick up point worker", 12, 12, &pop);
    testing::internal::CaptureStdout();
    puper.ReturnParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "PickUpPoint worker Rublevskaya Kate done his work for today\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointWorkerTest, ReturnParcel_OK) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221", "Pick up point worker", 12, 1, &pop);
    testing::internal::CaptureStdout();
    puper.ReturnParcel("aaa", &meUser);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "PickUpPoint worker Rublevskaya Kate works on PUP#10\n\n\nError!\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointWorker_EmployeeTest, IsAvailable_Free) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221", "Pick up point worker", 12, 1, &pop);
    testing::internal::CaptureStdout();
    puper.IsAvailable();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "Employee Rublevskaya Kate is free! How can we help you?\n";
    EXPECT_EQ(output, expected_output);
}

TEST(PickUpPointWorker_EmployeeTest, IsAvailable_NotFree) {
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
    Date bday2(25, 11, 2005);
    PickUpPointWorker puper("Kate", "Rublevskaya", bday2, "+375254321221", "Pick up point worker", 12, 1, &pop);
    testing::internal::CaptureStdout();
    puper.IsAvailable();
    puper.IsAvailable();
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "Employee Rublevskaya Kate is free! How can we help you?\nSorry. Employee Rublevskaya Kate is too busy now!\n";
    EXPECT_EQ(output, expected_output);
}
