#include "PostOffice.h"

PostOffice::PostOffice(int officeIDX, const string& address, vector<Employee*> employees, vector<string> services)
	:officeIndex(officeIDX), address(address), employees(employees), activeServices(services), averageCustomersCount(0) {
}
void PostOffice::ServeCustomer(Employee* worker, Customer waitingCustomer) { //
	cout << "Employee " << worker->GetFullName() << " is serving a customer " << waitingCustomer.GetFullName() << endl;
	averageCustomersCount++;
}
void PostOffice::AddEmployee(Employee* newEmployee) { //
	employees.push_back(newEmployee);
	cout << "Added new employee " << newEmployee->GetFullName() << " to a post office #" << officeIndex << endl;
}

int PostOffice::GetAverageCustomers() {
	return averageCustomersCount;
}

const vector<Employee*>& PostOffice::GetEmployees() const {
	return employees;
}