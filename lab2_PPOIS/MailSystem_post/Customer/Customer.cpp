#include "Customer.h"

int Customer::counterMailID = 0;

Customer::Customer(string name, string surname, Date bday, string passID, string address)
	: Human(name, surname, bday, passID) {
	this->address = address;
	counterMailID++;
	this->mailID = address.substr(0, 3) + surname.substr(0, 3) + name.substr(0, 3) + "_" + to_string(counterMailID);
}
void Customer::ShowInfo() {
	cout << "\nFull name: " << this->GetFullName() << "\nBirthday: ";
	this->birthday.ShowDate();
	cout << "PassportID: " << this->passportID
		<< "\nAddress: " << this->address
		<< "\nMailID: " << this->mailID << endl;
}

void Customer::ReceivePackage() { //
	cout << "Customer " << GetFullName() << " recieved package" << endl;
}

void Customer::RateConsultant(Consultant* workingConsultant, double rate) { //
	workingConsultant->ChangeRate(rate);
}
string Customer::GetName() {
	return name;
}
string Customer::GetSurname() {
	return surname;
}
string Customer::GetMailID() {
	return mailID;
}
