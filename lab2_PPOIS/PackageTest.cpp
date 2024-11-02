#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Package.h"
#include "E:\PPOIS\labs\MailSystem_post\Package.cpp"

TEST(PackageTest, ChangeRecieverTest) {
	Date MaxBday(1, 1, 2001);
	Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
	Date send(12, 12, 2022);
	Date MashaBday(11, 12, 2011);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	Date recieve(31, 12, 2022);
	Product prod("banana", 11.1, 2.1);
	Package pack(prod, Max, send, Masha, recieve);
	Date KateBday(25, 11, 2005);
	Customer Kate("Kate", "Rubleuskaya", KateBday, "BY2114561", "Abobino 18");
	UserAccount userMax(&Max, "max1234", "password", "max@mail.ru");
	EXPECT_EQ(pack.GetReciever().GetFullName(), "Pushkina Masha");
	pack.ChangeReciever(Kate, userMax);
	EXPECT_EQ(pack.GetReciever().GetFullName(), "Rubleuskaya Kate");
	EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "The reciever has been changed");
}

TEST(PackageTest, ShowInfoOutput) {
	Date MaxBday(1, 1, 2001);
	Customer Max("Max", "Smirnov", MaxBday, "BY2114561", "Bulkino 7c");
	Date send(12, 12, 2022);
	Date MashaBday(11, 12, 2011);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	Date recieve(31, 12, 2022);
	Product prod("banana", 11.1, 2.1);
	Package pack(prod, Max, send, Masha, recieve);
	testing::internal::CaptureStdout();
	pack.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expectedOutput = "\nProduct name: banana\nProduct cost: 11.1\nProduct weight: 2.1\nWeight cathegory: light\n\nStatus of delivery: Package Created\nTraccking number: SmMaPuMa12\n\nSender:\nFull name: Smirnov Max\nBirthday: 1.1.2001\nPassportID: BY2114561\nAddress: Bulkino 7c\nMailID: BulSmiMax_26\nSending data: 12.12.2022\n\nReciever: \nFull name: Pushkina Masha\nBirthday: 11.12.2011\nPassportID: AB3252221\nAddress: Baranove 14a\nMailID: BarPusMas_27\nReciving data: 31.12.2022\n\n";
	EXPECT_EQ(output, expectedOutput);
}