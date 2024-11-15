#ifndef HUMAN_H
#define HUMAN_H

#include "Date.h"
#include <string>

class Human {

	string name; 
	string surname; 
	Date birthdate; 
	string phoneNumber; 

	bool IsCorrectPhoneNumber(string phoneNumber);

public:
	Human(string name, string surname, Date bday, string phoneNum);

	void virtual ShowInfo();

	void ChangePhoneNumber(string newPhoneNum);

	string GetFullName() const;

	string GetPhoneNumber();
};

#endif