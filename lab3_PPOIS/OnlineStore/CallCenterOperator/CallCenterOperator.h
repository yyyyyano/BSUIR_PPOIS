#ifndef CALL_CENTER_OPERATOR_H
#define CALL_CENTER_OPERATOR_H

#include "Employee.h"
#include "Order.h"
#include "UserAccount.h"

class CallCenterOperator final: public Employee {
	int CCidx; 
	int callsPerDay; 
	int currentCallsCount;
	string specialization; 
public:
	CallCenterOperator(string name, string surname, Date bday, string phoneNum, string position, int callPerDay, string specialization, int currCallsCount);

	void Work() override;

	void ShowInfo() override;

	void OrderConfirmation(Order* confirmOrder, UserAccount* confirmUser);
};

#endif
