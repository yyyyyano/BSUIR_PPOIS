#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\DeliverySystem.h"
#include "E:\PPOIS\labs\MailSystem_post\Deliverysystem.cpp"

TEST(DeliverySystemTest, DisplayStatusHistory_NotEmpty) {
    Date KateBday(11, 11, 2011);
    Customer Kate("Kate", "Rubleuskaya", KateBday, "BY2114561", "Abobino 18");
    Date sendDate(12, 12, 2022);
    Date receiveDate(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Maria", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");

    Package pack(prod, Kate, sendDate, Masha, receiveDate);
    pack.GetPackageStatus()->ChangeStatus("In Transit");
    pack.GetPackageStatus()->ChangeStatus("Delivered");

    DeliverySystem del;
    testing::internal::CaptureStdout();
    del.DisplayStatusHistory(pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "\nStatus history for package RuKaPuMa12:\n - Package Created\n - In Transit\n - Delivered\n";
    EXPECT_EQ(output, expectedOutput);
}

TEST(DeliverySystemTest, DisplayStatus_Empty) {
    Date MarinaBday(1, 1, 2000);
    Customer Marina("Marina", "Koshkina", MarinaBday, "JD1234567", "Marynovo 11");
    Date sendDate(10, 10, 2022);
    Date receiveDate(20, 10, 2022);
    Product prod("apple", 1.5, 0.5);
    Customer recipient("Jane", "Smith", MarinaBday, "JS7654321", "High Street 5");
    Package pack(prod, Marina, sendDate, recipient, receiveDate);
    pack.SetPackageStatus(nullptr);
    DeliverySystem del;
    testing::internal::CaptureStdout();
    del.DisplayStatusHistory(pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "No status information for this package KoMaSmJa10\n";
    EXPECT_EQ(output, expectedOutput);
}

TEST(DeliverySystemTest, DisplayStatusHistory_Empty) {
    Date MarinaBday(1, 1, 2000);
    Customer Marina("Marina", "Koshkina", MarinaBday, "JD1234567", "Marynovo 11");
    Date sendDate(10, 10, 2022);
    Date receiveDate(20, 10, 2022);
    Product prod("apple", 1.5, 0.5);
    Customer recipient("Jane", "Smith", MarinaBday, "JS7654321", "High Street 5");
    Package pack(prod, Marina, sendDate, recipient, receiveDate);
    pack.GetPackageStatus()->GetStatusHistory().empty();
    pack.SetPackageStatus(nullptr);
    DeliverySystem del;
    testing::internal::CaptureStdout();
    del.DisplayStatusHistory(pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "No status information for this package KoMaSmJa10\n";
    EXPECT_EQ(output, expectedOutput);
}


TEST(DeliverySystemTest, DisplayStatusHistory_NoStatus) {
    Date AnnaBday(2, 2, 1999);
    Customer Anna("Anna", "Brown", AnnaBday, "AB1237890", "Oakino 10");
    Date sendDate(5, 5, 2023);
    Date receiveDate(15, 5, 2023);
    Product prod("orange", 2.0, 1.0);
    Customer recipient("Bobik", "White", AnnaBday, "BW0987654", "Eleny Volkovoy 20");

    Package pack(prod, Anna, sendDate, recipient, receiveDate);
    pack.SetPackageStatus(nullptr);  

    DeliverySystem del;
    testing::internal::CaptureStdout();
    del.DisplayStatusHistory(pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "No status information for this package " + pack.GetTrackingNumber() + "\n";
    EXPECT_EQ(output, expectedOutput);
}


TEST(DeliverySystemTest, NotifyUserAboutDelivery_Delivered) {
    Date DariaBday(13, 11, 2011);
    Customer Daria("Daria", "Serhievich", DariaBday, "BY2114561", "Abobino 18");
    Date sendDate(12, 12, 2022);
    Date receiveDate(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Maria", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");

    Package pack(prod, Daria, sendDate, Masha, receiveDate);
    pack.GetPackageStatus()->ChangeStatus("Delivered");

    DeliverySystem del;
    UserAccount userDaria(&Daria, "loginDasha", "password1234", "dasha@gmail.com");
    testing::internal::CaptureStdout();
    del.NotifyUserAboutDelivery(userDaria,pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "Notifying user loginDasha about delivery of SeDaPuMa12\n";
    EXPECT_EQ(output, expectedOutput);
}

TEST(DeliverySystemTest, NotifyUserAboutDelivery_NotDelivered) {
    Date DariaBday(13, 11, 2011);
    Customer Daria("Daria", "Serhievich", DariaBday, "BY2114561", "Abobino 18");
    Date sendDate(12, 12, 2022);
    Date receiveDate(31, 12, 2022);
    Product prod("banana", 11.1, 2.1);
    Date MashaBday(11, 12, 2011);
    Customer Masha("Maria", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");

    Package pack(prod, Daria, sendDate, Masha, receiveDate);

    DeliverySystem del;
    UserAccount userDaria(&Daria, "loginDasha", "password1234", "dasha@gmail.com");
    testing::internal::CaptureStdout();
    del.NotifyUserAboutDelivery(userDaria, pack);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "Notifying user loginDasha that your package SeDaPuMa12 has changed delivery status\nNew status: Package Created\n";
    EXPECT_EQ(output, expectedOutput);
}

