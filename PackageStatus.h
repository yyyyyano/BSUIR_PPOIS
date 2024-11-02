#ifndef PACKAGE_STATUS_H
#define PACKAGE_STATUS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PackageStatus {
	string statusDescription;
	vector<string> statusHistory;
public:
	PackageStatus(string initStatus);

	void ChangeStatus(const string& newStatus);

	bool IsDelivered();

	string GetpackageStatus();

	const vector<string>& GetStatusHistory() const;
};



#endif