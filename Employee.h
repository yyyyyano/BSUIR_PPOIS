#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Human.h"

class Employee : public Human {
protected:
	string position;
	string workID;
	static int counterWorkID;
public:

	Employee(string name, string surname, Date bday, string passID, string position);

	void ShowInfo() override;

	void virtual Work() = 0;

	bool IsJunior(Employee* otherEmployee);

	virtual ~Employee() = default;
};


#endif
