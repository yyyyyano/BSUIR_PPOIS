#ifndef PACKAGE_H
#define PACKAGE_H
#include"Customer.h"
#include "Product.h"
#include "PackageStatus.h"
#include "Date.h"
#include "UserAccount.h"

class Package {
	Product sending;
	PackageStatus* packageStatus;
	string trackingNumber;
	Customer senderInfo;
	Date sendingData;
	Customer recieverInfo;
	Date recievingData;

	string CreateTrackingNumber();

public:
	Package(Product sending, Customer sender, Date sendingData, Customer reciever, Date recievingData);

	void ChangeReciever(Customer newReciever, UserAccount sender);

	string GetTrackingNumber();

	PackageStatus* GetPackageStatus();

	Product GetPackageSending();

	Customer GetReciever();

	void ShowInfo();

	void SetPackageStatus(PackageStatus* newStatus);

	~Package();
};

#endif
