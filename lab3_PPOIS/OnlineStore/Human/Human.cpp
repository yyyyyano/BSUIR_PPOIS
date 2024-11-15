#include "Human.h"

bool Human::IsCorrectPhoneNumber(string phoneNumber) {
	if (phoneNumber.empty()) {
		return false;
	}
	int correctSize = 12;
	int currentSize = 0;
	if (phoneNumber[0] == '+') {
		for (int i = 1; i < phoneNumber.length(); ++i) {
			if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9')) {
				return false;
			}
			currentSize++;
		}
	}
	return currentSize == correctSize;
}

Human::Human(string name, string surname, Date bday, string phoneNum)
	:name(name), surname(surname), birthdate(bday) {
	if (IsCorrectPhoneNumber(phoneNum))
		phoneNumber = phoneNum;
	else
		phoneNumber = "incorrect phone number ";
};

void Human:: ShowInfo() {
	cout << "Full name: " << GetFullName() << "\nBirthdate: ";
	birthdate.ShowDate();
	cout << "Phone number: " << phoneNumber << endl;
};

void Human::ChangePhoneNumber(string newPhoneNum) {
	if (IsCorrectPhoneNumber(newPhoneNum)) {
		phoneNumber = newPhoneNum;
		cout << "\nPhone number has been changed successfully!";
		ShowInfo();
	}
	else cout << "Incorrect phone number!";
}

string Human::GetFullName() const {
	return surname + " " + name;
}

string Human:: GetPhoneNumber() {
	return phoneNumber;
}
