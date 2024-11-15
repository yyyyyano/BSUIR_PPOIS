#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\PostOffice.h"
#include "E:\PPOIS\labs\MailSystem_post\PostOffice.cpp"

TEST(PostOfficeTest, ServeCustomerTest) {
	Date MaksBday(13, 1, 2001);
	Consultant Maks("Maksimum", "Ivanov", MaksBday, "AB3211221", "0", "delivery");
	vector<Employee*> staff = { &Maks };
	vector<string> services;
	PostOffice post(225410, "Coidanovo 11", staff, services);
	Date MashaBday(1, 1, 2001);
	Customer Masha("Masha", "Pushkina", MashaBday, "AB3252221", "Baranove 14a");
	post.ServeCustomer(&Maks, Masha);
	EXPECT_EQ(post.GetAverageCustomers(), 1);
}

TEST(PostOfficeTest, AddEmployeeTest) {
	vector<Employee*> staff;
	vector<string> services;
	PostOffice post(225410, "Coidanovo 11", staff, services);
	Date MaksBday(13, 1, 2001);
	Consultant Maks("Maksimum", "Ivanov", MaksBday, "AB3211221", "0", "delivery");
	post.AddEmployee(&Maks);
	ASSERT_FALSE(post.GetEmployees().empty());
	EXPECT_EQ(post.GetEmployees().back()->GetFullName(), "Ivanov Maksimum") ;
	EXPECT_EQ(post.GetEmployees().size(), 1);
}
