#include "Cashier.h"

int Cashier::cashAppID = 0;

Cashier::Cashier(string name, string surname, Date bday, string passID, string position, string specialization, string vehicle, double capacity, int category)
	: Employee(name, surname, bday, passID, "Cashier"),
	Consultant(name, surname, bday, passID, "Cashier", specialization),
	Courier(name, surname, bday, passID, "Cashier", vehicle, capacity),
	category(category) {
	this->cashAppID = cashAppID;
	cashAppID++;
}
void Cashier::Work() {
	Consultant::Work();
	Courier::Work();
	cout << "\nCashier " << surname << ' ' << name << " (category: " << category << ") processes your package transactions on cashApp #" << cashAppID << endl;
}

void Cashier::ShowInfo() {
	Consultant::ShowInfo();
	cout << "Category: " << category
		<< "\nCashAppID: " << cashAppID << endl;
}
