#include "CallCenter.h"

bool CallCenter::IsInStaff(CallCenterOperator* oper) {
	for (CallCenterOperator* worker : CCstaff) {
		if (worker->GetFullName() == oper->GetFullName()) {
			return true;
		}
	}
	return false;
}

CallCenter::CallCenter(vector<CallCenterOperator*> staff, string CCphone) :
	CCstaff(staff), CCphoneNumber(CCphone) {};

void CallCenter::TransferCallToOperator() {
	for (CallCenterOperator* CCoperator : CCstaff) {
		if (CCoperator->GetAvailability()==FREE) {
			cout << "The call is transfered to available operator " << CCoperator->GetFullName() << ". Please wait.\n ";
			CCoperator->Work();
			return;
		}
	}
	cout << "All operators are too busy. Please wait untill operator will be free.\n";
}

void CallCenter::ConfirmOrder(Order* confirmOrder, UserAccount* confirmUser, CallCenterOperator operatorWorker) {
	if (IsInStaff(&operatorWorker))
		operatorWorker.OrderConfirmation(confirmOrder, confirmUser);
	else cout << "Worker " << operatorWorker.GetFullName() << " doesn`t work there" << endl;
}