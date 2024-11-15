#include "PickUpPointWorker.h"

PickUpPointWorker::PickUpPointWorker(string name, string surname, Date bday, string phoneNum, string position, int averageOrderesProccessed, int currentOrderesProccessed, PickUpPoint* PUP) :
	Employee(name, surname, bday, phoneNum, position), Human(name, surname, bday, phoneNum),
	averageOrderesProccessed(averageOrderesProccessed), currentOrderesProccessed(currentOrderesProccessed), PUPwork(PUP) {};

void PickUpPointWorker::IssueParcel(string issuedOrderArticle, UserAccount* servisedUser) {
	if (currentOrderesProccessed < averageOrderesProccessed) {
		Work();
		cout << endl;
		PUPwork->IssueParcel(issuedOrderArticle, servisedUser);
		currentOrderesProccessed++;
	}
	else cout << "PickUpPoint worker " << GetFullName() << " done his work for today\n";
}

void PickUpPointWorker::ReturnParcel(string returningOrderArticle, UserAccount* servicedUser) {
	if (currentOrderesProccessed < averageOrderesProccessed) {
		Work();
		cout << endl;
		PUPwork->ReturnParcel(returningOrderArticle, servicedUser);
		currentOrderesProccessed++;
	}
	else cout << "PickUpPoint worker " << GetFullName() << " done his work for today\n";
}


void PickUpPointWorker::Work() {
	cout << "PickUpPoint worker " << GetFullName() << " works on PUP#" << PUPwork->GetPUPid() << endl;
}