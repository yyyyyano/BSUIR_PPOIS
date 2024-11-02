#include "PackageStatus.h"

PackageStatus::PackageStatus(string initStatus)
	: statusDescription(initStatus) {
	statusHistory.push_back(initStatus);
}

void PackageStatus::ChangeStatus(const string& newStatus) { //
	statusHistory.push_back(newStatus);
	this->statusDescription = newStatus;
}

bool PackageStatus::IsDelivered() { //
	bool delivered = (statusDescription == "Delivered") ||
		(find(statusHistory.begin(), statusHistory.end(), "Delivered") != statusHistory.end());
	return delivered;
}

string PackageStatus::GetpackageStatus() {
	return statusDescription;
}

const vector<string>& PackageStatus::GetStatusHistory() const {
	return statusHistory;
}

