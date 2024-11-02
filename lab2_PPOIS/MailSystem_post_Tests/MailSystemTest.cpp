#include "pch.h"
#include "E:\PPOIS\labs\MailSystem_post\MailSystem.h"
#include "E:\PPOIS\labs\MailSystem_post\MailSystem.cpp"

TEST(MailSystemTest, FindCustomerByMailID_ExistingCustomer_ReturnsPointer) {
	Date MaxBday(1, 1, 2001);
	Customer Max("Max", "Ivanov", MaxBday, "AB3211221", "Baranove 12a");
	Date MashaBday(11, 12, 2011);
	Customer Masha("Masha", "Pushkina", MashaBday, "AC3252221", "Bubkino 2");
	Masha.ShowInfo();
	vector<PostOffice> pvec; 
	vector<LogisticsCenter> logs;
	vector<Customer> cust = { Max, Masha };
	MailSystem sys(pvec, logs, 1000, cust);
	Customer* finder = sys.FindCustomerByMailID("BubPusMas_19"); 
	ASSERT_NE(finder, nullptr); 
	EXPECT_EQ(finder->GetFullName(), "Pushkina Masha"); 
}


TEST(MailSystemTest, FindCustomerByMailID_ExistingCustomer_ReturnsNullptr) {
	Date PetrBday(17, 11, 2005);
	Customer Petr("Petr", "Smirnov", PetrBday, "AB1111221", "Surganova 1");
	Date KatyaBday(1, 02, 2001);
	Customer Katya("Masha", "Bubkina", KatyaBday, "AC3252141", "Maryno 12b");
	vector < PostOffice> pvec;
	vector <LogisticsCenter> logs;
	vector<Customer> cust = { Katya,Petr };
	MailSystem sys(pvec, logs, 1000, cust);
	Customer* finder = sys.FindCustomerByMailID("MarPusMax_1");
	ASSERT_EQ(finder, nullptr);
}

TEST(MailSystemTest, RegisterCustomer_AddsCustomerSuccessfully) {
	Date KateBday(25, 11, 2005);
	Customer newCustomer("Kate", "Rubleuskaya", KateBday, "BY2114561", "Abobino 18");
	newCustomer.ShowInfo();
	vector < PostOffice> pvec;
	vector <LogisticsCenter> logs;
	vector<Customer> cust;
	MailSystem sys(pvec, logs, 1000, cust);
	sys.RegisterCustomer(newCustomer);
	Customer* findNewCustomer = sys.FindCustomerByMailID("AboRubKat_22");
	EXPECT_NE(findNewCustomer, nullptr);
	EXPECT_EQ(findNewCustomer->GetFullName(), "Rubleuskaya Kate");
}

