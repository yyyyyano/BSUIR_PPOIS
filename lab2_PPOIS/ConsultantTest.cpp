#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Consultant.h"
#include "E:\PPOIS\labs\MailSystem_post\Consultant.cpp"

TEST(ConsultantTest, WorkingTest) {
	Date MaksBday(13, 1, 2001);
	Consultant Maks("Maksimum", "Ivanov", MaksBday, "AB3211221", "0", "delivery");
	Maks.Work();
	Maks.Work();
	Maks.Work();
	EXPECT_EQ(Maks.GetClientsServed(), 3);
}

TEST(ConsultantTest, ShowInfoOutput) {
	Date YanaBday(13, 1, 2004);
	Consultant Yana("Maksimum", "Kurkina", YanaBday, "AB3211221", "Consultant", "delivery");
	testing::internal::CaptureStdout();
	Yana.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nFull name: Kurkina Maksimum\nBirthday: 13.1.2004\n\nPosition: consultant\nWorkID: consu_8\nSpecialization: delivery\nSatisfaction rate: 0\nClients served: 0\n";
	EXPECT_EQ(output, expected_output);
}