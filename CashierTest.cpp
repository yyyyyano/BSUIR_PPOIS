#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Cashier.h"
#include "E:\PPOIS\labs\MailSystem_post\Cashier.cpp"

TEST(CashierTest, WorkingTest) {
	Date MaicsBday(11, 11, 2001);
	Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	Maics.Work();
	Maics.Work();
	Maics.Work();
	EXPECT_EQ(Maics.GetClientsServed(), 3);
	EXPECT_EQ(Maics.GetDeliveriesCount(), 3);

}

TEST(EmployeeCashierTest, IsJuniorTest_ExpectFalse) {
	Date MaicsBday(11, 11, 2001);
	Cashier Maics("Maics", "Ivanov", MaicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	Date MaimicsBday(11, 11, 2001);
	Cashier Masimics("Masimics", "Ivanov", MaimicsBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	EXPECT_FALSE(Maics.IsJunior(&Masimics));
}

TEST(EmployeeCashierTest, IsJuniorTest_ExpectTrue) {
	Date MaiBday(11, 11, 2001);
	Cashier Mai("Mai", "Ivanov", MaiBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	Date MasBday(11, 11, 2001);
	Cashier Mas("Mas", "Ivanov", MasBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	EXPECT_TRUE(Mas.IsJunior(&Mai));
}

TEST(CashierTest, ShowInfoOutput) {
	Date MaiklBday(11, 11, 2001);
	Cashier Maikl("Maikl", "Ivanov", MaiklBday, "AB3211221", "Cashier", "payments", "foot", 12.5, 2);
	testing::internal::CaptureStdout();
	Maikl.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nFull name: Ivanov Maikl\nBirthday: 11.11.2001\n\nPosition: Cashier\nWorkID: Cashi_2\nSpecialization: payments\nSatisfaction rate: 0\nClients served: 0\nCategory: 2\nCashAppID: 2\n";
	EXPECT_EQ(output, expected_output);
}