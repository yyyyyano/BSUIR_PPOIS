#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\LogisticsCenter.h"
#include "E:\PPOIS\labs\MailSystem_post\LogisticsCenter.cpp"

TEST(LogisticsCenterTest, AcceptPackage_NoSpace) {
	vector<Package> packs;
	vector<Employee*> staff;
	LogisticsCenter log(packs, "Unovo 12", staff, 1);
	testing::internal::CaptureStdout();
	log.AcceptPackage();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "There is no space for your package\n";
	EXPECT_EQ(output, expected_output);
}

TEST(LogisticsCenterTest, AcceptPackage_Take) {
	vector<Package> packs;
	Date MakiksBday(11, 11, 2001);
	Courier Maksik("Maksik", "Ivanov", MakiksBday, "AB3211221", "0", "car", 12.5);
	vector<Employee*> staff = { &Maksik };
	LogisticsCenter log(packs, "Unovo 12", staff, 10);
	testing::internal::CaptureStdout();
	log.AcceptPackage();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "The package was accepted by Logistic center\n";
	EXPECT_EQ(output, expected_output);
}

TEST(LogisticsCenterTest, SendPackage_GoodCourier) {
	vector<Package> packs;
	Date Makiks1Bday(11, 11, 2001);
	Courier Maksik1("Maksik", "Ivanov", Makiks1Bday, "AB3211221", "0", "car", 12.5);
	vector<Employee*> staff = { &Maksik1 };
	LogisticsCenter log(packs, "Unovo 12", staff, 10);
	testing::internal::CaptureStdout(); 
	log.SendPackage(&Maksik1);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Sending your package to courier Ivanov Maksik";
	EXPECT_EQ(output, expected_output);
}

TEST(LogisticsCenterTest, SendPackage_BusyCourier) {
	vector<Package> packs;
	Date MakikssBday(11, 11, 2001);
	Courier Maksiks("Maksik", "Ivanov", MakikssBday, "AB3211221", "0", "car", 2.5);
	vector<Employee*> staff = { &Maksiks };
	LogisticsCenter log(packs, "Unovo 12", staff, 10);
	testing::internal::CaptureStdout();
	log.SendPackage(&Maksiks);
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Courier Ivanov Maksik is too busy to take package";
	EXPECT_EQ(output, expected_output);
}