#ifndef CASHIER_H
#define CASHIER_H
#include "Courier.h"
#include"Consultant.h"

class Cashier final : public Courier, public Consultant {
	int category;
	static int cashAppID;
public:
	Cashier(string name, string surname, Date bday, string passID, string position, string specialization, string vehicle, double capacity, int category);

	void Work() override;

	void ShowInfo() override;

};

#endif
