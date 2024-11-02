#include "Employee.h"

int Employee::counterWorkID = 0;

Employee::Employee(string name, string surname, Date bday, string passID, string position)
	:Human(name, surname, bday, passID) {
	this->position = position;
	counterWorkID++;
	this->workID = position.substr(0, 5) + "_" + to_string(counterWorkID);

}
void Employee::ShowInfo() {
	cout << "\nFull name: " << this->GetFullName() << "\nBirthday: ";
	this->birthday.ShowDate();
	cout << "\nPosition: " << this->position << "\nWorkID: " << this->workID;
}

bool Employee::IsJunior(Employee* otherEmployee) {
	int currentID = stoi(workID.substr(workID.find("_") + 1));
	int otherID = stoi(otherEmployee->workID.substr(otherEmployee->workID.find("_") + 1));

	if (currentID > otherID) {
		cout << this->GetFullName() << " is a junior compared to " << otherEmployee->GetFullName() << ".\n";
		return true;
	}
	else {
		cout << this->GetFullName() << " is not a junior compared to " << otherEmployee->GetFullName() << ".\n";
		return false;
	}
}
