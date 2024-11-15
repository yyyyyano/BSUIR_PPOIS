#include "CallCenterOperator.h"

CallCenterOperator::CallCenterOperator(string name, string surname, Date bday, string phoneNum, string position, int callPerDay, string specialization, int currCallsCount) :
	Employee(name, surname, bday, phoneNum, position), Human(name, surname, bday, phoneNum),
	callsPerDay(callPerDay), CCidx(0), specialization(specialization), currentCallsCount(currCallsCount) {};

void CallCenterOperator::Work()  {
	try {
		if (currentCallsCount >= callsPerDay) {
			isFree = UNAVAILABLE;
			throw runtime_error("This call center operator has completed the work plan for today!");
		}
		isFree = ONLINE;
		cout << "Call center operator " << GetFullName() << " is on phone helping users with specialization <" << specialization << ">" << endl;
		currentCallsCount++;

	}
	catch (const runtime_error& exception)
	{
		cerr << "Error: " << exception.what() << '\n';
	}
}

void CallCenterOperator::ShowInfo()  {
	Employee::ShowInfo();
	cout << "Specialization: " << specialization << "\nCall center index: " << CCidx << "\nAverage calls per day: " << callsPerDay << endl;
}

void CallCenterOperator::OrderConfirmation(Order* confirmOrder, UserAccount* confirmUser) {
	try {
		if (!(GetAvailability() == FREE) ){
			throw runtime_error("Call center operator " + GetFullName() + " isn`t available now\n");
		}
		cout << endl;
		if (confirmUser->GetBasket()->IsInBasket(confirmOrder)) {
			cout << "Order #" << confirmOrder->GetOrderIdx() << " was confirmed by user #" << confirmUser->GetLogin() << " on line " << CCidx << endl;
			confirmOrder->SetStatus("Confirmed");
		}
		else {
			cout << "User #" << confirmUser->GetLogin() << " doesn`t have Order #" << confirmOrder->GetOrderIdx() << " in his basket\n";
		}
		
	}
	catch (const runtime_error& exception) {
		cerr << "Error: " << exception.what() << endl;
	}
}
