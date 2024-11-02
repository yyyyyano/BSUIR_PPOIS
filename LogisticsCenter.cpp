#include "LogisticsCenter.h"

LogisticsCenter::LogisticsCenter(vector<Package> packages, string address, vector <Employee*> staff, int currentCapacity)
	:packages(packages), address(address), logisticsStaff(staff), currentCapacity(currentCapacity) {
	int numOfEmployees = logisticsStaff.size();
	averageCapacity = numOfEmployees * 50;
}

void LogisticsCenter::AcceptPackage() { //
	if (currentCapacity <= averageCapacity) {
		cout << "The package was accepted by Logistic center\n";
	}
	else cout << "There is no space for your package\n";
}

void LogisticsCenter::SendPackage(Courier* workingCourier) { //
	if (currentCapacity <= workingCourier->GetCapacity()) {
		cout << "Sending your package to courier " << workingCourier->GetFullName();
	}
	else cout << "Courier " << workingCourier->GetFullName() << " is too busy to take package";
}