#include "Courier.h"

Courier::Courier(string name, string surname, Date bday, string passID, string position, string vehicle, double capacity)
	:Employee(name, surname, bday, passID, "Courier") {
	this->vehicle = vehicle;
	this->averageCapacity = capacity;
	this->deliveriesCount = 0;
}
void Courier::Work() { //
	if (deliveriesCount < averageCapacity) {
		cout << "\nCourier " << surname << ' ' << name << " delivers your package on " << vehicle << endl;
		deliveriesCount++;
	}
	else
		cout << "\nCourier " << surname << ' ' << name << " is too busy today\n";
}
void Courier::ShowInfo()  {
	Employee::ShowInfo();
	cout << "Vehile type: " << this->vehicle
		<< "\nDeliveries count: " << this->deliveriesCount
		<< "\nAverage capacity: " << averageCapacity << endl;
}
void Courier::DeliverPackage(Package* package) { //
	cout << "\nCourier " << surname << ' ' << name << " has delivered your package #" << package->GetTrackingNumber() << endl;
	package->GetPackageStatus()->ChangeStatus("Delivered");
	deliveriesCount++;
}
double Courier::GetCapacity() {
	return averageCapacity;
}

int Courier::GetDeliveriesCount() {
	return deliveriesCount;
}
