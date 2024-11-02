#include "Package.h"

string Package::CreateTrackingNumber() {
	trackingNumber = senderInfo.GetSurname().substr(0, 2) + senderInfo.GetName().substr(0, 2) + recieverInfo.GetSurname().substr(0, 2) + recieverInfo.GetName().substr(0, 2) + to_string(sendingData.GetDay());
	return trackingNumber;
}

Package::Package(Product sending, Customer sender, Date sendingData, Customer reciever, Date recievingData)
	:sending(sending), senderInfo(sender), sendingData(sendingData), recieverInfo(reciever), recievingData(recievingData)
{
	this->trackingNumber = this->CreateTrackingNumber();
	packageStatus = new PackageStatus("Package Created");
};

void Package::ChangeReciever(Customer newReciever, UserAccount sender) { //
	recieverInfo = newReciever;
	packageStatus->ChangeStatus("The reciever has been changed");
	cout << "Notifying user " << sender.GetLogin() << " that your package " << trackingNumber << " has changed delivery status\n";
	cout << "New status: " << packageStatus->GetpackageStatus() << endl;
}


string Package::GetTrackingNumber() {
	return trackingNumber;
}

PackageStatus* Package::GetPackageStatus() {
	return packageStatus;
}

Product Package::GetPackageSending() {
	return sending;
}

Customer Package::GetReciever() {
	return recieverInfo;
}

void Package::ShowInfo() { //
	sending.ShowInfo();
	cout << "\nStatus of delivery: " << packageStatus->GetpackageStatus()
		<< "\nTraccking number: " << trackingNumber
		<< "\n\nSender:";
	senderInfo.ShowInfo();
	cout << "Sending data: ";
	sendingData.ShowDate();
	cout << "\nReciever: ";
	recieverInfo.ShowInfo();
	cout << "Reciving data: ";
	recievingData.ShowDate();
	cout << endl;
}

void Package::SetPackageStatus(PackageStatus* newStatus) {
	delete packageStatus; 
	packageStatus = newStatus; 
}

Package:: ~Package() {
	delete packageStatus;
}