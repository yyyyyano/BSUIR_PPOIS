#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Human.h"
#include "Consultant.h"
#include <vector>

class Customer final : public Human {
	string mailID;
	string address;
	static int counterMailID;
public:
	Customer(string name, string surname, Date bday, string passID, string address);

	void ShowInfo() override;

	void ReceivePackage();

	void RateConsultant(Consultant* workingConsultant, double rate);

	string GetName();

	string GetSurname();

	string GetMailID();
};


#endif
