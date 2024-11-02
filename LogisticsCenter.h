#ifndef LOGISTICS_CENTER_H
#define LOGISTICS_CENTER_H
#include "Package.h"
#include "Courier.h"
#include "Employee.h"
#include <vector>

class LogisticsCenter {
	int averageCapacity;
	int currentCapacity;
	vector<Package> packages;
	string address;
	vector <Employee*> logisticsStaff;

public:
	LogisticsCenter(vector<Package> packages, string address, vector <Employee*> staff, int currentCapacity);

	void AcceptPackage();

	void SendPackage(Courier* workingCourier);
};

#endif
