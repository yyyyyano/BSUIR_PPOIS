#ifndef CONSULTANT_H
#define CONSULTANT_H
#include "Employee.h"

class Consultant : public virtual Employee {
protected:
	string specialization;
	double satisfactionRate;
	int clientsServed;
public:
	Consultant(string name, string surname, Date bday, string passID, string position, string specialization);

	void Work() override;

	void ShowInfo() override;

	void ChangeRate(double rate);

	double GetRate();

	int GetClientsServed();

	virtual ~Consultant() = default;
};


#endif
