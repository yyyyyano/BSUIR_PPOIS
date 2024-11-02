#include "Consultant.h"

Consultant::Consultant(string name, string surname, Date bday, string passID, string position, string specialization)
	:Employee(name, surname, bday, passID, "consultant") {
	this->specialization = specialization;
	this->satisfactionRate = 0.0;
	this->clientsServed = 0;
}
void Consultant::Work() { //
	cout << "\nConsultant " << surname << " " << name << " consults customer for " << specialization << " issue\n";
	clientsServed++;
}
void Consultant::ShowInfo()  {
	Employee::ShowInfo();
	cout << "\nSpecialization: " << specialization
		<< "\nSatisfaction rate: " << satisfactionRate
		<< "\nClients served: " << clientsServed << endl;
}
void Consultant::ChangeRate(double rate) { //
	if (satisfactionRate == 0.0 && clientsServed == 0)
		satisfactionRate = rate;
	else
		satisfactionRate = (satisfactionRate + rate) / 2;
	clientsServed++;
}

double Consultant::GetRate() {
	return satisfactionRate;
}

int Consultant::GetClientsServed() {
	return clientsServed;
}