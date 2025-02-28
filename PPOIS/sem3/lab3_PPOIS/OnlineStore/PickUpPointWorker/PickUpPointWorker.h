#ifndef PICK_UP_POINT_WORKER_H
#define PICK_UP_POINT_WORKER_H

#include "Employee.h"
#include "PickUpPoint.h"

class PickUpPointWorker : public Employee {
	PickUpPoint* PUPwork; 
	int averageOrderesProccessed; 
	int currentOrderesProccessed;
public:
	PickUpPointWorker(string name, string surname, Date bday, string phoneNum, string position, int averageOrderesProccessed, int currentOrderesProccessed, PickUpPoint* PUP);

	void IssueParcel(string issuedOrderArticle, UserAccount* servisedUser);

	void ReturnParcel(string returningOrderArticle, UserAccount* servicedUser);

	void Work() override;
};


#endif
