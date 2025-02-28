#ifndef CALL_CENTER_H
#define CALL_CENTER_H

#include "CallCenterOperator.h"
#include "Order.h"
#include "UserAccount.h"
#include <vector>

class CallCenter {
	vector<CallCenterOperator*> CCstaff;
	string CCphoneNumber;

	bool IsInStaff(CallCenterOperator* oper);

public:
	CallCenter(vector<CallCenterOperator*> staff, string CCphone);

	void TransferCallToOperator();

	void ConfirmOrder(Order* confirmOrder, UserAccount* confirmUser, CallCenterOperator operatorWorker);
};


#endif
