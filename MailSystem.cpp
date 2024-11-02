#include "MailSystem.h"

MailSystem::MailSystem(vector <PostOffice> offices, vector<LogisticsCenter> logistics, const int averageEmployeesCount, vector<Customer> customers)
	:offices(offices), logistics(logistics), averageEmployeesCount(averageEmployeesCount), customers(customers) {	}

Customer* MailSystem::FindCustomerByMailID(const string& mailID) { //
    for (auto& customer : customers) {
        if (customer.GetMailID() == mailID) {
            cout << "There is a customer with mailID " << mailID << ". It is " << customer.GetFullName() << endl;
            return &customer; 
        }
    }
    cout << "There is no customer with mailID " << mailID << endl;
    return nullptr;
}

void MailSystem::RegisterCustomer(Customer& customer) { //
	customers.push_back(customer);
	cout << "Customer " << customer.GetFullName() << " was registered.\n";
}