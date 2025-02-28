#ifndef POST_OFFICE_H
#define POST_OFFICE_H

#include "Customer.h"
#include "Employee.h"
#include <vector>

class PostOffice {
	int officeIndex;
	const string address;
	int averageCustomersCount;
	vector<Employee*> employees;
	vector<string> activeServices;
public:
	PostOffice(int officeIDX, const string& address, vector<Employee*> employees, vector<string> services);

	void ServeCustomer(Employee* worker, Customer waitingCustomer);

	void AddEmployee(Employee* newEmployee);

	int GetAverageCustomers();

	const vector<Employee*>& GetEmployees() const;
};

#endif
