#include "Employee.h"

Employee::Employee(string name, string surname, Date bday, string phoneNum, string position) :
	Human(name, surname, bday, phoneNum), position(position), isFree(FREE) {
	employeeIDcounter++;
	employeeID = position.substr(0, 3) + "_" + to_string(employeeIDcounter);
};

void Employee::ShowInfo()  {
	Human::ShowInfo();
	cout << "Position: " << position << "\nEmployee ID: " << employeeID << endl;
}

void Employee::IsAvailable() {
	if (isFree==FREE) {
		cout << "Employee " << GetFullName() << " is free! How can we help you?" << endl;
		isFree = ONLINE;
	}
	else cout << "Sorry. Employee " << GetFullName() << " is too busy now!" << endl;
}

workerStatus Employee::GetAvailability() {
	return isFree;
}

int Employee::employeeIDcounter = 0;
