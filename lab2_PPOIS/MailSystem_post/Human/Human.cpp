#include "Human.h"

Human::Human(string name, string surname, Date birthday, string passportID)
	:name(name), surname(surname), birthday(birthday), passportID(passportID) {};


bool Human::VerifyIdentity(const string& passID) const {
	return passportID == passID;
}

string Human::GetFullName() {
	return surname + " " + name;
}
