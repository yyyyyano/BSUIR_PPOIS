#ifndef COURIER_H
#define COURIER_H
#include "Employee.h"
#include "Package.h"

class Courier : public virtual Employee {
	string vehicle;
	int deliveriesCount;
	double averageCapacity;

public:
	Courier(string name, string surname, Date bday, string passID, string position, string vehicle, double capacity);

	void Work() override;

	void ShowInfo() override;

	void DeliverPackage(Package* package);

	double GetCapacity();

	int GetDeliveriesCount();

	virtual ~Courier() = default;
};


#endif
