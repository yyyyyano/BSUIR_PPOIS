#ifndef MAIL_SYSTEM_H
#define MAIL_SYSTEM_H
#include "PostOffice.h"
#include "LogisticsCenter.h"
#include "Customer.h"

class MailSystem {
	vector <PostOffice> offices;
	vector<LogisticsCenter> logistics;
	const int averageEmployeesCount;
	vector<Customer> customers;
public:
	MailSystem(vector <PostOffice> offices, vector<LogisticsCenter> logistics, const int averageEmployeesCount, vector<Customer> customers);

	Customer* FindCustomerByMailID(const string& mailID);

	void RegisterCustomer(Customer& customer);
};



#endif
