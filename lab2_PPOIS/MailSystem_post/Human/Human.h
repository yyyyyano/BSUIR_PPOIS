#ifndef HUMAN_H
#define HUMAN_H

#include "Date.h"

class Human {
protected:
	string name;
	string surname;
	Date birthday;
	string passportID;
public:
	Human(string name, string surname, Date birthday, string passportID);

	void virtual ShowInfo() = 0;

	bool VerifyIdentity(const string& passID) const;

	string GetFullName();

	virtual ~Human() = default;
};

#endif
