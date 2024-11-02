#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Payment.h"
#include "E:\PPOIS\labs\MailSystem_post\Payment.cpp"


TEST(PaymentTest, ProcessPaymentCardTest) {
    Date MaxBday(1, 1, 2001);
    Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
    Date send(12, 12, 2022);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
    Date recieve(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Package pack(prod, Max, send, Masha, recieve);
    Payment payBanana(&pack, "card");
    Date MaicsBday(11, 11, 2001);
    Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
    testing::internal::CaptureStdout();
    payBanana.ProcessPayment("123321456", &Maics);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nPayment #SmMaPuMa12car has been sent to bank acc #123321456\nAmount: 12.432";
    EXPECT_EQ(output, expected_output);
    EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "The package payment was approved");
    EXPECT_TRUE(payBanana.GetTransactionFlag());
}

TEST(PaymentTest, ProcessPaymentCashTest) {
    Date MaxBday(1, 1, 2001);
    Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
    Date send(12, 12, 2022);
    Date MishaBday(11, 12, 2011);
    Customer Misha("Masha", "Pushkina", MishaBday, "AB3252221", "Baranove 14a");
    Date recieve(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Package pack(prod, Max, send, Misha, recieve);
    Payment payBanana(&pack, "cash");
    Date MaicsBday(11, 11, 2001);
    Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
    testing::internal::CaptureStdout();
    payBanana.ProcessPayment("123321456", &Maics);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nPayment #SmMaPuMa12cas was processed by cashier Ivanov Maics\nAmount: 12.432";
    EXPECT_EQ(output, expected_output);
    EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "The package payment was approved");
    EXPECT_TRUE(payBanana.GetTransactionFlag());
}

TEST(PaymentTest, ProcessRefundCardTest) {
    Date MaxBday(1, 1, 2001);
    Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
    Date send(12, 12, 2022);
    Date MishaBday(11, 12, 2011);
    Customer Misha("Masha", "Pushkina", MishaBday, "AB3252221", "Baranove 14a");
    Date recieve(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Package pack(prod, Max, send, Misha, recieve);
    Payment payBanana(&pack, "card");
    Date MaicsBday(11, 11, 2001);
    Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
    payBanana.ProcessPayment("123321456", &Maics); 
    testing::internal::CaptureStdout();
    payBanana.ProcessRefund("123321456", &Maics);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nRefund for payment #SmMaPuMa12car is being processed.\nRefunding amount: 12.432 to bank account #123321456\n";
    EXPECT_EQ(output, expected_output);
    EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "The package payment was refunded");
    EXPECT_FALSE(payBanana.GetTransactionFlag());
}

TEST(PaymentTest, ProcessRefundCashTest) {
    Date MaxBday(1, 1, 2001);
    Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
    Date send(12, 12, 2022);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
    Date recieve(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Package pack(prod, Max, send, Masha, recieve);
    Payment payBanana(&pack, "cash");
    Date MaicsBday(11, 11, 2001);
    Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
    payBanana.ProcessPayment("123321456", &Maics);
    testing::internal::CaptureStdout();
    payBanana.ProcessRefund("123321456", &Maics);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "\nRefund for payment #SmMaPuMa12cas is processed by cashier Ivanov Maics\n";
    EXPECT_EQ(output, expected_output);
    EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "The package payment was refunded");
    EXPECT_FALSE(payBanana.GetTransactionFlag());
}

TEST(PaymentTest, ProcessRefund_NoPayment) {
    Date MaxBday(1, 1, 2001);
    Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
    Date send(12, 12, 2022);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
    Date recieve(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Package pack(prod, Max, send, Masha, recieve);
    Payment payBanana(&pack, "cash");
    Date MaicsBday(11, 11, 2001);
    Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
    testing::internal::CaptureStdout();
    payBanana.ProcessRefund("123321456", &Maics);
    string output = testing::internal::GetCapturedStdout();
    string expected_output = "No transaction found for payment ID: SmMaPuMa12cas. Refund cannot be processed.\n";
    EXPECT_EQ(output, expected_output);
}

