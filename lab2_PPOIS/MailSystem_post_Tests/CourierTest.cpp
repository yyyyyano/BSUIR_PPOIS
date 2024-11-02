#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Courier.h"
#include "E:\PPOIS\labs\MailSystem_post\Courier.cpp"


#include "E:\PPOIS\labs\MailSystem_post\Employee.h"
#include "E:\PPOIS\labs\MailSystem_post\Employee.cpp"
#include "E:\PPOIS\labs\MailSystem_post\Human.h"
#include "E:\PPOIS\labs\MailSystem_post\Human.cpp"
//#include "E:\PPOIS\labs\MailSystem_post\Payment.h"
//#include "E:\PPOIS\labs\MailSystem_post\Payment.cpp"



//Courier
TEST(CourierTest, WorkingTest) {
	Date MakiksBday(11, 11, 2001);
	Courier Maksik("Maksik", "Ivanov", MakiksBday, "AB3211221", "Courier", "car", 12.5);
	Maksik.Work();
	Maksik.Work();
	EXPECT_EQ(Maksik.GetDeliveriesCount(), 2);
}

TEST(CourierTest, WorkingFullCapacityTest) {
	Date MakiksBday(11, 11, 2001);
	Courier Maksik("Maksik", "Ivanov", MakiksBday, "AB3211221", "Courier", "car", 1);
	Maksik.Work();
	Maksik.Work();
	EXPECT_EQ(Maksik.GetDeliveriesCount(), 1);
}

TEST(CourierTest, DeliverPackageTest) {
	Date MaxBday(1, 1, 2001);
	Customer Max("Kate", "Rubleuskaya", MaxBday, "BY2114561", "Abobino 18");
	Date send(12, 12, 2022);
	Date MashaBday(11, 12, 2011);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	Date recieve(31, 12, 2022);
	Product prod("banana", 11.1, 2.1);
	Package pack(prod, Max, send, Masha, recieve);
	Date MakiksBday(11, 11, 2001);
	Courier Maksik("Maksik", "Ivanov", MakiksBday, "AB3211221", "Courier", "car", 15);
	Maksik.DeliverPackage(&pack);
	EXPECT_EQ(Maksik.GetDeliveriesCount(), 1);
	EXPECT_EQ(pack.GetPackageStatus()->GetpackageStatus(), "Delivered");
}

TEST(CourierTest, ShowInfoOutput) {
	Date PolinaBday(4, 1, 2017);
	Courier Polina("Polina", "Puchinskaya", PolinaBday, "AB3211221", "Courier", "car", 15);
	testing::internal::CaptureStdout();
	Polina.ShowInfo();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "\nFull name: Puchinskaya Polina\nBirthday: 4.1.2017\n\nPosition: Courier\nWorkID: Couri_24Vehile type: car\nDeliveries count: 0\nAverage capacity: 15\n";
	EXPECT_EQ(output, expected_output);
}

//int main(int argc, char** argv) {
//	::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TEST();
//}
