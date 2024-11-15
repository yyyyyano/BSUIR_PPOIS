#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\Customer.h"
#include "E:\PPOIS\labs\MailSystem_post\Customer.cpp"

TEST(CustomerTest, RateConsultantTest) {
	Date MashaBday(1, 1, 2001);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	Date MaksBday(13, 1, 2001);
	Consultant Maks("Maksimum", "Ivanov", MaksBday, "AB3211221", "0", "delivery");
	Masha.RateConsultant(&Maks, 4.6);
	EXPECT_EQ(Maks.GetRate(), 4.6);
}

TEST(CustomerTest, RateConsultantTwiceTest) {
	Date MashaBday(1, 1, 2001);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	Date MaksBday(13, 1, 2001);
	Consultant Maks("Maksimum", "Ivanov", MaksBday, "AB3211221", "0", "delivery");
	Masha.RateConsultant(&Maks, 4.6);
	Masha.RateConsultant(&Maks, 5.0);
	EXPECT_EQ(Maks.GetRate(), 4.8);
}

TEST(CustomerTest, GenerateMailIDTest) {
	Date bday(1, 1, 2000);
	Customer Ivan("Ivan", "Bulkin", bday, "AV123321", "Barkovaya 123-4");
	EXPECT_EQ(Ivan.GetMailID(), "BarBulIva_3");
}

TEST(CustomerTest, ReceivePackageTest) {
	Date bday(11, 1, 2011);
	Customer Ivanka("Ivanka", "Bulkina", bday, "AV123321", "Parkovaya 123-4");
	Ivanka.ReceivePackage();
	testing::internal::CaptureStdout(); 
	Ivanka.ReceivePackage();
	string output = testing::internal::GetCapturedStdout(); 
	string expected = "Customer Bulkina Ivanka recieved package\n";
	EXPECT_EQ(output, expected);
}

//TEST(CustomerTest, ShowDataOutput) {
//	Date bday(11, 1, 2011);
//	Customer Ivana("Ivana", "Bulkina", bday, "AV123321", "Parkovaya 123-4");
//	testing::internal::CaptureStdout();
//	Ivana.ShowInfo();
//	string output = testing::internal::GetCapturedStdout();
//	string expected_output = "\nFull name: Bulkina Ivana\nBirthday: 11.1.2011\nPassportID: AV123321\nAddress: Parkovaya 123-4\nMailID: ";
//	EXPECT_EQ(output, expected_output);
//}
TEST(HumanCustomerTest, VerifyIdentity_ExpectTrue) {
	Date bday(9, 11, 2006);
	Customer Yanix("Yana", "Bankevich", bday, "Ab1112233", "Frolenkova 11");

	// Проверка значений
	std::cout << "Passport ID: " << Yanix.VerifyIdentity("Ab1112233") << std::endl;
	std::cout << "Name: " << Yanix.GetFullName() << std::endl;

	EXPECT_TRUE(Yanix.VerifyIdentity("Ab1112233"));
}
